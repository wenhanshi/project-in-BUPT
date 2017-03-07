#ifndef			__MAIN_H__
#define			__MAIN_H__

void Initialize(void);//to initialize the varieties and struct
void doubleTrans(void);//to transform the Idle state
void w_Config(void);//to write the config file
void r_Config(void);//to read the config file
void file_Event_Control(void);//to realize the function of reading event from file
void create_Event_List(void);//to create the event list after reading event from the file
void mainThread(void);//the main thread

int is_In_Rest_List(int);//to judge if the window is in the rest list
int is_Permit_Rest(WIN_PTR,int);//to judge if the window is permitted to rest

extern int is_All_Close(void);
extern void data_Maintenance(void);
extern void print_Statistics(void);
extern void state_To_Closed(WIN_PTR);
extern void add_Normal_List(void);
extern void add_VIP_List(void);
extern void add_Rest_List(void);
extern void alloc_Num_Orient(void);
extern void alloc_Num_BTW(void);
extern void sort_Rest(void);
extern void state_Trans(void);
extern void state_To_Rest(WIN_PTR);
extern void sort_Rest(void);
extern void file_Output(void);
extern void time_Count(void);
extern int initialize_Information(void);
extern LPVOID WINAPI get_Input(LPVOID);

#endif

