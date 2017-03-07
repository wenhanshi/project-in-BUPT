#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"alltype and alldefine.h"
#include"event_Control.h"

void event_Control(char event)
{
	int temp=0,count=0;
	switch(event)
	{
		case 'G':
			add_Normal_List();
			break;
		case 'V':
			while(count!=3&&temp==0)
			{
				temp=is_VIP_Client();
				if(count!=2)
				{
					printf("Wrong ID :  %d chances remaining.\n",2-count);
				}
				count++;
			}
			if(temp==1)
			{
				printf("CORRECT ID\n");
				add_VIP_List();
			}
			else
			{
				printf("WRONG ID\n");
				add_Normal_List();
			}
			break;
		case 'R':
			printf("Input the window number from 0 to 7.\n");
			scanf("%d",&rest);
			getchar();
			add_Rest_List();
			printf("The window has added to rest.\n");
			break;
		case 'Q':
			printf("You've instructed QUIT.\n");
			printf("Please Waiting the end till the windows has finished the work(if necessary).\n");
			system("pause");
			break;
		case 'S':
			printf("Input the strategy you want.\nIns:current strategy is %d.\n",strategy);
			printf("Ins:0 rep orient.\n    1 rep BTW.\n");
			scanf("%d",&strategy);
			getchar();
			break;
		default:
			UNKNOWN;
			break;
	}
}
void add_Normal_List(void)
{
	NORM_PTR new_Norm_P;
	new_Norm_P=(NORM_PTR)malloc(sizeof(NORM));
	if(new_Norm_P==NULL)
	{
		OVERFLOW;
	}
	else
	{
		new_Norm_P->client_Norm_Num=norm_Num;
		new_Norm_P->nextPtr=NULL;
		norm_Num++;
		cur_Norm_P->nextPtr=new_Norm_P;
		new_Norm_P=NULL;
		cur_Norm_P=cur_Norm_P->nextPtr;
		cur_Norm_Num++;
	}
}
void add_VIP_List(void)
{
	VIP_PTR new_VIP_P;
	new_VIP_P=(VIP_PTR)malloc(sizeof(VIP));
	if(new_VIP_P==NULL)
	{
		OVERFLOW;
	}
	else
	{
		new_VIP_P->client_VIP_Num=vip_Num;
		new_VIP_P->nextPtr=NULL;
		vip_Num--;
		cur_VIP_P->nextPtr=new_VIP_P;
		new_VIP_P=NULL;
		cur_VIP_P=cur_VIP_P->nextPtr;
		cur_VIP_Num++;
	}
}
void add_Rest_List() 
{
	REST_PTR new_Rest_P;
	new_Rest_P=(REST_PTR)malloc(sizeof(REST));
	if(new_Rest_P==NULL)
	{
		OVERFLOW;
	}
	else
	{
		new_Rest_P->window_Num=rest;
		new_Rest_P->inqueue_Time=Time;
		new_Rest_P->nextPtr=NULL;
		cur_Rest_P->nextPtr=new_Rest_P;
		new_Rest_P=NULL;
		cur_Rest_P=cur_Rest_P->nextPtr;	
	}	
}

int is_VIP_Client(void)
{
	INFOR_PTR temp_Infor_P;
	char number[20];
	int flag=1;
	temp_Infor_P=(INFOR_PTR)malloc(sizeof(INFOR));
	temp_Infor_P=head_Infor_P->nextPtr;
	if((fPtr=fopen("data.dat","rb+"))==NULL)
    {
    	printf("File could not be opened.\n");
	}
    else
    {
    	printf("please input the VIP number:\n");
    	scanf("%s",number);
    	getchar();
		fread(temp_Infor_P,sizeof(INFOR),1,fPtr);
        while(temp_Infor_P!=NULL)
        {
			flag=strcmp(temp_Infor_P->VIP_Number,number);
			if(flag==0)
			{
				return 1;
			}
			else
			{
				fseek(fPtr,0,1);
	    		temp_Infor_P=temp_Infor_P->nextPtr;
        		fread(temp_Infor_P,sizeof(INFOR),1,fPtr);
			}
		}
		fclose(fPtr);
		return 0;
    }
}

