#include<stdio.h>
#include<stdlib.h>
#include"alltype and alldefine.h"
#include"state_Trans.h"

static int i;//to pass the i to the state func to use IS_NROM_WIN

void state_Trans(void)
{
	for(i=0;i<=MAXWIN-1;i++)
	{
		switch(windows[i]->state_Now)//state_Now's type need to be changed
		{
			case STATE_CLOSE:
				if( ( ( IS_NORM_WIN&&cur_Norm_Num>=open_Norm_Num*SCALE ) 
				|| ( IS_VIP_WIN&&VIP_Time>=VIPSERVLen ) 
				|| ( strategy==STRATEGY_BTW&&IS_VIP_WIN&&cur_Norm_Num>=(open_Norm_Num+open_VIP_Num)*SCALE ) ) 
				&& ( event!='Q' ) )
				{
					state_To_Idle(windows[i]);
					if(IS_NORM_WIN)
					{
						open_Norm_Num++;
						printf("One normal window has been opened.\n");
					}
					else
					{
						open_VIP_Num++;
						printf("One VIP window has been opened.\n");
					}
				}
				else if(event=='Q')
				{
					windows[i]->quit='Y';
				}
				else
				{
					;
				}
				break;
			case STATE_IDLE:
				if(is_Get_Mission(windows[i]))
				{
					state_To_Waiting(windows[i]);
				}
				else
				{
					;
				}
				break;
			case STATE_REST:
				if(!is_Over_RestTime(windows[i]))
				{
					windows[i]->current_Rest_Time=windows[i]->current_Rest_Time+1;
					windows[i]->total_Rest_Time=windows[i]->total_Rest_Time+1;
				}
				else
				{
					state_To_Idle(windows[i]);
				}
				break;
			case STATE_WAITING:
				if(is_Over_WaitTime(windows[i]))
				{
					state_To_Idle(windows[i]);
				}
				else if(is_ClientArrive(windows[i])&&!is_Over_WaitTime(windows[i]))
				{
					state_To_Working(windows[i]);
				}
				else
				{
					windows[i]->current_Wait_Time=windows[i]->current_Wait_Time+1;
				}
				break;
			case STATE_WORKING:
				if(!is_Over_Mission(windows[i]))
				{
					windows[i]->current_Serve_Time=windows[i]->current_Serve_Time+1;
				}
				else
				{
					window_Statistics(sta_Windows[i],windows[i]);
					universe_Statistics(windows[i],i);
					state_To_Idle(windows[i]);
				}
				break;
			default :
				UNKNOWN;
				break;
		}
	}
	return ;
}

int is_Get_Mission(WIN_PTR cur_Window) 
{
	if(cur_Window->current_Number!=0&&cur_Window->plan_Serve_Time==0)
	{
		cur_Window->plan_Serve_Time=(rand()%(MaxSec-MinSec)+MinSec);
		cur_Window->plan_Wait_Time=rand()%MAX_WAIT_TIME+1;
		return 1;
	}
	else
	{
		return 0;
	}
}
int is_Over_WaitTime(WIN_PTR cur_Window)
{
	if(cur_Window->current_Wait_Time==cur_Window->plan_Wait_Time)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int is_ClientArrive(WIN_PTR cur_Window)
{
	int P=rand()%FULLRATE+1;
	if(P>=FULLRATE/2)
	{
		printf("Notice:the Client has come.\n");
		return 1;
	}
	else
	{
		printf("Notice:the Client has NOT come.\n");
		
		return 0;
	}
}
int is_Over_Mission(WIN_PTR cur_Window)
{
	if(cur_Window->current_Serve_Time==cur_Window->plan_Serve_Time&&cur_Window->plan_Serve_Time!=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int is_Over_RestTime(WIN_PTR cur_Window)
{
	if(cur_Window->current_Rest_Time==cur_Window->plan_Rest_Time
	&&cur_Window->plan_Rest_Time!=0
	&&!is_All_Rest())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//tras funcs definition
void state_To_Closed(WIN_PTR cur_Window)
{
	cur_Window->state_Now=STATE_CLOSE;
}
void state_To_Idle(WIN_PTR cur_Window)
{
	cur_Window->state_Now=STATE_IDLE;
	cur_Window->current_Serve_Time=0;
	cur_Window->plan_Serve_Time=0;
	cur_Window->current_Rest_Time=0;
	cur_Window->plan_Rest_Time=0;
	cur_Window->current_Number=0;
	cur_Window->current_Wait_Time=0;
	cur_Window->plan_Wait_Time=0;
}
void state_To_Waiting(WIN_PTR cur_Window)
{
	cur_Window->state_Now=STATE_WAITING;
}
void state_To_Working(WIN_PTR cur_Window)
{
	cur_Window->state_Now=STATE_WORKING;
}
void state_To_Rest(WIN_PTR cur_Window)
{
	cur_Window->state_Now=STATE_REST;
}

int is_All_Close(void)
{
	for(int i=0;i<=MAXWIN-1;i++)
	{
		if(windows[i]->state_Now!=STATE_CLOSE)
		{
			return 0;
		}
	}
	return 1;
}
int is_All_Rest(void)
{
	for(int i=0;i<=MAXWIN-1;i++)
	{
		if(windows[i]->state_Now!=STATE_REST)
		{
			return 0;
		}
	}
	return 1;
}

