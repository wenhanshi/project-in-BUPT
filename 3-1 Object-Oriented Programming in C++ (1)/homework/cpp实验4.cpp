//4.Matrix no.1

#include<iostream>
using namespace std;

const int ROW=2;
const int COL=3;


bool initMtx(int M[ROW][COL])
{
	for(int i=0;i<=ROW-1;i++)
	{
		for(int j=0;j<=COL-1;j++)
		{
			cin>>M[i][j];
		}
	}
	return 1;
}

bool outputMtx(int M[ROW][COL])
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

bool addMtx(int M[ROW][COL],int N[ROW][COL],int(& ans)[ROW][COL])
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

bool subMtx(int M[ROW][COL],int N[ROW][COL],int(& ans)[ROW][COL])
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
	int A1[ROW][COL];
	int A2[ROW][COL];
	int A3[ROW][COL];
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
	return 0;
}

