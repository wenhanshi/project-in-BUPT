#include<stdio.h>
#include<stdlib.h>

struct polyNode{
	float coef;
	int expo;
	struct polyNode* nextPtr;
};
typedef struct polyNode POLY;
typedef POLY* pPOLY;

void createPoly(pPOLY &P,int n);
void deletePoly(pPOLY &P);
void printPoly(pPOLY P); 
void addPoly(pPOLY &pa,pPOLY &pb);
void mulPoly(pPOLY &pa,pPOLY &pb);
void insertNodePre(pPOLY &P,pPOLY curP,pPOLY newP);
void delNode(pPOLY &P,pPOLY curP);
pPOLY getPre(pPOLY P,pPOLY curP);
void connectList(pPOLY &pa,pPOLY head);
 pPOLY copy(pPOLY P);



int main(void)
{
	int n,m;
	
	printf("Create pa,\nInput the number of items:\n");
	pPOLY pa,pb,pc;
	scanf("%d",&m);
	createPoly(pa,m);
	printPoly(pa);
	pc=copy(pa);
	printPoly(pc);
	printf("Create pb,\nInput the number of items:\n");
	scanf("%d",&n);
	createPoly(pb,n);
	printPoly(pb);
	addPoly(pa,pb);
	//mulPoly(pa,pb);
	printPoly(pa);
	//deletePoly(pa);
	return 0;
}

void createPoly(pPOLY &P,int n)
{
	P=(pPOLY)malloc(sizeof(POLY));
	P->coef=0.0;
	P->expo=0;
	P->nextPtr=NULL;
	
	pPOLY curP=P;
	for(int i=1;i<=n;i++)
	{
		curP->nextPtr=(pPOLY)malloc(sizeof(POLY));
		curP=curP->nextPtr;
		scanf("%f %d",&curP->coef,&curP->expo);
		curP->nextPtr=NULL;
	}
}
void deletePoly(pPOLY &P)
{
	pPOLY curP,tempP;
	curP=P->nextPtr;
	while(curP)
	{
		tempP=curP;
		free(tempP);
		curP=curP->nextPtr;
	}
}
void printPoly(pPOLY P)
{
	pPOLY curP;
	curP=P->nextPtr;
	while(curP)
	{
		printf("[%.2fx^%d]>>",curP->coef,curP->expo);
		curP=curP->nextPtr;
	}
	printf("NULL\n");
}
void addPoly(pPOLY &pa,pPOLY &pb)
{
	pPOLY curPa=pa->nextPtr;
	pPOLY curPb=pb->nextPtr;
	pPOLY newP;
	while(curPa&&curPb)
	{
		if(curPa->expo<curPb->expo)
		{
			curPa=curPa->nextPtr;
		}
		else if(curPa->expo>curPb->expo)
		{
			newP=(pPOLY)malloc(sizeof(POLY));
			newP->coef=curPb->coef;
			newP->expo=curPb->expo;
			insertNodePre(pa,curPa,newP);
			curPb=curPb->nextPtr;
		}
		else
		{
			if(curPa->coef+curPb->coef==0.0)
			{
				delNode(pa,curPa);
				curPb=curPb->nextPtr;
			}
			else
			{
				curPa->coef+=curPb->coef;
				curPa=curPa->nextPtr;
				curPb=curPb->nextPtr;
			}
		}
	}
	if(curPb!=NULL)
	{
		connectList(pa,curPb);
	}
}

void connectList(pPOLY &pa,pPOLY head)
{
	pPOLY tail=pa;
	while(tail->nextPtr!=NULL)
	{
		tail=tail->nextPtr;
	}
	tail->nextPtr=head;
}
 
 void insertNodePre(pPOLY &P,pPOLY curP,pPOLY newP)
 {
 	pPOLY preP=getPre(P,curP);
 	preP->nextPtr=newP;
 	newP->nextPtr=curP;
 }
 
 void delNode(pPOLY &P,pPOLY curP)
 {
 	pPOLY tempP=curP,preP=getPre(P,curP);
 	curP=curP->nextPtr;
 	preP->nextPtr=curP;
 	free(tempP);
 }
 
 pPOLY getPre(pPOLY P,pPOLY curP)
 {
 	pPOLY preP=P;
 	while(preP->nextPtr!=curP)
 	{
 		preP=preP->nextPtr;
	}
	return preP;
 }
  
 pPOLY copy(pPOLY P)
 {
 	pPOLY newP,curP,curnewP;
 	newP=(pPOLY)malloc(sizeof(POLY));
 	
 	curP=P->nextPtr;
 	while(!curP)
 	{
 		curnewP->nextPtr=(pPOLY)malloc(sizeof(POLY));
 		curnewP=curnewP->nextPtr;
 		curnewP->coef=curP->coef;
 		curnewP->expo=curP->expo;
 		curP=curP->nextPtr;
	 }
	 curnewP=NULL;
	 return newP;
 }
 
 void mulPoly(pPOLY &pa,pPOLY &pb,int m,int n)
{
	pPOLY aPOLY[100];//n
	pPOLY curPb=pb->nextPtr,curPa;
	for(int i=0;i<=n-1;i++)
	{
		aPOLY[n]=copy(pa);
		curPa=aPOLY[n]->nextPtr;
		while(!aPOLY[n])
		{
			curPa->coef*=curPb->coef;
			curPa->expo+=curPb->coef;
			curPa=curPa->nextPtr;
		}
		curPb=curPb->nextPtr;
	}
	for(int i=1;i<=n-1;i++)
	{
		addPoly(pa,aPOLY[i]);
	}
}
 
 
