#ifndef			__ALL_TYPE_AND_DEFINE_H__
#define			__ALL_TYPE_AND_DEFINE_H__

#define UNKNOWN printf("Error:Unknown instructions in switch.\n");
#define OVERFLOW printf("Error:Overflow in malloc.\n");
#define PRINT_SEPARATOR printf("***=====***=======L.S.Y=======***=====***\n");

#define MAXWIN 8
#define MAX_NORM_WIN 6

#define STATE_IDLE 'I'
#define STATE_WORKING 'W'
#define STATE_WAITING 'A'
#define STATE_CLOSE 'C'
#define STATE_REST 'R'

#define IS_NORM_WIN (i<=MAX_NORM_WIN-1)
#define IS_VIP_WIN (i>=MAX_NORM_WIN)
#define SCALE 3

#define MIN_OPEN_VIP_WIN 1
#define MIN_OPEN_NORM_WIN 3

#define VIPNUM_TO_STARTTIME 3

#define MAX_WAIT_TIME 10

#define FULLRATE 100

#define STRATEGY_ORIENT 0
#define STRATEGY_BTW 1

#define BIT 3

#define STA_GOOD_RATE 0.7
#define STA_BAD_RATE 0.1

//windows struct
struct window{
	char state_Now;
	int current_Number;
	int current_Serve_Time;
	int plan_Serve_Time;
	int current_Rest_Time;
	int plan_Rest_Time;
	int current_Wait_Time;
	int plan_Wait_Time;
	int total_Rest_Time;
	char quit;
};
typedef struct window WIN;
typedef WIN* WIN_PTR;

//windows statistics struct

struct win_Statistics{ 
	int total_Win_Client;
	int total_Win_Serve_Time;
	double ave_Win_Serve_Time;
	int satisfy_Win_Good;
	int satisfy_Win_Norm;
	int satisfy_Win_Bad;
};
typedef struct win_Statistics STA_WIN;
typedef STA_WIN* STA_WIN_PTR;


//universe statistics struct
struct universe_Statistics{
	int total_Norm;
	int total_VIP;
	int satisfy_Bad_Win[MAXWIN];//array to store the windows which do not reach the standard
};

typedef struct universe_Statistics STA_ALL;
typedef STA_ALL* STA_ALL_PTR;

//event list

struct event_Node{
	char Ins;
	int time;
	char extra[10];
	struct event_Node* nextPtr;
};
typedef struct event_Node EVENT;
typedef EVENT* EVENT_PTR;

//normal client list

struct client_Norm_Node{
	int client_Norm_Num;
	struct client_Norm_Node* nextPtr;
};
typedef struct client_Norm_Node NORM;
typedef NORM* NORM_PTR;


//VIP client list

struct client_VIP_Node{
	int client_VIP_Num;
	struct client_VIP_Node* nextPtr;
};
typedef struct client_VIP_Node VIP;
typedef VIP* VIP_PTR;
 
  
//windows rest list

struct win_Rest_Node{
	int window_Num;
	int inqueue_Time;
	struct win_Rest_Node* nextPtr;
};

typedef struct win_Rest_Node REST;
typedef REST* REST_PTR;

//VIP data list

struct VIP_Information{
	char VIP_Name[10];
    char VIP_Number[20];
    long long int balance_Account;
    struct VIP_Information* nextPtr;
};

typedef struct VIP_Information INFOR;
typedef INFOR* INFOR_PTR;

#endif

