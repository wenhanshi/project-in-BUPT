//5.Matrix no.2 ptr

#include<iostream>
using namespace std;

const int ROW=4;
const int COL=5;


bool initMtx(int **M)
{
	M=new int* [ROW];
	for(int i=0;i<=COL-1)
	{
		M[i]=new int [COL];
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

bool addMtx(int **M,int **N,int **(& ans))
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

bool subMtx(int **M,int **N,int **(& ans))
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

int main(void)
{
	int **A1;
	int **A2;
	int **A3;
	cout<<"Input A1 (row firstly):"<<endl; 
	initMtx(A1);
	cout<<"Input A2 (row firstly):"<<endl;
	initMtx(A2);
	cout<<"A1:"<<endl;
	outputMtx(A1);
	cout<<"A2:"<<endl;
	outputMtx(A2);
	addMtx(A1,A2,A3);
	cout<<"A1+A2="<<endl;
	outputMtx(A3);
	subMtx(A1,A2,A3);
	cout<<"A1-A2="<<endl;
	outputMtx(A3);
	for(int i=0;i<=ROW-1;i++)
	{
		delete [](A1[i]);
	}
	delete []A1;
	for(int i=0;i<=ROW-1;i++)
	{
		delete [](A2[i]);
	}
	delete []A2;
	return 0;
}
