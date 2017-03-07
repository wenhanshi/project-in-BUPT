#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"alltype and alldefine.h"
#include"data_Maintenance.h"

extern INFOR_PTR head_Infor_P;
extern INFOR_PTR cur_Infor_P;
extern FILE* fPtr;
extern int VIP_sum;
void data_Maintenance(void)
{
	int temp=1;
    printf("Please enter your choice\n");
    while(temp==1)
    {
    	temp=enter_Choice();
	}
}
void save_Information(void)              
{
    INFOR_PTR temp_Infor_P;
    temp_Infor_P=head_Infor_P->nextPtr;
    if((fPtr=fopen("data.dat","wb"))==NULL)
    {
    	printf("File could not be opened.\n");
	}
    else
    {
        while(temp_Infor_P!=NULL)
        {
        	fseek(fPtr,0,1);
        	fwrite(temp_Infor_P,sizeof(INFOR),1,fPtr);
        	temp_Infor_P=temp_Infor_P->nextPtr;
		}
    }
    fclose(fPtr);
}
int enter_Choice(void)                        //选择菜单函数 
{
	char choice[3];
    printf("\nEnter your choice\n"
    	   "'V+'-Add a VIP client \n"
           "'V/'-Modify a VIP client's information\n"
           "'V-'-Delete a VIP client\n"
           "'V*'-Search a VIP client's information\n"
		   "'E'-Exit\n");
    scanf("%s",choice);
    getchar();
    if(strcmp(choice,"V+")==0)
    {
    	add_Information();
		print_Information();
		return 1;
	}
    else 
    {
		if(strcmp(choice,"V/")==0)
		{
			modify_Information();
			print_Information();
			return 1;
		}
		else
		{
			if(strcmp(choice,"V-")==0)
			{
				delete_Information();
				print_Information();
				return 1;
			}
			else
			{
				if(strcmp(choice,"V*")==0)
				{
					search_Information();
					return 1;
				}
				else
				{
					if(strcmp(choice,"E")==0)
					{
						return 0;
					}
					else
					{
						printf("misinput");
						return 1;
					}
					
				}
			}	
		}	
	}	
}
void add_Information(void)
{
	INFOR_PTR new_Infor_P;
	new_Infor_P=(INFOR_PTR)malloc(sizeof(INFOR));
	printf("Please input the VIP clients' information in this way:\n"
		      "Tom //name\n"
			  "12345 //ID\n"
			  "1000  //account balance\n");
	scanf("%s\n%s\n%lld",new_Infor_P->VIP_Name,
	   	                 new_Infor_P->VIP_Number,
						 &new_Infor_P->balance_Account);
	new_Infor_P->nextPtr=NULL;
	cur_Infor_P->nextPtr=new_Infor_P;
	cur_Infor_P=cur_Infor_P->nextPtr;
	save_Information();
    VIP_sum++;	
}
void modify_Information(void)                           
{
	INFOR_PTR temp_Infor_P;
	int choice,flag=0;
	char number[20];
	temp_Infor_P=head_Infor_P->nextPtr;
	if((fPtr=fopen("data.dat","ab"))==NULL)
        printf("File could not be opened.\n");
    else
    {
    	printf("\nEnter your choice\n"
	       "1-Modify the VIP client's name\n"
		   "2-Modify the VIP client's number\n"
		   "3-Modify the VIP client's balance account\n"
		   "4-Exit\n");
		scanf("%d",&choice);
		if((choice==1)||(choice==2)||(choice==3))
		{
			printf("Please write down the ID of the client.\n");
			scanf("%s",number);
		}
		else
		{
			flag=1;
		}
		while(temp_Infor_P!=NULL&&flag==0)
		{
			fseek(fPtr,0,1);
			fread(temp_Infor_P,sizeof(INFOR),1,fPtr);
			if(strcmp(temp_Infor_P->VIP_Number,number)==0)
			{
				switch(choice)
  				{
   					case 1:
	    				printf("Please write down the name.\n");
		 				scanf("%s",temp_Infor_P->VIP_Name);
		 				flag=1;
		   				break;
					case 2:
  						printf("Please write down the number.\n");
			   			scanf("%s",temp_Infor_P->VIP_Number);
			   			flag=1;
			   			break;
					case 3:
  						printf("Please write down the balance account.\n");
		   				scanf("%lld",&temp_Infor_P->balance_Account);
		   				flag=1;
			   			break;
					default:
						flag=1;
						break;	
  				}
			}
			temp_Infor_P=temp_Infor_P->nextPtr;	
   	 	}
	}	
	if(flag==0)
	{
		printf("You've put the wrong ID\n");	
	}
	save_Information();
}
void search_Information(void)
{
	INFOR_PTR temp_Infor_P;
	int flag=0;
	char num[20];
	temp_Infor_P=(INFOR_PTR)malloc(sizeof(INFOR));
	temp_Infor_P=head_Infor_P->nextPtr;
	printf("Please write the number of the client you want to search.\n");
	scanf("%s",num);
	while(temp_Infor_P!=NULL&&flag==0)
	{
		if(strcmp(temp_Infor_P->VIP_Number,num)==0)
		{
			printf("%s\n%s\n%lld\n",temp_Infor_P->VIP_Name,
			                        temp_Infor_P->VIP_Number,
									temp_Infor_P->balance_Account);
			flag=1;
		}
		temp_Infor_P=temp_Infor_P->nextPtr;
	}
	if(flag==0)
	{
		printf("Sorry, we haven't found this VIP's information.\n");	
	}
}
void delete_Information(void)                                 
{
	char num[20];
	int flag=0;
	INFOR_PTR temp1_Infor_P,temp2_Infor_P;
	temp1_Infor_P=(INFOR_PTR)malloc(sizeof(INFOR));
	temp2_Infor_P=(INFOR_PTR)malloc(sizeof(INFOR));
	temp1_Infor_P=head_Infor_P->nextPtr;
	temp2_Infor_P=temp1_Infor_P;
	printf("Please write the number of the client you want to delete.\n");
	scanf("%s",num);
	while(temp1_Infor_P!=NULL&&flag==0)
	{
		if(strcmp(temp1_Infor_P->VIP_Number,num)==0)
		{
			if(temp2_Infor_P==temp1_Infor_P)//头结点 
			{
				head_Infor_P->nextPtr=temp1_Infor_P->nextPtr;
				free(temp1_Infor_P);
				flag=1;
			}
			else 
			{
				if(temp1_Infor_P->nextPtr==NULL)//尾节点 
				{
					temp2_Infor_P->nextPtr=NULL;
					cur_Infor_P=temp2_Infor_P;
					free(temp1_Infor_P);
					flag=1;
				}
				else
				{
					temp2_Infor_P->nextPtr=temp1_Infor_P->nextPtr;
					free(temp1_Infor_P);
					flag=1;
				}	
			}	
		}
		else
		{
			temp2_Infor_P=temp1_Infor_P;
			temp1_Infor_P=temp1_Infor_P->nextPtr;
		}
	}
	if(flag==0)
	{
		printf("ERROR\n");	
	}
	save_Information();
}
void print_Information(void)                                
{
	INFOR_PTR temp_Infor_P;
	temp_Infor_P=head_Infor_P->nextPtr;
	if((fPtr=fopen("data.dat","rb"))==NULL)
	    printf("File could not be opened");
    else
    {
    	while(temp_Infor_P!=NULL)
    	{
    		fseek(fPtr,0,1);
	    	fread(temp_Infor_P,sizeof(INFOR),1,fPtr);
	    	printf("%s\n%s\n%lld\n",temp_Infor_P->VIP_Name,
			                        temp_Infor_P->VIP_Number,
									temp_Infor_P->balance_Account);
	    	temp_Infor_P=temp_Infor_P->nextPtr;
	    }
    	fclose(fPtr);
    }
}

