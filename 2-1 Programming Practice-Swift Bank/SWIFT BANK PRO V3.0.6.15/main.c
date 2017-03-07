/*
	Name: SWIFT BANK PRO 2.0 Beta
	Copyright: All rights reserved.
	Author: L.S.Y
	Date: 29/05/15 22:01
	Description: The first version has been completed.
*/

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include"alltype and alldefine.h"
#include"main.h"

NORM_PTR cur_Norm_P;
NORM_PTR head_Norm_P;
 
VIP_PTR cur_VIP_P;
VIP_PTR head_VIP_P;

REST_PTR cur_Rest_P;
REST_PTR head_Rest_P;

EVENT_PTR cur_Event_P;
EVENT_PTR head_Event_P;

INFOR_PTR head_Infor_P;//VIP information list node head pointer
INFOR_PTR cur_Infor_P;//VIP information list node current pointer

HANDLE head_Mutex;//global : getinput mutex
WIN_PTR windows[MAXWIN];//global : windows array
STA_WIN_PTR sta_Windows[MAXWIN];//global : windows statistics array
STA_ALL_PTR universe_P;//global : universe statistics pointer

char event;
int Time;
int rest;//the number of the window to rest
int norm_Num;//the normal number 
int vip_Num;//the VIP number
FILE* file_Output_P;//the file pointer of the print_Message
FILE* file_Statistics_P;//the file pointer of the print_Statistics
FILE* fPtr;//the file pointer of the data

int cur_Norm_Num;
int cur_VIP_Num;
int VIP_Time;//to count the VIPSERVLen
int open_Norm_Num;//the number of the opened normal windows at present
int open_VIP_Num;//the number of the opened VIP windows at present
int strategy;//the strategy : orient by 0 and BTW by 1
int VIP_sum;//the amount of the VIP clients

char string_Print[BIT+1];//the array to store the client number which has been changed to string

int MaxSeqLen;//the maximum length of per sequence waiting
int MinSec;//the minimum time of single business
int MaxSec;//the maximum time of single business
int MinRestSec;//the minimum time of rest
int MaxRestSec;//the maximum time of rest
int VIPSERVLen;//the time to judge if the VIP window's amount could be changed

clock_t start;//the start time of the system

int main(void)
{
	printf("\
	Name: SWIFT BANK PRO 2.0 Beta\n\
	Copyright: All rights reserved.\n\
	Author: L.S.Y\n\
	Date: 29/05/15 22:01\n\
	Description: The first version has been completed.\n\
	");
	srand(time(NULL));
	PRINT_SEPARATOR;
	Initialize();
	printf("\n\nINS:The common initialization has been finished.\n");
	printf("INS:You need to initialize the VIP data by follwing steps.\n");
	initialize_Information();
	printf("INS:The VIP DATA initialization has been finished.\n");
	printf("INS:U have to value the following six parameters.\n");
	w_Config();
	printf("INS:The parameters have been successfully written in the file config.ini .\n");
	r_Config();
	getchar();
	printf("INS:The parameters have been read.\n");
	
	PRINT_SEPARATOR;
	int input_Str;
	printf("INS:Choose the WAY OF INPUT:\n0---FILE\n1---KEYBOARD\n");
	scanf("%d",&input_Str);
	getchar();
	

	if(input_Str==0)
	{
		printf("INS:You've chose the file input.Do nothing untill the end.\n");
		system("pause");
		start=clock();// count begin from herE
		create_Event_List();
		cur_Event_P=head_Event_P->nextPtr;
		
		while(!is_All_Close()||event!='Q')
		{
		
			if(cur_Event_P!=NULL&&cur_Event_P->time==Time)
			{
				while(cur_Event_P->time==Time)
				{
					file_Event_Control();
					cur_Event_P=cur_Event_P->nextPtr;
					if(cur_Event_P==NULL)
					{
						break;
					}
				}
			}
			mainThread();
		}
	}
	else if(input_Str==1)
	{
		printf("INS:You've chose the keyboard input.\n");
		data_Maintenance();
		printf("INS:Input the order with the following instructions.\n");
		printf("Enter your choice\n\
				G-A normal client arrives\n\
				V-A VIP client arrives\n\
				R-A window asks for resting\n\
				X-Enter the customer data maintenance interface\n\
				Q-Quit");
		system("pause");
		start=clock();// count begin from herE
		
		head_Mutex=CreateMutex(NULL,FALSE,NULL);
		HANDLE 
		head_Thread_Input=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)get_Input,NULL,0,NULL);
		
		while(!is_All_Close()||event!='Q')
		{
			WaitForSingleObject(head_Mutex,INFINITE);
			mainThread();
			ReleaseMutex(head_Mutex);
		}
		CloseHandle(head_Thread_Input);
	}
	else
	{
		printf("ERROR:UNKNOWN INPUT_STR!\n");
	}
	print_Statistics();
	return 0;
}

