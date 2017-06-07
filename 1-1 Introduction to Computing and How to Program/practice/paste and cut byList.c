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

POSITION findPosition(LIST L,int x)
{
	POSITION P;
	int count=1;
	
	P=L->nextPtr;
	
	while(count!=x)
	{
		P=P->nextPtr;
		count++;
	}
	return P;
}

POSITION findPrev(LIST L,POSITION P)
{
	POSITION prvPtr;
	
	prvPtr=L;
	while(prvPtr->nextPtr!=P)
	{
		prvPtr=prvPtr->nextPtr;
	}
	return prvPtr;
}

POSITION findLater(LIST L,POSITION P)
{
	POSITION laterPtr;
	
	laterPtr=L->nextPtr->nextPtr;
	while(P->nextPtr!=laterPtr)
	{
		laterPtr=laterPtr->nextPtr;
	}
	return laterPtr;
}

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


int main(void)
{
	LIST L;
	POSITION P1,P2,Q1,Q2,Tmp1,Tmp2,Tmp3,Tmp4;
	int s1,t1,s2,t2;
	
	L=cFIFOList();
	printList(L);
	scanf("%d%d%d%d",&s1,&t1,&s2,&t2);
	
	P1=findPosition(L,s1);
	Q1=findPosition(L,t1);
	P2=findPosition(L,s2);
	Q2=findPosition(L,t2);
	Tmp1=findPrev(L,P2);
	Tmp2=findLater(L,Q2);
	Tmp3=findPrev(L,P1);
	Tmp4=findLater(L,Q1);
	
	Q1->nextPtr=P2;
	Q2->nextPtr=Tmp4;
	Tmp1->nextPtr=P1;
	Q1->nextPtr=Tmp2;
	Tmp3->nextPtr=P2;
	
	printList(L);
	
	return 0;
}
