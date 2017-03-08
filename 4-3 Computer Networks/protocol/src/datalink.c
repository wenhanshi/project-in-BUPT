#include <stdio.h>
#include <string.h>

#include "protocol.h"
#include "datalink.h"

#define DATA_TIMER 1500
#define ACK_TIMER 300

#define MAX_SEQ 7

// to enhance the feature of the process GO_BACK_N
// nak is closed by default
// enable the nak frame if necessary

struct FRAME {
    unsigned char kind; //frame kind : ack/nak/data
    unsigned char ack;
    unsigned char seq; //sequence number from 0 to MAX_SEQ
    unsigned char data[PKT_LEN];
    unsigned int padding; // give room to crc32
};

static unsigned char buffer[MAX_SEQ+1][PKT_LEN]; //out buffer here
static unsigned char nbuffered; //the use of buffers
static unsigned char frame_expected = 0; //receiver window with the width of 1
static unsigned char ack_expected = 0; //lower bound of send window
static unsigned char next_frame_to_send = 0; //upper bound of send window
int no_nak = 1; //only need one nak call for expect frame

static int phl_ready = 0;

static void put_frame(unsigned char *frame, int len) //the driver to send_frame
{
    *(unsigned int *)(frame + len) = crc32(frame, len);
    send_frame(frame, len + 4);
    phl_ready = 0;
}
char inc(char c)
{
    return (c + 1) % (MAX_SEQ + 1);
}


static void send_ack_frame(void)
{
    struct FRAME s;
    s.kind = FRAME_ACK;
    s.ack = ( frame_expected + MAX_SEQ ) % (MAX_SEQ + 1); // ack is the former state of frame_expected
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
    memcpy(s.data, buffer[next_frame_to_send], PKT_LEN);
    dbg_frame("Send DATA %d %d, ID %d\n", s.seq, s.ack, *(short *)s.data);
    put_frame((unsigned char *)&s, 3 + PKT_LEN);
    start_timer(next_frame_to_send, DATA_TIMER);
    stop_ack_timer();
}
static void send_nakdata_frame(unsigned char send_ack) // when got an nak , decide which frame to resend
{
    struct FRAME s;
    s.kind = FRAME_DATA;
    s.seq =( send_ack + 1 ) % ( MAX_SEQ + 1);  //next state of the present-sender-ack
    s.ack = ( frame_expected + MAX_SEQ ) % (MAX_SEQ + 1);
    memcpy(s.data, buffer[s.seq], PKT_LEN);
    dbg_frame("Send RESEND-DATA resendseq:%d ack:%d, ID %d\n",
               s.seq, s.ack, *(short *)s.data);
    put_frame((unsigned char *)&s, 3 + PKT_LEN);
    start_timer(s.seq, DATA_TIMER);
    stop_ack_timer();
}

static void send_nak_frame(void)
{
    struct FRAME s;
    no_nak = 0;
    s.kind = FRAME_NAK;
    s.seq = 0;  // no need of seq for nak frame
    s.ack = ( frame_expected + MAX_SEQ ) % (MAX_SEQ + 1);
    dbg_frame("Send NAK req: %d\n", s.ack);
    put_frame((unsigned char *)&s, 3);
}

static int between(unsigned char a, unsigned char b, unsigned char c)
{
    if( (a<=b&&b<c) || (c<a&&a<=b) || (b<c&&c<a) ) return 1;
    return 0;
}
int main(int argc, char **argv)
{
    int event, arg;
    struct FRAME f;
    int len = 0;
    int i;

    protocol_init(argc, argv);
    disable_network_layer();

    for(;;)
    {
        event = wait_for_event(&arg);

        switch (event)
        {

        case NETWORK_LAYER_READY:
            get_packet(buffer[next_frame_to_send]); // get packet from network layer to buffer
            send_data_frame();
            nbuffered++;
            next_frame_to_send = inc(next_frame_to_send); // update send-window
            break;

        case PHYSICAL_LAYER_READY:
            phl_ready = 1;
            break;

        case FRAME_RECEIVED:
            len = recv_frame((unsigned char *)&f, sizeof f);  // to get the length of the frame
            if (crc32((unsigned char *)&f, len) != 0)
            {
                dbg_frame("BAD CRC : %d\n",f.seq);
                if(no_nak == 1)
                    // nak is not enabled by default
                    // no need to do anything
                    // send_nak_frame();
                break;
            }
            if (f.kind == FRAME_DATA)  // here we got intact data frame
            {
                dbg_frame("Recv DATA %d %d, ID %d , PHL QUEUE: %d\n",
                           f.seq, f.ack, *(short *)f.data, phl_sq_len());
                if (f.seq != frame_expected && no_nak == 1)  // the frame is not the one we want
                {
                    // nak is not enabled by default
                    // no need to do anything
                    // send_nak_frame();
                }
                if (f.seq == frame_expected)
                {
                    put_packet(f.data, len - 7);
                    no_nak = 1; // update the nak
                    start_ack_timer(ACK_TIMER); // see if to send ack alone
                    frame_expected = inc(frame_expected); // update receive-window
                }
            }
            if(f.kind == FRAME_ACK)  // single ack here , piggy-backing in a minute
            {
                dbg_frame("!!!!recv lonely ack %d\n",f.ack);
            }
            if(f.kind == FRAME_NAK)
            {
                // nak is not enabled by default
                dbg_frame("!!!!recv lonely NAK call for  %d\n",(f.ack + 1) % (MAX_SEQ + 1));
                if(between(ack_expected , (f.ack + 1) % (MAX_SEQ + 1) , next_frame_to_send)) // if the resend data is in send-window
                    send_nakdata_frame(f.ack);
            }
            while(between(ack_expected , f.ack , next_frame_to_send)) // the process of piggy-backing
            {
                stop_timer(ack_expected);
                ack_expected = inc(ack_expected);
                nbuffered -- ;
            }
            break;

        case DATA_TIMEOUT:
            dbg_event("---- DATA %d timeout\n ----", arg);
            next_frame_to_send = ack_expected; // return to where going wrong
            for (i = 1;i <= nbuffered ;i++)// the process of GO BACK N
            {
                send_data_frame();
                next_frame_to_send = inc(next_frame_to_send);
            }
            break;

        case ACK_TIMEOUT:
            dbg_event("---- ACK %d timeout\n ---- ", arg);
            send_ack_frame();
            break;
        } // end switch
        if (nbuffered < MAX_SEQ && phl_ready)
            enable_network_layer();
        else
            disable_network_layer();
    }//end for
}