void Initialize(void)
{
	WIN blank_Open_WIN={STATE_IDLE,0,0,0,0,0,0,0,0,'N'};
	WIN blank_Close_WIN={STATE_CLOSE,0,0,0,0,0,0,0,0,'N'};
	STA_WIN blank_STA_WIN={0,0,0,0,0,0};
	
	head_Norm_P=malloc(sizeof(NORM));
	head_Norm_P->nextPtr=NULL;
	head_Norm_P->client_Norm_Num=-9999;
	cur_Norm_P=head_Norm_P;

	head_VIP_P=malloc(sizeof(VIP));
	head_VIP_P->nextPtr=NULL;
	head_VIP_P->client_VIP_Num=-9999;
	cur_VIP_P=head_VIP_P;
	
	head_Rest_P=malloc(sizeof(REST));//new struct type
	head_Rest_P->nextPtr=NULL;
	head_Rest_P->window_Num=-1;
	head_Rest_P->inqueue_Time=-1;
	cur_Rest_P=head_Rest_P;
	
	universe_P=(STA_ALL_PTR)malloc(sizeof(STA_ALL));
	universe_P->total_Norm=0;
	universe_P->total_VIP=0;
	
	for(int i=0;i<=MIN_OPEN_NORM_WIN-1;i++)
	{
		windows[i]=malloc(sizeof(WIN));
		*windows[i]=blank_Open_WIN;
	}
	for(int i=MIN_OPEN_NORM_WIN;i<=MAX_NORM_WIN-1;i++)
	{
		windows[i]=malloc(sizeof(WIN));
		*windows[i]=blank_Close_WIN;
	}
	for(int i=MAX_NORM_WIN;i<=MAXWIN-MIN_OPEN_VIP_WIN-1;i++)
	{
		windows[i]=malloc(sizeof(WIN));
		*windows[i]=blank_Open_WIN;
	}
	for(int i=MAXWIN-MIN_OPEN_VIP_WIN;i<=MAXWIN-1;i++)
	{
		windows[i]=malloc(sizeof(WIN));
		*windows[i]=blank_Close_WIN;
	}
	for(int i=0;i<=MAXWIN-1;i++)
	{
		sta_Windows[i]=malloc(sizeof(STA_WIN));
		*sta_Windows[i]=blank_STA_WIN;
	}
	for(int i=0;i<=MAXWIN-1;i++)
	{
		universe_P->satisfy_Bad_Win[i]=0;
	}
	
	
	Time=0;
	event='\0';
	rest=-1;
	norm_Num=1;
	vip_Num=-1;
	cur_Norm_Num=0;
	cur_VIP_Num=0;
	VIP_Time=0;
 	open_Norm_Num=MIN_OPEN_NORM_WIN;
	open_VIP_Num=MIN_OPEN_VIP_WIN;
	strategy=STRATEGY_ORIENT;
}




void r_Config(void)
{
	extern int MaxSeqLen;
	extern int MinSec;
	extern int MaxSec;
	extern int MinRestSec;
    extern int MaxRestSec;
    extern int VIPSERVLen;
	FILE* P;
	P=fopen("config.ini","r");
	fscanf(P,"[MaxSeqLen]%d\n",&MaxSeqLen);
	fscanf(P,"[MinSec]%d\n",&MinSec);
	fscanf(P,"[MaxSec]%d\n",&MaxSec);
	fscanf(P,"[MinRestSec]%d\n",&MinRestSec);
	fscanf(P,"[MaxRestSec]%d\n",&MaxRestSec);
	fscanf(P,"[VIPSERVLen]%d",&VIPSERVLen);
	fclose(P);
	return ;
}

