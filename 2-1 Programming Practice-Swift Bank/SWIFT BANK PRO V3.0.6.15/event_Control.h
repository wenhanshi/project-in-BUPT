#ifndef			__EVENT_CONTROL_H__
#define			__EVENT_CONTROL_H__

void event_Control(char event);//to get event and add clients or windows to the list
void add_Normal_List(void);//to add a normal client to the normal list
void add_VIP_List(void);//to add a VIP client to the VIP list
void add_Rest_List(void);//to add a window to the rest list
int is_VIP_Client(void);//to judge if the client is VIP 

extern NORM_PTR cur_Norm_P;
extern NORM_PTR head_Norm_P;
 
extern VIP_PTR cur_VIP_P;
extern VIP_PTR head_VIP_P;

extern REST_PTR cur_Rest_P;
extern REST_PTR head_Rest_P;

extern INFOR_PTR head_Infor_P;
extern INFOR_PTR cur_Infor_P;

extern char event;
extern int rest;
extern int norm_Num;
extern int vip_Num;

extern int cur_Norm_Num;
extern int cur_VIP_Num;
extern int VIP_Time;
extern int open_Norm_Num;
extern int open_VIP_Num;

extern int strategy;
extern int Time;

extern FILE* fPtr;

#endif

