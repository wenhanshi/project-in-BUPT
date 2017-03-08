#include <stdio.h>
#include <string.h>

#include "protocol.h"
#include "datalink.h"

#define DATA_TIMER  3000
#define ACK_TIMER 100
#define MAX_SEQ 31
#define MAX_BUF (( MAX_SEQ + 1 ) / 2)
#define MAX_TIMER 64

struct FRAME {
    unsigned char kind; // frame kind : ack/nak/data
    unsigned char ack;
    unsigned char seq; // sequence number from 0 to MAX_SEQ
    unsigned char data[PKT_LEN];
    unsigned int padding; // give room to crc32
};

static unsigned char out_buffer[MAX_BUF][PKT_LEN]; // buffer to send
static unsigned char in_buffer[MAX_BUF][PKT_LEN]; // buffer to receive
static unsigned char nbuffered; // the use of buffers
static unsigned char frame_expected = 0; // lower bound of receive window
static unsigned char ack_expected = 0; // lower bound of send window
static unsigned char next_frame_to_send = 0; // upper bound of send window
static unsigned char too_far = MAX_BUF; // upper bound of receive window
int no_nak = 1 ; // only need one nak call for expect frame
int arrv[MAX_BUF]; // if the in_buffer is in use , make sure put_packet in order
int in_timer[MAX_TIMER]; // array of timer , to decide the time of unconfirmed frames

static int phl_ready = 0;

void inc_timer(void) // increase the timer of each unconfirmed frames
{
    int i;
    for(i = 0 ; i <= MAX_SEQ ; i++)
    {
        if(in_timer[i] >= 0)
            in_timer[i] ++;
    }
}

unsigned char get_oldest_frame(void) // get the oldest unconfirmed frame
{
    int i;
    int max_timer = -2;
    int of;

    for(i = 0;i<=MAX_SEQ;i++)
    {
        if(in_timer[i] > max_timer)
        {
            of = i;
            max_timer = in_timer[i];
        }
    }
    return  of;
}
static void put_frame(unsigned char *frame, int len)
{
    *(unsigned int *)(frame + len) = crc32(frame, len);
    send_frame(frame, len + 4);
    phl_ready = 0;
}
char inc(char c)
{
    return (c + 1) % (MAX_SEQ + 1);
}

static void send_ack_frame(void) // single ack to send
{
    struct FRAME s;

    s.kind = FRAME_ACK;
    s.ack = ( frame_expected + MAX_SEQ ) % (MAX_SEQ + 1);
    dbg_frame("Send ACK  %d\n", s.ack);
    put_frame((unsigned char *)&s, 2);
    stop_ack_timer();
}
static void send_data_frame(void)
{
    struct FRAME s;

    s.kind = FRAME_DATA;
    s.seq = next_frame_to_send;
    s.ack = ( frame_expected + MAX_SEQ ) % (MAX_SEQ + 1);
    memcpy(s.data, out_buffer[s.seq % MAX_BUF], PKT_LEN);
    dbg_frame("Send DATA %d %d, ID %d\n", s.seq, s.ack, *(short *)s.data);
    put_frame((unsigned char *)&s, 3 + PKT_LEN);
    start_timer(s.seq, DATA_TIMER);int event, arg;
    struct FRAME f;
    int len = 0; // the length of frame
    in_timer[s.seq]++; // let timer of s.seq -1 -> 0 ,to start timer
    inc_timer(); // increase every started timer
    stop_ack_timer();
}
static void send_nakdata_frame(unsigned char send_ack) // resend data frame due to nak
{
    struct FRAME s;

    s.kind = FRAME_DATA;
    s.seq =( send_ack + 1 ) % ( MAX_SEQ + 1);
    s.ack = ( frame_expected + MAX_SEQ ) % (MAX_SEQ + 1);
    memcpy(s.data, out_buffer[s.seq % MAX_BUF], PKT_LEN);
    dbg_frame("Send RESEND-DATA-TIMEOUT resendseq:%d ack:%d, ID %d\n",
               s.seq, s.ack, *(short *)s.data);
    put_frame((unsigned char *)&s, 3 + PKT_LEN);
    start_timer(s.seq, DATA_TIMER);
    in_timer[s.seq]++;
    inc_timer();
    stop_ack_timer();
}
static void send_timerout_data_frame(void) // resend data frame due to timeout
{
    struct FRAME s;

    s.kind = FRAME_DATA;
    s.seq = get_oldest_frame(); // send the oldest unconfirmed frame
    s.ack = ( frame_expected + MAX_SEQ ) % (MAX_SEQ + 1);
    memcpy(s.data, out_buffer[s.seq % MAX_BUF], PKT_LEN);
    dbg_frame("Send RESEND-DATA-NAK resendseq:%d ack:%d, ID %d\n",
               s.seq, s.ack, *(short *)s.data);
    put_frame((unsigned char *)&s, 3 + PKT_LEN);
    start_timer(s.seq, DATA_TIMER);
    in_timer[s.seq] = 0; // such frame become another unconfirmed frame
    inc_timer();
    stop_ack_timer();
}