void w_Config(void)
{
	FILE* P;
	int maxseqlen,minsec,maxsec,minrestsec,maxrestsec,vipservlen;
	
	P=fopen("config.ini","w");
	printf("Input the value of MaxSeqLen:");
	scanf("%d",&maxseqlen);
	fprintf(P,"[MaxSeqLen]%d\n",maxseqlen);
	printf("Input the value of MinSec:");
	scanf("%d",&minsec);
	fprintf(P,"[MinSec]%d\n",minsec);
	printf("Input the value of MaxSec:");
	scanf("%d",&maxsec);
	fprintf(P,"[MaxSec]%d\n",maxsec);
	printf("Input the value of MinRestSec:");
	scanf("%d",&minrestsec);
	fprintf(P,"[MinRestSec]%d\n",minrestsec);
	printf("Input the value of MaxRestSec:");
	scanf("%d",&maxrestsec);
	fprintf(P,"[MaxRestSec]%d\n",maxrestsec);
	printf("Input the value of VIPSERVLen:");
	scanf("%d",&vipservlen);
	fprintf(P,"[VIPSERVLen]%d\n",vipservlen);
	
	fclose(P);
	return ;
}




void doubleTrans(void)
{
	for(int i=0;i<=MAXWIN-1;i++)
	{
		if(windows[i]->state_Now==STATE_IDLE&&head_Rest_P->nextPtr!=NULL&&is_In_Rest_List(i)&&is_Permit_Rest(windows[i],i))
		{
			state_To_Rest(windows[i]);
			printf("One window has been to the Rest.\n");
			//delete the first rest queue,
			//anyway ,it 's the first one to rest(alo has added in alloc.c)
			REST_PTR temp_Rest_P=head_Rest_P->nextPtr;
			if(head_Rest_P->nextPtr==cur_Rest_P)//如果 cur同时是首尾 
			{
				cur_Rest_P=head_Rest_P;//指针回归 
			}
			head_Rest_P->nextPtr=temp_Rest_P->nextPtr;
			free(temp_Rest_P);
			temp_Rest_P=NULL;
		}
		else if(windows[i]->state_Now==STATE_IDLE&&(( ( ( IS_NORM_WIN && ( cur_Norm_Num<=open_Norm_Num*(SCALE-1) ) 
				&& ( open_Norm_Num>=MIN_OPEN_NORM_WIN+1 ) )
			||( ( IS_VIP_WIN && VIP_Time<VIPSERVLen )
				&& ( open_VIP_Num>=MIN_OPEN_VIP_WIN+1 ) ) )
			&&  windows[i]->current_Number==0 )
			||( ( event=='Q' ) &&( (IS_NORM_WIN&&head_Norm_P->nextPtr==NULL)||(IS_VIP_WIN&&head_VIP_P->nextPtr==NULL) ))))
		{
			if(IS_VIP_WIN&&strategy==STRATEGY_BTW&&cur_Norm_Num>=(open_Norm_Num+open_VIP_Num)*SCALE)
			{
				break;
			}
			state_To_Closed(windows[i]);
			if(IS_NORM_WIN)
			{
				open_Norm_Num--;
				printf("One normal window has been closed.\n");
			}
			else
			{
				open_VIP_Num--;
				printf("One VIP window has been closed.\n");
			}
			if(event=='Q')
			{
				windows[i]->quit='Y';
			}

		}
		else
		{
			;
		}
	}
}

int is_In_Rest_List(int i)
{
	REST_PTR temp_Rest_P=head_Rest_P->nextPtr;
	while(temp_Rest_P!=NULL)
	{
		if(temp_Rest_P->window_Num==i)
		{
			return 1;
		}
		temp_Rest_P=temp_Rest_P->nextPtr;
	}
	return 0;
}

int is_Permit_Rest(WIN_PTR cur_Window,int i)
{
	if(head_Rest_P->nextPtr->window_Num==i
	&&(double)(cur_Norm_Num+cur_VIP_Num)/(open_Norm_Num+open_VIP_Num)<MaxSeqLen
	&&((IS_NORM_WIN&&open_Norm_Num>=MIN_OPEN_NORM_WIN+1)||(IS_VIP_WIN&&open_VIP_Num>=MIN_OPEN_VIP_WIN+1)))
	{
		cur_Window->plan_Rest_Time=(rand()%(MaxRestSec-MinRestSec)+MinRestSec);
		return 1;
	}
	else
	{
		return 0;
	}
}


void file_Event_Control(void)
{
	INFOR_PTR temp_Infor_P;
	switch(cur_Event_P->Ins)
	{
		case 'G':
			add_Normal_List();
			break;
		case 'V':
			temp_Infor_P=head_Infor_P->nextPtr;
			while(temp_Infor_P!=NULL)
			{
				if(!strcmp(temp_Infor_P->VIP_Number,cur_Event_P->extra))
				{
					add_VIP_List();
					break;
				}
				temp_Infor_P=temp_Infor_P->nextPtr;
			}
			break;
		case 'R':
			printf("Input the window number from 0 to 7.\n");
			rest=atoi(cur_Event_P->extra);
			add_Rest_List();
			printf("The window has added to rest.\n");
			break;
		case 'Q':
			printf("You've instructed QUIT.\n");
			printf("Please Waiting the end till the windows has finished the work(if necessary).\n");
			event='Q';
			system("pause");
			break;
		default:
			UNKNOWN;
			break;
	}
}

