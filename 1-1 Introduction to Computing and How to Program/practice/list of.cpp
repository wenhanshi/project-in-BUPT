#include<stdio.h>
#include<stdlib.h>

struct listNode{
	char data;
	struct listNode* nextPtr;
};

typedef struct listNode LISTNODE; 
typedef LISTNODE* LISTNODEPTR; 

LISTNODEPTR cFIFOList(void);
int isEmpty(LISTNODEPTR);
void printListNode(LISTNODEPTR);

int main(void)
{
	LISTNODEPTR HEADER;
	
	HEADER=cFIFOList();
	printListNode(HEADER);
	return 0;
}

int isEmpty(LISTNODEPTR L)
{
	if(!L->nextPtr)
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
		while(curPtr!=NULL)
		{
			printf("%c-->",curPtr->data);
			curPtr=curPtr->nextPtr;
		}
	}
}

LISTNODEPTR cFIFOList(void)
{
	char c;
	LISTNODEPTR header=NULL,curPtr,prvPtr;
	
	while((c=getchar())!=EOF)
	{
		curPtr=malloc(sizeof(LISTNODE));
		if(curPtr!=NULL)
		{
			curPtr->data=c;
			if(isEmpty==1)
			{
				header=curPtr;
				prvPtr=header;
			}
			else
			{
				prvPtr->nextPtr=curPtr;
				prvPtr=curPtr;
			}
		}
		else
		{
			printf("Erorr:The memory is full!");
		}
	}
	curPtr->next=NULL;
}