void initialize_Information(void)
{
	INFOR_PTR new_Infor_P;
	int number;
	head_Infor_P=(INFOR_PTR)malloc(sizeof(INFOR));
	head_Infor_P->nextPtr=NULL;
	head_Infor_P->VIP_Name[10]='0';
	head_Infor_P->VIP_Number[20]='0';
	head_Infor_P->balance_Account=0;
	cur_Infor_P=head_Infor_P;
		printf("Please input the number of the VIP clients:\n");
		scanf("%d",&number);
		getchar();
		printf("Please input the VIP clients' information in this way:\n"
		      "Tom //name\n"
			  "12345 //ID\n"
			  "1000  //account balance\n");
    	for(int i=0;i<number;i++)
    	{
    		printf("The No.%d VIP information:\n",i+1);
			new_Infor_P=(INFOR_PTR)malloc(sizeof(INFOR));
			scanf("%s\n%s\n%lld",new_Infor_P->VIP_Name,
		    	                 new_Infor_P->VIP_Number,
								 &new_Infor_P->balance_Account);
			new_Infor_P->nextPtr=NULL;
			cur_Infor_P->nextPtr=new_Infor_P;
			cur_Infor_P=cur_Infor_P->nextPtr;
		}
    VIP_sum=number;
	save_Information();
	print_Information();
}
