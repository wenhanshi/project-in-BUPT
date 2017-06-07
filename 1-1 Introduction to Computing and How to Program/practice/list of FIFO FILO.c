#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct listNode{
	char data;
	struct listNode* nextPtr;
};

typedef struct listNode LISTNODE; 
typedef LISTNODE* LISTNODEPTR;
typedef LISTNODEPTR POSITION;
typedef LISTNODEPTR LIST;

LISTNODEPTR Choice(int);
void printContents(void);
LISTNODEPTR cFIFOList(void);
LISTNODEPTR cFILOList(void);
int isEmpty(LISTNODEPTR);
void printListNode(LISTNODEPTR);
LISTNODEPTR Insert(LIST,POSITION,char);
LISTNODEPTR Find(LIST,char);

int main(void)
{
	int choice;
	LIST L;
	char ch;
	
	printContents();
	scanf("%d",&choice);
	L=Choice(choice);
	scanf("%c",&ch);
	printf("%c\n",Find(L,ch)->data);
	
	return 0;
}

void printContents(void)
{
	printf("WELCOME TO THE LIST WORLD Presented by SHI\nWhat's your instruction?\n");
	printf("1---Creat a FIFOList,then print it.\n");
	printf("2---Creat a FILOList,then print it.\n");
	printf("3---Insert your char_x into the position P,then print it.\n");
}

LIST Choice(int choice)
{
	LIST HEADER;
	switch(choice)
	{
		case 1:
			{
				printf("Let's input your data ending with EOF.\n");
				HEADER=cFIFOList();
				printListNode(HEADER);
				break;
			}
		case 2:
			{
				printf("Let's input your data ending with EOF.\n");
				HEADER=cFILOList();
				printListNode(HEADER);
				break;
			}
		default:
			{
				printf("Error:The unkonw instruction,try again.\n");
				scanf("%c",&choice);
				Choice(choice);
				break;
			}
	}
	return HEADER;
}
int isEmpty(LISTNODEPTR L)
{
	if(L==NULL)
	{
		return 1;
	}
	return 0;
}

void printListNode(LISTNODEPTR L)
{
	LISTNODEPTR curPtr;
	
	if(isEmpty(L)==1)
	{
		printf("The list is empty,it can't be printed.");
	}
	else
	{
		printf("The printing result is:\n");
		curPtr=L;
		while(curPtr->nextPtr!=NULL)
		{
			printf("%c-->",curPtr->data);
			curPtr=curPtr->nextPtr;
		}
		printf("%c\n",curPtr->data);
	}
}

LISTNODEPTR cFIFOList(void)
{
	char c;
	LISTNODEPTR header=NULL,curPtr,prvPtr;
	
	while((c=getchar())!=EOF)
	{
		if(isspace(c))
		{
			continue;
		}
		curPtr=malloc(sizeof(LISTNODE));
		if(curPtr!=NULL)
		{
			curPtr->data=c;
			if(isEmpty(header)==1)
			{
				header=curPtr;
				prvPtr=header;
			}
			else
			{
				prvPtr->nextPtr=curPtr;
				prvPtr=curPtr;
			}
			//for print the empty,put it to the front.
			curPtr->nextPtr=NULL;
		}
		else
		{
			printf("Error:The memory is full!");
		}
	}
	return header;
}

LISTNODEPTR cFILOList(void)
{
	char c;
	LISTNODEPTR header=NULL,curPtr;
	
	while((c=getchar())!=EOF)
	{
		if(isspace(c))
		{
			continue;
		}
		curPtr=malloc(sizeof(LISTNODE));
		if(curPtr!=NULL)
		{
			curPtr->data=c;
			if(isEmpty(header)==1)
			{
				header=curPtr;
				header->nextPtr=NULL;
			}
			else
			{
				curPtr->nextPtr=header;
				header=curPtr;
			}
		}
		else
		{
			printf("Erorr:The memory is full!");
		}
	}	
	return header;
}

LISTNODEPTR Insert(LIST L,POSITION P,char x)
{
	LISTNODEPTR curPtr;

	curPtr=malloc(sizeof(LISTNODE));
	if(curPtr!=NULL)
	{
		curPtr->data=x;
		curPtr->nextPtr=P->nextPtr;
		P->nextPtr=curPtr;
	}
	else
	{
		printf("Error:The memory is full!");
	}
	return curPtr;
}

LISTNODEPTR Find(LIST L,char x)
{
	POSITION P;
	
	P=L;
	while(P!=NULL)
	{
		if(P->data==x)
		{
			return P;
		}
		P=P->nextPtr;
	}
	return P;
}
