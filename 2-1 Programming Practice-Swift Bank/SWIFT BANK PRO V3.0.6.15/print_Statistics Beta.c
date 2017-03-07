#include<stdio.h>
#include<stdlib.h>
#include"alltype and alldefine.h"
#include"print_Statistics.h"

void print_Statistics(void)
{
	if((file_Statistics_P=fopen("Statistics.txt","w"))==NULL)
	{
		printf("The file could not be opened.\n");
	}
	else
	{
		int count=0;
		fprintf(file_Statistics_P,"WINDOW STATISTICS:\n");
		for(int i=0;i<=MAXWIN-1;i++)
		{
			if(is_Reach_Standard(sta_Windows[i])==0)
			{
				universe_P->satisfy_Bad_Win[count]=i;
			   	count++;
			}
			sta_Windows[i]->ave_Win_Serve_Time=sta_Windows[i]->total_Win_Client ? (double)sta_Windows[i]->total_Win_Serve_Time/sta_Windows[i]->total_Win_Client : 0;
			fprintf(file_Statistics_P,"WINDOW No.%d   :",i);
			fprintf(file_Statistics_P,"TOTAL CLIENT:%4d    ",sta_Windows[i]->total_Win_Client);
			fprintf(file_Statistics_P,"TOTAL SERVE TIME:%4d    ",sta_Windows[i]->total_Win_Serve_Time);
			fprintf(file_Statistics_P,"AVERAGE SERVE TIME:%15lf    ",sta_Windows[i]->ave_Win_Serve_Time);
			fprintf(file_Statistics_P,"GOOD:%4d    ",sta_Windows[i]->satisfy_Win_Good);
			fprintf(file_Statistics_P,"NORMAL:%4d    ",sta_Windows[i]->satisfy_Win_Norm);
			fprintf(file_Statistics_P,"BAD:%4d    ",sta_Windows[i]->satisfy_Win_Bad);
			fprintf(file_Statistics_P,"\n");
			
		}
		fprintf(file_Statistics_P,"\nBUSINESS HALL STATISTICS:\n");
		fprintf(file_Statistics_P,"TOTAL NORMAL CLIENT:%4d\n",universe_P->total_Norm);
		fprintf(file_Statistics_P,"TOTAL  VIP   CLIENT:%4d",universe_P->total_VIP);
		fprintf(file_Statistics_P,"\n\n");
		fprintf(file_Statistics_P,"WINDOWS DO NOT REACH STANDARD:\n");
		for(int i=0;i<=count-1;i++)
		{
			fprintf(file_Statistics_P,"WINDOW No.%d\n",universe_P->satisfy_Bad_Win[i]);
		}
	}
	fclose(file_Statistics_P);
	return;
}

void window_Statistics(STA_WIN_PTR cur_Sta_Window,WIN_PTR cur_Window)
{
	cur_Sta_Window->total_Win_Client++;
	cur_Sta_Window->total_Win_Serve_Time+=cur_Window->plan_Serve_Time;
	int degree=rand()%3-1;
	switch(degree)
	{
		case -1:
			cur_Sta_Window->satisfy_Win_Bad++;
			break;
		case  0:
			cur_Sta_Window->satisfy_Win_Norm++;
			break;
		case  1:
			cur_Sta_Window->satisfy_Win_Good++;
			break;
		default:
			printf("Error:Unknown ins.\n");
			break;				
	}
}
void universe_Statistics(WIN_PTR cur_Window,int i)
{
	if(strategy==STRATEGY_ORIENT)
	{
		if(IS_NORM_WIN)
		{
			universe_P->total_Norm++;
		}
		else
		{
			universe_P->total_VIP++;
		}
	}
	else
	{
		if(cur_Window->current_Number>0)
		{
			universe_P->total_Norm++;
		}
		else
		{
			universe_P->total_VIP++;
		}
	}
}

int is_Reach_Standard(STA_WIN_PTR cur_Sta_Window)
{
	if((cur_Sta_Window->total_Win_Client ? (double)cur_Sta_Window->satisfy_Win_Good/cur_Sta_Window->total_Win_Client : 1 )<STA_GOOD_RATE||
	(cur_Sta_Window->total_Win_Client ? (double)cur_Sta_Window->satisfy_Win_Bad/cur_Sta_Window->total_Win_Client : 0 )>STA_BAD_RATE)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

