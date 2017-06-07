# DNS RELAY SERVER

This is a course work of course Computer Network.Such simple DNS server is a good practice for getting know about `socket` with Python and other Python useful package, such as `struct.py`.

## How to use
There is only a single script `dns_server.py`.  
```shell
$ python dns_server.py -f $FILE_PATH -d $REMOTE_DNS_SERVER
```
- Use `-f` to include a ip-name search table, use `dns_relay.txt` as default
- Use `-d` to introduce the ip address of remote DNS server, such as `8.8.8.8` or `10.3.9.5` (@BUPT)

For exapmle:
```shell
$ python dns_server.py -f G:/test.txt -d 8.8.8.8
```

## Features
- A simple course work with no more than 200 lines of code
- Using double threads for decoupling dns relay server  
```Python
if __name__ == '__main__':
    # command line options
    get_opt()
    # load dns search table
    init_dns_file()
    # to be a DNS server for clients in LAN
    handle_query = threading.Thread(target=create_dns_server, args=(), name='role_server').start()
    # to be a virtual client for remote DNS server
    handle_ans = threading.Thread(target=handle_dns_ans, args=(), name='role_client').start()
```
- Only handle dns frame with qtype = A(1), qclass = IN(1)