static void send_nak_frame(void) // send single nak frame
{
    struct FRAME s;
    no_nak = 0;
    s.kind = FRAME_NAK;
    s.seq = 0;
    s.ack = ( frame_expected + MAX_SEQ ) % (MAX_SEQ + 1);
    dbg_frame("Send NAK req: %d\n", (s.ack + 1) % (MAX_SEQ + 1));
    put_frame((unsigned char *)&s, 3);
}

static int between(unsigned char a, unsigned char b, unsigned char c)
{
     // if the frame is in the window
    if( (a<=b && b<c) || (c<a &&a <=b) || (b<c && c<a) ) return 1;
    return 0;
}

int main(int argc, char **argv)
{
    int event, arg;
    struct FRAME f;
    int len = 0; // the length of frame
    int i;

    for( i = 0 ; i <= MAX_BUF - 1;i++) // initialize the buffer in use
        arrv[i] = 0;

    for( i = 0 ; i <= MAX_TIMER - 1 ; i++) // initialize the timer array
        in_timer[i] = -1;

    protocol_init(argc, argv);
    disable_network_layer();

    for (;;) {
        event = wait_for_event(&arg);

        switch (event) {
        case NETWORK_LAYER_READY:
            get_packet(out_buffer[next_frame_to_send % MAX_BUF]);
            send_data_frame();
            nbuffered++; // increase the buffer in use
            next_frame_to_send = inc(next_frame_to_send); // update the send-window
            break;

        case PHYSICAL_LAYER_READY:
            phl_ready = 1; // tag for enable network layer
            break;

        case FRAME_RECEIVED:
            //dbg_event("FRAME_RECEIVED\n");
            //for(i = 0;i<=MAX_SEQ;i++)
            //   lprintf("*%d ",in_timer[i]);
            //lprintf("\n");
            len = recv_frame((unsigned char *)&f, sizeof f);
            if (crc32((unsigned char *)&f, len) != 0)
            {
                dbg_frame("BAD CRC : %d\n",f.seq);
                if(no_nak == 1)
                    send_nak_frame(); // send nak due to bad crc32
                break; // no need for piggy-backing
            }
            if (f.kind == FRAME_DATA)
            {
                dbg_frame("Recv DATA %d %d, ID %d , PHL QUEUE: %d\n",
                           f.seq, f.ack, *(short *)f.data, phl_sq_len());
                if (f.seq != frame_expected && no_nak == 1) // not the expected frame
                    send_nak_frame();
                if(between(frame_expected,f.seq,too_far) && arrv[f.seq % MAX_BUF] == 0)
                {
                     // put frames to in_buffer
                    arrv[f.seq % MAX_BUF] = 1; // buffer is in use
                    memcpy(in_buffer[f.seq%MAX_BUF], f.data , PKT_LEN);
                    //lprintf("fe:%d\n",frame_expected);
                    //for(i = 0;i<=MAX_BUF -1 ;i++)
                    //    lprintf("%d:",arrv[i]);
                    //lprintf("\n");
                    while(arrv[frame_expected % MAX_BUF]) // check if is enable to put packet in order
                    {
                        arrv[frame_expected%MAX_BUF] = 0; // buffer is not in use
                        put_packet(in_buffer[frame_expected % MAX_BUF],len - 7);
                        no_nak = 1; // update the nak
                        start_ack_timer(ACK_TIMER); // see if to send single ack
                        frame_expected = inc(frame_expected); // update receive-window
                        too_far = inc(too_far);
                    }
                }
                //for(i = 0;i<=MAX_BUF -1 ;i++)
                //        lprintf("%d:",arrv[i]);
                //    lprintf("\n");
                //lprintf("--------\n");
            }
            if(f.kind == FRAME_ACK) // single ack
            {
                dbg_frame("!!!!recv lonely ack %d\n",f.ack);
            }
            if(f.kind == FRAME_NAK) // nak frame ,cautious : nak is taking ack as well
            {
                dbg_frame("!!!!recv lonely NAKNAK call for  %d\n",(f.ack + 1) % (MAX_SEQ + 1));
                if(between(ack_expected , (f.ack + 1) % (MAX_SEQ + 1) , next_frame_to_send))
                    // if the resend frame is in send-window
                    send_nakdata_frame(f.ack);
            }
            while(between(ack_expected , f.ack , next_frame_to_send)) // the process of piggy-backing
            {
                stop_timer(ack_expected);
                in_timer[ack_expected] = -1; // stop timer in array
                ack_expected = inc(ack_expected);
                nbuffered -- ;
            }
            break;

        case DATA_TIMEOUT:
            dbg_event("---- DATA %d timeout\n", arg);
            send_timerout_data_frame();
            break;

        case ACK_TIMEOUT:
            dbg_event("---- ACK %d timeout\n", arg);
            send_ack_frame();
            break;
        }
        if (nbuffered < MAX_BUF && phl_ready)
            enable_network_layer();
        else
            disable_network_layer();
   }
}
