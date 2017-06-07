#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;
const int MAX=100;

//data struct
typedef struct treeNode{
	treeNode *rc,*lc;
	char data;
}treeNode, * BiTree;

typedef char LDR,DLR;

typedef struct QUEUE{
	treeNode **front,**tail;
}QUEUE;

typedef struct STACK{
	treeNode **base,**top;
}STACK;

//stack

void initStack(STACK &S)
{
	S.base=NULL;
	S.top=NULL;
}

bool createStack(STACK &S,int n)
{
	if(S.base=(treeNode**)malloc(n*sizeof(treeNode*)) )
	{
		S.top=S.base;
		return 1;
	}
	else
	{
		cout<<"Create Stack failed."<<endl;
		return 0;
	}
}

void push(STACK &S,treeNode* temp)
{
	*S.top=temp;
	S.top++;
}

bool pop(STACK &S,treeNode* &temp)
{
	if(S.top==S.base)
	{
		cout<<"Error:The Stack is empty."<<endl;
		return 0;
	}
	S.top--;
	temp=*S.top;
	return 1;
}

bool emptyStack(STACK &S)
{
	if(S.top==S.base) return 1;
	return 0;
}

bool getStackTop(STACK &S,treeNode* &temp)
{
	if(!emptyStack(S))
	{
		S.top--;
		temp=*S.top;
		S.top++;
		return 1;
	}
	else
	{
		cout<<"Error:The Stack is empty."<<endl;
		return 0;
	}
}

bool isVisited(STACK &RUB,treeNode* temp)
{//Check if the node is visited to find the path
	treeNode** sec=RUB.base;
	while(sec!=RUB.top)
	{
		if(*sec==temp) return 1;
		sec++;
	}
	return 0;
}

bool printStack(STACK &S)
{
	if(emptyStack(S)||*S.base==NULL)
	{
		cout<<"Error:Can not print an empty OR a null_tree stack."<<endl;
		return 0;
	} 
	else
	{
		treeNode **temp=S.base;
		while(temp!=S.top)
		{
			cout<<(*temp)->data;
			temp++;
		}
		cout<<endl;
	}
	return 1;
}

//Queue

void initQueue(QUEUE &Q)
{
	Q.front=NULL;
	Q.tail=NULL;
}

bool createQueue(QUEUE &Q,int n)
{
	if(Q.front=(treeNode**)malloc(n*sizeof(treeNode*)) )
	{
		Q.tail=Q.front;
		return 1;
	}
	else
	{
		cout<<"Error:Create Queue failed."<<endl;
		return 0;
	}
}


bool emptyQueue(QUEUE &Q)
{
	if(Q.front==Q.tail) return 1;
	return 0;
}

void inQueue(QUEUE &Q,treeNode* temp)
{
	*Q.tail=temp;
	Q.tail++;
}

bool deQueue(QUEUE &Q,treeNode* &temp)
{
	if(emptyQueue(Q))
	{
		cout<<"Error:Empty Queue."<<endl;
		return 0;
	}
	else
	{
		temp=*Q.front;
		Q.front++;
		return 1;
	}
}

//BiTree
void initBiTree(BiTree &T)
{
	T=NULL;	
}

bool createBiTree(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
	{
		T=NULL;
	}
	else
	{
		T=(treeNode*)malloc(sizeof(treeNode));
		T->data=ch;
		createBiTree(T->lc);
		createBiTree(T->rc);
	}
	return 1;
}

bool blank(int x)
{
	if(x<0) return 0;
	else for(int i=1;i<=x;i++) printf("  ");
	return 1;
}

bool printBiTree(BiTree &T,int depth)
{//the order is RDL
	if(T)
	{
		printBiTree(T->rc,depth+1);
		if( !( depth<0 ) )
		{
			blank(depth);//use blanks to represent the depth(x positon)
			cout<<T->data<<endl;//use endl(enter) to represent the y position
		}
		else return 0;
		printBiTree(T->lc,depth+1);
	}
	return 1;
}

int findRoot(char s[MAX],char root)
{
	char* ps=s;
	for(int i=0;i<=strlen(s)-1;i++)
	{
		if(s[i]==root) return i;
	}
	return -1;
}

