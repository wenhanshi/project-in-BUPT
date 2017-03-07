#include<stdio.h>
#include<stdlib.h>
#include"alltype and alldefine.h"
#include"alloc_Num.h"

void alloc_Num_Orient(void)
{
	NORM_PTR temp_Norm_P=NULL;//to delete the block
	VIP_PTR temp_VIP_P=NULL;
	for(int i=0;i<=MAXWIN-1;i++)  //遍历窗口 
	{
		if(windows[i]->state_Now==STATE_IDLE) 
		{
			if(IS_NORM_WIN&&head_Norm_P->nextPtr!=NULL)         //空闲的为普通窗口 
			{
				windows[i]->current_Number=head_Norm_P->nextPtr->client_Norm_Num;
				temp_Norm_P=head_Norm_P->nextPtr;
				if(head_Norm_P->nextPtr==cur_Norm_P)//如果 cur同时是首尾 
				{
					cur_Norm_P=head_Norm_P;//指针回归 
				}
				head_Norm_P->nextPtr=temp_Norm_P->nextPtr;
				free(temp_Norm_P);
				temp_Norm_P=NULL;
				cur_Norm_Num--;
			}
			else if(IS_VIP_WIN&&head_VIP_P->nextPtr!=NULL)            //空闲的为VIP窗口 
			{
				windows[i]->current_Number=head_VIP_P->nextPtr->client_VIP_Num;
				temp_VIP_P=head_VIP_P->nextPtr;
				if(head_VIP_P->nextPtr==cur_VIP_P)//如果 cur同时是首尾 
				{
					cur_VIP_P=head_VIP_P;//指针回归 
				}
				head_VIP_P->nextPtr=temp_VIP_P->nextPtr;
				free(temp_VIP_P);
				temp_VIP_P=NULL;
				cur_VIP_Num--;
			}
			else
			{
				;
			}
		}
		else
		{
			;
		}
	}
}

void alloc_Num_BTW(void)
{
	NORM_PTR temp_Norm_P=NULL;//to delete the block
	VIP_PTR temp_VIP_P=NULL;
	for(int i=0;i<=MAXWIN-1;i++)  //遍历窗口 
	{
		if(windows[i]->state_Now==STATE_IDLE)
		{
			if(head_VIP_P->nextPtr==NULL&&head_Norm_P->nextPtr!=NULL)    
			{
				windows[i]->current_Number=head_Norm_P->nextPtr->client_Norm_Num;
				temp_Norm_P=head_Norm_P->nextPtr;
				if(head_Norm_P->nextPtr==cur_Norm_P)//如果 cur同时是首尾 
				{
					cur_Norm_P=head_Norm_P;//指针回归 
				}
				head_Norm_P->nextPtr=temp_Norm_P->nextPtr;
				free(temp_Norm_P);
				temp_Norm_P=NULL;
				cur_Norm_Num--;
			}
			else if(IS_NORM_WIN&&head_Norm_P->nextPtr!=NULL) 
			{
				windows[i]->current_Number=head_Norm_P->nextPtr->client_Norm_Num;
				temp_Norm_P=head_Norm_P->nextPtr;
				if(head_Norm_P->nextPtr==cur_Norm_P)//如果 cur同时是首尾 
				{
					cur_Norm_P=head_Norm_P;//指针回归 
				}
				head_Norm_P->nextPtr=temp_Norm_P->nextPtr;
				free(temp_Norm_P);
				temp_Norm_P=NULL;
				cur_Norm_Num--;
			}
			else if(IS_VIP_WIN&&head_VIP_P->nextPtr!=NULL)
			{
				windows[i]->current_Number=head_VIP_P->nextPtr->client_VIP_Num;
				temp_VIP_P=head_VIP_P->nextPtr;
				if(head_VIP_P->nextPtr==cur_VIP_P)//如果 cur同时是首尾 
				{
					cur_VIP_P=head_VIP_P;//指针回归 
				}
				head_VIP_P->nextPtr=temp_VIP_P->nextPtr;
				free(temp_VIP_P);
				temp_VIP_P=NULL;
				cur_VIP_Num--;
			}
			else
			{
				;
			}
		}
		else
		{
			;
		}
	}
}

void sort_Rest(void)
{
	REST_PTR temp_Rest_P=head_Rest_P->nextPtr->nextPtr;
	REST_PTR prv_Rest_P=head_Rest_P->nextPtr;
	REST_PTR prvprv_Rest_P=head_Rest_P;
	while(temp_Rest_P!=NULL)
	{
		if(temp_Rest_P->inqueue_Time==prv_Rest_P->inqueue_Time
		&&windows[prv_Rest_P->window_Num]->total_Rest_Time>windows[temp_Rest_P->window_Num]->total_Rest_Time)
		{
			prv_Rest_P->nextPtr=temp_Rest_P->nextPtr;
			prvprv_Rest_P->nextPtr=temp_Rest_P;
			temp_Rest_P->nextPtr=prv_Rest_P;
			prv_Rest_P=temp_Rest_P;
			temp_Rest_P=temp_Rest_P->nextPtr;
		}
		temp_Rest_P=temp_Rest_P->nextPtr;
		prv_Rest_P=prv_Rest_P->nextPtr;
		prvprv_Rest_P=prvprv_Rest_P->nextPtr;
	}
}

