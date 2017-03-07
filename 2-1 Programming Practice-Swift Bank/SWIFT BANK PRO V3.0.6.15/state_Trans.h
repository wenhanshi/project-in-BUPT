#ifndef			__STATE_TRANS_H__
#define			__STATE_TRANS_H__

void state_Trans(void);//to transform the state

int is_Get_Mission(WIN_PTR);//to judge if the window has got mission
int is_Over_WaitTime(WIN_PTR);//to judge if the window has reached the planned wait time
int is_ClientArrive(WIN_PTR);//to judge if the client has arrived at the window
int is_Over_Mission(WIN_PTR);//to judge if the window has completed the mission
int is_Over_RestTime(WIN_PTR);//to judge if the window has reached the planned rest time

void state_To_Closed(WIN_PTR);//to transform the window's state to closed
void state_To_Idle(WIN_PTR);//to transform the window's state to idle
void state_To_Waiting(WIN_PTR);//to transform the window's state to waiting
void state_To_Working(WIN_PTR);//to transform the window's state to working
void state_To_Rest(WIN_PTR);//to transform the window's state to rest

int is_All_Close(void);//to judge if all the windows has been closed
int is_All_Rest(void);//to judge if all the windows has rested

extern void window_Statistics(STA_WIN_PTR,WIN_PTR);
extern void universe_Statistics(WIN_PTR ,int);

extern WIN_PTR windows[MAXWIN];
extern STA_WIN_PTR sta_Windows[MAXWIN];

extern int cur_Norm_Num;
extern int cur_VIP_Num;
extern int VIP_Time;
extern int open_Norm_Num;
extern int open_VIP_Num;

extern int MaxSeqLen;
extern int MinSec;
extern int MaxSec;
extern int MinRestSec;
extern int MaxRestSec;
extern int VIPSERVLen;

extern int strategy;
extern int event;

#endif

