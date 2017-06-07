#include<stdio.h>
#include<stdlib.h>

struct listNode{
	int data;
	struct listNode* nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE* LISTNODEPTR;
typedef LISTNODEPTR POSITION;
typedef LISTNODEPTR LIST;

LIST cFIFOList(void)
{
	int num;
	LIST L;
	POSITION curPtr,prvPtr;
	
	L=malloc(sizeof(LISTNODE));
	L->nextPtr=NULL;
	prvPtr=L;
	
	scanf("%d",&num);
	while(num!=-1)
	{
		curPtr=malloc(sizeof(LISTNODE));
		if(curPtr!=NULL)
		{
			curPtr->data=num;
			prvPtr->nextPtr=curPtr;
			prvPtr=curPtr;
			curPtr->nextPtr=NULL;
		}
		else
		{
			printf("Error!The memory is full.");
		}
		scanf("%d",&num);
	}
	return L;
}

void printList(LIST L)
{
	POSITION P;
	
	P=L->nextPtr;
	if(L->nextPtr==NULL)
	{
		printf("There is no item in the list.\n");
	}
	else
	{
		while(P!=NULL)
		{
			printf(P->nextPtr==NULL?"%d\n":"%d ",P->data);
			P=P->nextPtr;
		}
	}
}

void deleteAllElement(LIST L,int x)
{
	POSITION P,prvPtr,Tmp;
	
	P=L->nextPtr;
	prvPtr=L;
	
	while(P!=NULL)
	{
		if(P->data==x)
		{
			Tmp=P;
			prvPtr->nextPtr=P->nextPtr;
			P=P->nextPtr;
			free(Tmp);
		}
		else
		{
			P=P->nextPtr;
			prvPtr=prvPtr->nextPtr;
		}
	}
}

void deleteList(LIST L)
{
	POSITION P,Tmp;
	
	P=L->nextPtr;
	L->nextPtr=NULL;
	
	Tmp=P;
	while(P!=NULL)
	{
		P=P->nextPtr;
		free(Tmp);
		Tmp=P;
	}
}

int main(void)
{
	LIST L;
	int x;
	
	printf("Plsea input a series of integers:");
	L=cFIFOList();
	printf("The list is:");
	printList(L);
	printf("Please input an integer you want to delete:");
	scanf("%d",&x);
	deleteAllElement(L,x);
	printf("The new list is:");
	printList(L);
	
	return 0;
}
