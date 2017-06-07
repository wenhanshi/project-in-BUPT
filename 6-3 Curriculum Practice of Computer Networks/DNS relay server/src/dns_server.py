import socket
import struct
import queue
import sys
import getopt
import random
import threading


dns_data = {}  # file that contains DNS info
dns_server = '10.3.9.5'  # remote DNS server
port = 53  # DNS port
query_buf = queue.Queue()  # DNS query queue
ans_buf = queue.Queue()  # DNS response queue
file_name = 'dnsrelay.txt'  # default file
id_dict = {}  # id : ( src_id, src_addr )


# send DNS query to remote DNS server if ip not found in dns_data
# 127.0.0.1 : 5000 -> 10.x.x.x : 53
def send_dns_frame(server, frame, addr):
    global dns_server, port, id_dict
    id = struct.unpack('!H', frame[0:2])

    # if the id exists
    if id[0] in id_dict:
        # make new IP
        # e.g.
        # 23333 : (2, 10.128.102.40:50050)
        # 44678 : (4, 10.128.105.21:52199)
        # ...
        new_id = (2 * id[0] + random.randint(0, 65535)) % 65536
        frame = struct.pack('!H', new_id) + frame[2::]
        id_dict[new_id] = (id[0], addr)

    # remain the original IP
    else:
        id_dict[id[0]] = (id[0], addr)
    print('[SEND QUERY]', get_qname(frame))
    server.sendto(frame, (dns_server, port))


# deal with query_buf
# server receive a response from remote DNS server -> put the response into ans_buf
# caution: we can NOT reply the response received
# $nslookup need answer from port 53 ! so just put them in the ans_buf
def handle_dns_ans():
    global id_dict, query_buf, ans_buf
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.bind(('', 50000))
        s.settimeout(1)
        while True:
            try:
                # query frame in buffers waiting for handle
                while not query_buf.empty():
                    frame, addr = query_buf.get()
                    send_dns_frame(s, frame, addr)

                # receive answer and resend (put them in ans_buf)
                data, addr = s.recvfrom(1024)
                print('[RESPONSE]', get_ip(data))

                # mapping id : id -> ( src_id, src_addr )
                id = struct.unpack('!H', data[0:2])
                src_id, src_addr = id_dict[id[0]]
                data = struct.pack('!H', src_id) + data[2::]

                # put response into ans_buf
                ans_buf.put((data, src_addr))

                # update id_dict
                id_dict.pop(id[0])

            except:
                # no answer or timeout
                # do next while
                print('[TIMEOUT] No response from remote DNS server timeout.')


# response -> a.b.c.d
def get_ip(dns_frame):
    ip1, ip2, ip3, ip4 = struct.unpack('!BBBB', dns_frame[-4::])
    return str(ip1) + '.' + str(ip2) + '.' + str(ip3) + '.' + str(ip4)


# map b'3www5baidu3com' -> 'www.baidu.com'
def get_qname(dns_frame):
    segs = []
    q_name_bytes = dns_frame[12:-2]  # e.g. b'3www5baidu3com'
    i = 0
    count = q_name_bytes[0]

    while count != 0:
        segs.append(q_name_bytes[i + 1:i + count + 1].decode('ascii'))
        i += count + 1
        count = q_name_bytes[i]

    # get 'www.baidu.com'
    return '.'.join(segs)


# look up ip with domain name
# www.baidu.com -> a.b.c.d
def look_up(q_name):
    global dns_data
    if q_name not in dns_data:
        return ''
    else:
        return dns_data[q_name]