bool createBiTree_DLR_LDR(BiTree &T,DLR dlr[MAX],LDR ldr[MAX])
{
	int num;
	DLR lc_dlr[MAX],rc_dlr[MAX];
	LDR lc_ldr[MAX],rc_ldr[MAX];
	if(!dlr[0])
	{
		T=NULL;
	}
	else
	{
		T=(treeNode*)malloc(sizeof(treeNode));
		T->data=dlr[0];
		num=findRoot(ldr,dlr[0]);
		cout<<T->data<<":"<<num<<" ";
		if(strlen(dlr)==1 && num==0)
		{
			T->lc=NULL;
			T->rc=NULL;
		}
		else if( num==0 )
		{
			T->lc=NULL;
			strcpy(rc_ldr,&ldr[num+1]);
			strcpy(rc_dlr,&dlr[num+1]);
			createBiTree_DLR_LDR(T->rc,rc_dlr,rc_ldr);
		}
		else if( num==strlen(dlr)-1 )
		{
			T->rc=NULL;
			strncpy(lc_ldr,ldr,num);
			strncpy(lc_dlr,&dlr[1],num);
			createBiTree_DLR_LDR(T->lc,lc_dlr,lc_ldr);
		}
		else if(num>0)
		{
			strncpy(lc_ldr,ldr,num);
			strncpy(lc_dlr,&dlr[1],num);
			strcpy(rc_ldr,&ldr[num+1]);
			strcpy(rc_dlr,&dlr[num+1]);
			createBiTree_DLR_LDR(T->lc,lc_dlr,lc_ldr);
			createBiTree_DLR_LDR(T->rc,rc_dlr,rc_ldr);
		}
		else return 0;
	 }
	return 1;
}

bool LRDTraverse(BiTree &T)
{
	if(T)
	{
		LRDTraverse(T->lc);
		LRDTraverse(T->rc);
		cout<<T->data;
	}
	return 1;
}

bool levelTraverse(BiTree &T)
{
	QUEUE Q;
	initQueue(Q);
	createQueue(Q,100);
	treeNode* temp;
	inQueue(Q,T);
	while(!emptyQueue(Q) && *Q.front!=NULL)
	{
		deQueue(Q,temp);//visit the node
		cout<<temp->data;
		if(temp->lc) inQueue(Q,temp->lc);
		if(temp->rc) inQueue(Q,temp->rc);
	}
	return 1;
}

bool searchNode(BiTree &T,char ch)
{
	STACK s,rub;//s to save the path,rub to save the unable nodes
	treeNode *temp_s,*temp_rub;
	initStack(s);
	initStack(rub);
	createStack(s,100);
	createStack(rub,100);
	push(s,T);
	getStackTop(s,temp_s);
	while(!emptyStack(s) && *s.base!=NULL && temp_s->data!=ch )
	{
		if(temp_s->lc && !isVisited(rub,temp_s->lc))
		{
			push(s,temp_s->lc);//save the left child
		}
		else if(temp_s->rc && !isVisited(rub,temp_s->rc))
		{
			push(s,temp_s->rc);//save the right child
		}
		else
		{
			pop(s,temp_rub);//nothing to save
			push(rub,temp_rub);//go back
		}
		getStackTop(s,temp_s);
	}
	if(emptyStack(s))
	{
		cout<<"Searching failed.The node doesn't exist."<<endl;
		return 0;
	}
	else printStack(s);
	return 1;
}

 int main(void)
 {
 	char ch;
 	DLR dlr[MAX]="";//ABDEFCGH DEBFACHG
 	LDR ldr[MAX]="";//
 	BiTree T;
 	initBiTree(T);
 	back:
 	cout<<"Input the DLR & LDR to create a BiTree:"<<endl;
 	cout<<"Input the DLR:"<<endl;
 	gets(dlr);
 	cout<<"Input the LDR:"<<endl;
 	gets(ldr);
 	if(strlen(dlr)==strlen(ldr)) 
	createBiTree_DLR_LDR(T,dlr,ldr);
	else
	{
		cout<<"Error: The length of DLR != LDR "<<endl;
		goto back;
	}
	cout<<endl;
 	cout<<"Display the BiTree:"<<endl;
 	printBiTree(T,0);
 	cout<<"LRD:"<<endl;
 	LRDTraverse(T);
 	cout<<endl;
 	cout<<"Level Traverse:"<<endl;
 	levelTraverse(T);
 	cout<<endl;
 	cout<<"Input the node u want to search:"<<endl;
 	cin>>ch;
 	cout<<"The result is:"<<endl;
 	searchNode(T,ch);
 	return 0;
 }