void create_Event_List(void)
{
	EVENT_PTR temp_Event_P;
	head_Event_P=malloc(sizeof(EVENT));
	head_Event_P->time=-1;
	head_Event_P->Ins='\0';
	head_Event_P->extra[0]='\0';
	head_Event_P->nextPtr=NULL;
	cur_Event_P=head_Event_P;
	FILE* fp;
	char ch;
	int destTime=0;
	char buf_Time[5];
	char buf_VIP[10];
	char buf_Rest[3];
	
	fp=fopen("input.txt","r");
	
	int i;
	ch=fgetc(fp);
	while(ch!='Q')
	{
		switch(ch)
		{
			case 'T':
				fgetc(fp);
				i=0;
				while((ch=fgetc(fp))!=',')
				{
					buf_Time[i]=ch;
					i++;
				}
				buf_Time[i]='\0';
				destTime=atoi(buf_Time);
				fgetc(fp);
				fgetc(fp);
				fgetc(fp);
				fgetc(fp);
				fgetc(fp);
				fgetc(fp);
				break;
			case 'G':
				temp_Event_P=malloc(sizeof(EVENT));
				temp_Event_P->extra[0]='\0';
				temp_Event_P->Ins='G';
				temp_Event_P->time=destTime;
				temp_Event_P->nextPtr=NULL;
				
				cur_Event_P->nextPtr=temp_Event_P;
				cur_Event_P=cur_Event_P->nextPtr;
				break;
			case 'V':
				i=0;
				ch=fgetc(fp);
				while(ch!='|'&&ch!='\n')
				{
					buf_VIP[i]=ch;
					i++;
					ch=fgetc(fp);
				}
				buf_VIP[i]='\0';
				
				temp_Event_P=malloc(sizeof(EVENT));
				strcpy(temp_Event_P->extra,buf_VIP);
				temp_Event_P->Ins='V';
				temp_Event_P->time=destTime;
				temp_Event_P->nextPtr=NULL;
				
				cur_Event_P->nextPtr=temp_Event_P;
				cur_Event_P=cur_Event_P->nextPtr;
				break;
			case 'R':
				i=0;
				ch=fgetc(fp);
				while(ch!='|'&&ch!='\n')
				{
					buf_Rest[i]=ch;
					i++;
					ch=fgetc(fp);
				}
				buf_Rest[i]='\0';
				
				temp_Event_P=malloc(sizeof(EVENT));
				strcpy(temp_Event_P->extra,buf_Rest);
				temp_Event_P->Ins='R';
				temp_Event_P->time=destTime;
				temp_Event_P->nextPtr=NULL;
				
				cur_Event_P->nextPtr=temp_Event_P;
				cur_Event_P=cur_Event_P->nextPtr;
				break;
			default:
				break;
		}
		ch=fgetc(fp);
	}
	temp_Event_P=malloc(sizeof(EVENT));
	temp_Event_P->extra[0]='\0';
	temp_Event_P->Ins='Q';
	temp_Event_P->time=destTime;
	temp_Event_P->nextPtr=NULL;
				
	cur_Event_P->nextPtr=temp_Event_P;
	cur_Event_P=cur_Event_P->nextPtr;
}

void mainThread(void)
{
	if(head_Norm_P->nextPtr!=NULL||head_VIP_P->nextPtr!=NULL)
	{
		if(strategy==STRATEGY_ORIENT)
		{
			alloc_Num_Orient();
			printf("***DEBUG***:the num has been allocated by strategy ORIENT.\n");
		}
		else if(strategy==STRATEGY_BTW)
		{
			alloc_Num_BTW();
			printf("***DEBUG***:the num has been allocated by strategy BTW.\n");
		}
		else
		{
			printf("Error:Unknown strategy.\n");
		}
	}
	if(head_Rest_P->nextPtr!=NULL)
	{
		sort_Rest();
		printf("The list has been sorted.\n");
	}
	state_Trans();
	doubleTrans();
		
	file_Output();//use the file ptr to output
	time_Count();
}

