#include<iostream>
using namespace std;

int const MAX_NODES=10;

typedef struct BSTNode{
	int lh,rh;
	int data;
	BSTNode *fa,*lc,*rc;
}BSTNode,* BSTree;

bool searchBST(BSTree &T,int x,BSTNode *&p)
{	// if x exists,return 1
 	// if T is empty, return p=NULL
	BSTNode *t=T;
	p=NULL;
	while(t)
	{
		if(t->data==x)
		return 1;
		else
		{
			p=t;
			if(t->data<x) t=t->rc;
			else t=t->lc;
		}
	}
	return 0;
}
bool L_Rotate(BSTree &T)
{
	BSTNode *temp;
	temp=T->rc;
	T->rc=temp->lc;
	if(T->rc) T->rc->fa=temp;
	temp->lc=T;
	T=temp;
	T->lc->fa=T;
	return 1;
}
bool R_Rotate(BSTree &T)
{	
	BSTNode *temp;
	temp=T->lc;
	T->lc=temp->rc;
	if(T->lc) T->lc->fa=temp;
	temp->rc=T;
	T=temp;
	T->rc->fa=T;
	return 1;
}
bool R_Rotate_F(BSTree &T,BSTree &checkP)
{	//Because of the pointer "fa"
	//Change the "fa" based on R_Rotate
	int tag=0;
	BSTNode *pfa;
	pfa=checkP->fa;
	if(pfa)
	{
		if(pfa->lc==checkP)
		tag=-1;
		else
		tag=1;
	}
	else//Directly change the root "T"
	{
		if(T->lc==checkP)
		tag=-1;
		else
		tag=1;
	}
	R_Rotate(checkP);
	checkP->fa=pfa;
	if(pfa)
	{
		if(tag==-1)
		pfa->lc=checkP;
		else
		pfa->rc=checkP;	
	}
	else T=checkP;
	return 1;
}
bool L_Rotate_F(BSTree &T,BSTree &checkP)
{	// the same with R_Rotate_F
	int tag=0;
	BSTNode *pfa;
	pfa=checkP->fa;
	if(pfa)
	{
		if(pfa->lc==checkP)
		tag=-1;
		else
		tag=1;
	}
	else
	{
		if(T->lc==checkP)
		tag=-1;
		else
		tag=1;
	}
	L_Rotate(checkP);
	checkP->fa=pfa;
	if(pfa)
	{
		if(tag==-1)
		pfa->lc=checkP;
		else
		pfa->rc=checkP;	
	}
	else T=checkP;
	return 1;
}
int getLH(BSTree& );
int getRH(BSTree& );

int getLH(BSTree &T)
{
	if(!T) return -1;
	else 
	{	//Choose the higher one 
		int clh,crh;
		clh=getLH(T->lc)+1;
		crh=getRH(T->lc)+1;
		return clh>crh? clh : crh;
	}
}
int getRH(BSTree &T)
{
	if(!T) return -1;
	else
	{	//The same with getLH
		int clh,crh;
		clh=getLH(T->rc)+1;
		crh=getRH(T->rc)+1;
		return clh>crh? clh : crh;
	}
}
bool resetH(BSTree &T)
{	//Reset the "bf" with funcs getLH & getRH
	if(T)
	{
		T->lh=getLH(T);
		T->rh=getRH(T);
		if(T->lc) resetH(T->lc);
		if(T->rc) resetH(T->rc);
	}
	
}

bool insertBST(BSTree &T,int x)
{
	BSTNode *p,*temp;
	int bal[255]={0};
	int count=0;
	int balance;
	if(searchBST(T,x,p))
	{	//x exists
		cout<<"Existance element:"<<x<<endl;
		return 0;
	}
	else
	{
		temp=new BSTNode;
		temp->data=x;
		temp->lh=temp->rh=0;
		temp->fa=p;
		temp->lc=NULL;
		temp->rc=NULL;
		if(!p)
		{	//if the tree is empty
			T=temp;
		}
		else//insert the node with x
		{
			if(p->data>x)
			{
				p->lc=temp;
			}
			else
			{
				p->rc=temp;
			}
		}
		BSTNode *checkP=temp;
		resetH(T);
		while(checkP)
		{	//use balance to calculate "bf"
			balance=checkP->lh-checkP->rh;
			switch(balance)
			{
				case -2:
					switch(bal[--count])
					{
						case -1:
							cout<<"Balance rotate:RR"<<endl;
							L_Rotate_F(T,checkP);
							resetH(T);
							break;
						case 1:
							cout<<"Balance rotate:RL"<<endl;
							R_Rotate_F(T,checkP->rc);
							L_Rotate_F(T,checkP);
							resetH(T);
							break;
						default:
							cout<<"error"<<endl;
							break;
					}
					goto jump;
				case 2:
					switch(bal[--count])
					{
						case -1:
							cout<<"Balance rotate:LR"<<endl;
							L_Rotate_F(T,checkP->lc);
							R_Rotate_F(T,checkP);
							resetH(T);
							break;
						case 1:
							cout<<"Balance rotate:LL"<<endl;
							R_Rotate_F(T,checkP);
							resetH(T);
							break;
						default:
							cout<<"error"<<endl;
							break;
					}
					goto jump;
				default:
					bal[count++]=balance;
					checkP=checkP->fa;
					break;
			}
		}
		jump:
			return 1;
	}
}

bool printTree(BSTree &T,int depth)
{	//It is equivalent with RDL
	if(T)
	{
		printTree(T->rc,depth+1);
		for(int i=0;i<=depth-1;i++)
		{
			cout<<"     ";
		}
		//Node: lh*data*rh
		cout<<T->lh<<"*"<<T->data<<"*"<<T->rh<<endl;
		printTree(T->lc,depth+1);
	}
}

int main(void)
{
	cout<<"Getting the input from the file 'bst_input.txt' "<<endl;
	cout<<"10 elements by default."<<endl;
	freopen("bst_input.txt","r",stdin);
	int x;
	BSTree T=NULL;
	for(int i=0;i<=MAX_NODES-1;i++)
	{
		cin>>x;
		insertBST(T,x);
		//printTree(T,0);
	}
	printTree(T,0);
	return 0;
}