# creating DNS answer frame if ip is found in dns_data
def create_ans_frame(dns_frame, ans_ip, filtered):
    '''

    ------
    Header : IP, flags, question_count, answer RRs, authority RRs, additional RRs
    ------
    Queries : name, type, class
    ------
    Answers : name, type, class, ttl, data_length, address
    ------

    Flags : 
    * answer : 0x8180 (1000 0001 1000 0000) 
    [is response, recursion desired and available]
    * query : 0x0100 (0000 0001 0000 0000)
    [standard query, recursion desired]

    '''

    # Header
    id = dns_frame[0:2]  # copy from query

    q_count = b'\x00\x01'  # same as query
    if not filtered:
        flags = b'\x81\x80'  # diff from query & response [2:4], the same [5::]
        ans_RRs = b'\x00\x01'  # default : only 1 answer, un-auth
    else:
        flags = b'\x81\x83'  # rcode = 3, domain does not exist
        ans_RRs = b'\x00\x00'  # no RRs
    auth_RRs = b'\x00\x00'  # default : no auth RR
    add_RRs = b'\x00\x00'  # default : no add RR
    header = id + flags + q_count + ans_RRs + auth_RRs + add_RRs

    # Queries
    queries = dns_frame[12::]  # the same as DNS query

    # Answers
    name = b'\xc0\x0c'  # name pointer
    type = b'\x00\x01'  # A
    a_class = b'\x00\x01'  # IN
    ttl = struct.pack('!L', 46)  # default
    data_length = struct.pack('!H', 4)  # *.*.*.*
    ip_num = ans_ip.split('.')  # *.*.*.* -> hex(*), hex(*), ...
    address = struct.pack('!BBBB', int(ip_num[0]), int(ip_num[1]), int(ip_num[2]), int(ip_num[3]))
    answers = name + type + a_class + ttl + data_length + address

    return header + queries + answers


# create local DNS server with UDP
# binding 127.0.0.1 : 53
# listening DNS queries from clients, or DNS answers from remote DNS server
# send DNS answers to clients if name is found in table
# 10.x.x.x : xxxxx <- 127.0.0.1 : 53 (server) or
# 127.0.0.1 : xxxxx <- 127.0.0.1 : 53 (local)
def create_dns_server():
    global dns_server, port, ans_buf, query_buf
    print('Creating local DNS server...(UDP)')
    print('Remote DNS server: [%s]' % dns_server)
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        print('Binding socket [%s:%s]...' % ('127.0.0.1', port))
        s.settimeout(1)
        s.bind(('', port))  # can not be 127.0.0.1 explicitly
        while True:
            try:
                # deal with ans_buf
                while not ans_buf.empty():
                    ans, src_addr = ans_buf.get()
                    s.sendto(ans, src_addr)

                data, addr = s.recvfrom(1024)
                flags = data[2:4]
                type = data[-4:-2]

                # only standard query with IN and A
                if flags == b'\x01\x00' and type == b'\x00\x01':
                    print('[DNS QUERY FROM]', addr)
                    q_name = get_qname(data)
                    print('[Q_NAME]', q_name)
                    ans_ip = look_up(q_name)

                    if ans_ip == '0.0.0.0':
                        ans = create_ans_frame(data, ans_ip, filtered=True)
                        # send to client immediately, no need to buffer
                        s.sendto(ans, addr)
                        print('[NOTE] Domain does not exist.')

                    # normal IP, just response it directly
                    elif len(ans_ip) > 0:
                        print('Domain [%s] \'s IP has been found, is [%s]' % (q_name, ans_ip))
                        ans = create_ans_frame(data, ans_ip, filtered=False)
                        # send to client immediately, no need to buffer
                        s.sendto(ans, addr)
                        print('[CREATED RESPONSE]', ans)

                    # put queries into query_buf, waiting for sending
                    else:
                        print('IP not found. Sending query to [%s]' % dns_server)
                        query_buf.put((data, addr))

            except:
                # connection can always be denied or timeout
                # just ignore the exception and do next while
                print('[TIMEOUT] No query from client timeout.')


# reading DNS data file
def init_dns_file():
    global file_name, dns_data

    with open(file_name, 'r') as f:
        for line in f.readlines():
            line = line.replace('\n', '')
            if len(line) > 0:
                ip = line.split(' ')[0]
                name = line.split(' ')[1]
                dns_data[name] = ip
    print('Loading data files success.')
    print('Items: ', len(dns_data))


# get paras from console
# $ python dns_server.py -d 10.3.9.5 -f dnsrelay.txt
# default : file_name='dnsrelay.txt', dns_server = '10.3.9.5'
def get_opt():
    global file_name, dns_server
    opts, args = getopt.getopt(sys.argv[1::], 'd:f:')
    for op, value in opts:
        if op == '-d':
            dns_server = value
        elif op == '-f':
            file_name = value
        else:
            print('Error : unknown paras, use default settings.')


if __name__ == '__main__':
    get_opt()
    init_dns_file()
    handle_query = threading.Thread(target=create_dns_server, args=(), name='role_server').start()
    handle_ans = threading.Thread(target=handle_dns_ans, args=(), name='role_client').start()
