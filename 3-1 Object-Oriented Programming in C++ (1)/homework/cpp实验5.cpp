//5.Matrix no.2 ptr

#include<iostream>
using namespace std;

const int ROW=2;
const int COL=1;


bool initMtx(int ** (&M) )
{
	M=new int* [ROW];
	for(int i=0;i<=ROW-1;i++)
	{
		M[i]=new int[COL];
	}
	for(int i=0;i<=ROW-1;i++)
	{
		for(int j=0;j<=COL-1;j++)
		{
			cin>>M[i][j];
		}
	}
	return 1;
}
bool initMtx0(int **&M)
{
	M=new int* [ROW];
	for(int i=0;i<=ROW-1;i++)
	{
		M[i]=new int [COL];
	}
	for(int i=0;i<=ROW-1;i++)
	{
		for(int j=0;j<=COL-1;j++)
		{
			M[i][j]=0;
		}
	}
	return 1;
}

bool outputMtx(int **M)
{
	for(int i=0;i<=ROW-1;i++)
	{
		for(int j=0;j<=COL-1;j++)
		{
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	return 1;
}

bool addMtx(int **M,int **N,int **& ans)
{
	for(int i=0;i<=ROW-1;i++)
	{
		for(int j=0;j<=COL-1;j++)
		{
			ans[i][j]=M[i][j]+N[i][j];
		}
	}
	return 1;
}

bool subMtx(int **M,int **N,int **& ans)
{
	for(int i=0;i<=ROW-1;i++)
	{
		for(int j=0;j<=COL-1;j++)
		{
			ans[i][j]=M[i][j]-N[i][j];
		}
	}
	return 1;
}
bool del(int **M)
{
	for(int i=0;i<=ROW-1;i++)
	{
		delete [](M[i]);
	}
	delete []M;
	return 1;
}

int main(void)
{
	//int count1=0;
	//int count2=0;
	int **A1;
	int **A2;
	int **A3;
	cout<<"Input A1 (row firstly):"<<endl; 
	initMtx(A1);
	cout<<"Input A2 (row firstly):"<<endl;
	initMtx(A2);
	cout<<"Init A3 for all 0 elems:"<<endl;
	initMtx0(A3);
	
	cout<<"A1:"<<endl;
	outputMtx(A1);
	cout<<"A2:"<<endl;
	outputMtx(A2);
	cout<<"A3:"<<endl;
	outputMtx(A3);
	addMtx(A1,A2,A3);
	cout<<"A1+A2="<<endl;
	outputMtx(A3);
	subMtx(A1,A2,A3);
	cout<<"A1-A2="<<endl;
	outputMtx(A3);
	del(A1);
	del(A2);
	del(A3);
	return 0;
}
