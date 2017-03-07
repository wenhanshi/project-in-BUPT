#ifndef			__PRINT_MESSAGE_H__
#define			__PRINT_MESSAGE_H__

void file_Output(void);//to print the message
void print_Normal_List(void);//to print the normal list
void print_VIP_List(void);//to print the VIP list
void print_Rest_List(void);//to print the rest list
char* itos_Client(int);//to convert the client number from integer to string
char* ctos_PrintState(char);//to convert the state from character to string

extern FILE* file_Output_P;

extern NORM_PTR cur_Norm_P;
extern NORM_PTR head_Norm_P;
 
extern VIP_PTR cur_VIP_P;
extern VIP_PTR head_VIP_P;

extern REST_PTR cur_Rest_P;
extern REST_PTR head_Rest_P;

extern WIN_PTR windows[MAXWIN];

extern int Time;
extern int norm_Num;
extern int vip_Num;

extern int cur_Norm_Num;
extern int cur_VIP_Num;
extern int open_Norm_Num;
extern int open_VIP_Num;

extern char string_Print[BIT+1];

#endif

