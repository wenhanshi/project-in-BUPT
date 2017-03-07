#include<stdio.h>
#include<stdlib.h>
#include"alltype and alldefine.h"
#include"print_Message.h"

void file_Output(void)
{
	if((file_Output_P=fopen("Output.txt","at+"))==NULL)
	{
		printf("The file could not be opened.\n");
	}
	else
	{
		fprintf(file_Output_P,"T=<%d>\n",Time);
		for(int i=0;i<=MAXWIN-1;i++)
		{
			fprintf(file_Output_P,"WINDOW No.%d :",i);
			fprintf(file_Output_P,"STATE:%8s  ",ctos_PrintState(windows[i]->state_Now));
			fprintf(file_Output_P,"CURRENT NUMBER:%s  ",itos_Client(windows[i]->current_Number));
			fprintf(file_Output_P,"SERVE:%3d/%3d  ",windows[i]->current_Serve_Time,windows[i]->plan_Serve_Time);
			fprintf(file_Output_P,"REST:%3d/%3d  ",windows[i]->current_Rest_Time,windows[i]->plan_Rest_Time);
			fprintf(file_Output_P,"QUIT:%c",windows[i]->quit);
			fprintf(file_Output_P,"\n");
			printf("WINDOW No.%d : ",i);
			printf("STATE:%8s  ",ctos_PrintState(windows[i]->state_Now));
			printf("NUMBER:%s  ",itos_Client(windows[i]->current_Number));
			printf("SERVE:%2d/%2d  ",windows[i]->current_Serve_Time,windows[i]->plan_Serve_Time);
			printf("REST:%2d/%2d  ",windows[i]->current_Rest_Time,windows[i]->plan_Rest_Time);
			printf("QUIT:%c",windows[i]->quit);
			printf("\n");
		}
		fprintf(file_Output_P,"Current Normal Clients in queue:%d\n",cur_Norm_Num);
		fprintf(file_Output_P,"Current Max Normal Clients NUMBER in the BANK:%s\n",itos_Client(norm_Num-1));
		fprintf(file_Output_P,"Current VIP Clients in queue:%d\n",cur_VIP_Num);
		fprintf(file_Output_P,"Current Max VIP Clients NUMBER in the BANK:%s\n\n",vip_Num+1?itos_Client(vip_Num+1):"V00");
		PRINT_SEPARATOR;
		print_Normal_List();
		print_VIP_List();
		print_Rest_List();
		printf("Current Normal Clients in queue:%d\n",cur_Norm_Num);
		printf("Current VIP Clients in queue:%d\n",cur_VIP_Num);
		printf("Current Opened Normal Windows:%d\n",open_Norm_Num);
		printf("Current Opened VIP Windows:%d\n",open_VIP_Num);
		printf("The time of <%d> message has been printed.\n\n",Time);
	}
	
	fclose(file_Output_P);
	return;
}


void print_Normal_List()                  //打印链表中的数据 
{
	NORM_PTR temp_Norm_P=NULL;
	temp_Norm_P=head_Norm_P->nextPtr;
	printf("The normal client queue:\n");
	while(temp_Norm_P!=NULL)
	{
		printf("%s-->",itos_Client(temp_Norm_P->client_Norm_Num));
		temp_Norm_P=temp_Norm_P->nextPtr;
	}
	printf("NULL\n");
}
void print_VIP_List()                  //打印链表中的数据 
{
	VIP_PTR temp_VIP_P=NULL;
	temp_VIP_P=head_VIP_P->nextPtr;
	printf("The VIP client queue:\n");
	while(temp_VIP_P!=NULL)
	{
		printf("%s-->",itos_Client(temp_VIP_P->client_VIP_Num));//need to change
		temp_VIP_P=temp_VIP_P->nextPtr;
	}
	printf("NULL\n");
}
void print_Rest_List(void)                  //打印链表中的数据 
{
	REST_PTR temp_Rest_P=NULL;
	temp_Rest_P=head_Rest_P->nextPtr;
	printf("The Waiting-for-rest windows queue:\n");
	while(temp_Rest_P!=NULL)
	{
		printf("WIN%d-->",temp_Rest_P->window_Num);
		temp_Rest_P=temp_Rest_P->nextPtr;
	}
	printf("NULL\n");
}

char* itos_Client(int client_Num)
{
	if(client_Num>=0)
	{
		for(int i=2;i>=0;i--)
		{
			string_Print[i]=client_Num%10+48;
			client_Num=(client_Num-(client_Num%10))/10;
		}
		string_Print[BIT]='\0';
		return string_Print;
	}
	else
	{
		client_Num=-client_Num;
		string_Print[0]='V';
		string_Print[2]=client_Num%10+48;
		if(client_Num<10)
		{
			string_Print[1]='0';
		}
		else
		{
			string_Print[1]=client_Num/10+48;
		}
		string_Print[BIT]='\0';
		return string_Print;
	}
}

char* ctos_PrintState(char state)
{
	switch(state)
	{
		case STATE_IDLE:
			return "IDLE";
		case STATE_WORKING:
			return "WORKING";
		case STATE_WAITING:
			return "WAITING";
		case STATE_REST:
			return "REST";
		case STATE_CLOSE:
			return "CLOSE";
		default:
			return "ERROR";
	}
}

