//6.Matrix no.3 class

#include<iostream>
using namespace std;

class Matrix{
	private:
		int ROW,COL;
		int **PM;
	public:
		Matrix(int row,int col);
		~Matrix();
		Matrix(Matrix & );
		bool outputMtx();
		bool addMtx(Matrix &M,Matrix &N);
		bool subMtx(Matrix &M,Matrix &N);
		friend bool check(Matrix &A,Matrix &B);
}; 
Matrix::Matrix(int row,int col)
{
	cout<<"Building a matrix..."<<endl;
	ROW=row;
	COL=col;
	PM=new int* [ROW];
	for(int i=0;i<=ROW-1;i++)
	{
		PM[i]=new int [COL];
	}
	for(int i=0;i<=ROW-1;i++)
	{
		for(int j=0;j<=COL-1;j++)
		{
			cin>>PM[i][j];
		}
	}
}

Matrix::~Matrix()
{
	cout<<"Destroying the matrix..."<<endl;
	for(int i=0;i<=ROW-1;i++)
	{
		delete [](PM[i]);
	}
	delete []PM;
}

Matrix::Matrix(Matrix &M)
{
	ROW=M.ROW;
	COL=M.COL;
	PM=new int* [ROW];
	for(int i=0;i<=COL-1;i++)
	{
		PM[i]=new int [COL];
	}
	for(int i=0;i<=ROW-1;i++)
	{
		for(int j=0;j<=COL-1;j++)
		{
			cin>>PM[i][j];
		}
	}
}



bool Matrix::outputMtx()
{
	cout<<"The result after processing:"<<endl;
	for(int i=0;i<=ROW-1;i++)
	{
		for(int j=0;j<=COL-1;j++)
		{
			cout<<PM[i][j]<<" ";
		}
		cout<<endl;
	}
	return 1;
}

bool Matrix::addMtx(Matrix &M,Matrix &N)
{
	if(check(M,N)&&M.COL==COL&&M.ROW==ROW&&N.COL==COL&&N.ROW==ROW)
	{
		for(int i=0;i<=ROW-1;i++)
		{
			for(int j=0;j<=COL-1;j++)
			{
				PM[i][j]=M.PM[i][j]+N.PM[i][j];
			}
		}
		return 1;	
	}
	else
	{
		cout<<"Error:Not compared."<<endl;
		return 0;
	}
}

bool Matrix::subMtx(Matrix &M,Matrix &N)
{
	if(check(M,N)&&M.COL==COL&&M.ROW==ROW&&N.COL==COL&&N.ROW==ROW)
	{
		for(int i=0;i<=ROW-1;i++)
		{
			for(int j=0;j<=COL-1;j++)
			{
				PM[i][j]=M.PM[i][j]-N.PM[i][j];
			}
		}
		return 1;	
	}
	else
	{
		cout<<"Error:Not compared."<<endl;
		return 0;
	}
}

bool check(Matrix &A,Matrix &B)
{
	if(A.COL==B.COL&&A.ROW==B.ROW) return 1;
	return 0;
}

int main(void)
{
	int row1,col1,row2,col2,row3,col3;
	cout<<"Input row1,col1,row2,col2,row3,col3:"<<endl;
	scanf("%d%d%d%d%d%d",&row1,&col1,&row2,&col2,&row3,&col3);
	Matrix A1(row1,col1),A2(row2,col2),A3(row3,col3);
	if(A3.addMtx(A1,A2)) A3.outputMtx();
	
	cout<<"Another init by pointers:"<<endl;
	Matrix *pA1,*pA2,*pA3;
	cout<<"Input row1,col1,row2,col2,row3,col3:"<<endl;
	scanf("%d%d%d%d%d%d",&row1,&col1,&row2,&col2,&row3,&col3);
	pA1=new Matrix(row1,col1);
	pA2=new Matrix(row2,col2);
	pA3=new Matrix(row3,col3);
	if(pA3->addMtx(*pA1,*pA2)) pA3->outputMtx();
	delete pA1; delete pA2; delete pA3;
	
	return 1;
}
