#include<stdio.h>
int a[100][100];
int b[100][100];
int newElement(int row,int col,int s)
{
	int sum=0,i;
	for(i=1;i<=s;i++)
	{
		sum+=a[row][i]*b[i][col];
	}
	return sum;
}
void print(int v[][100],int fromRow,int toRow,int fromCol,int toCol)
{
	int i,j;
	printf("\nThe result is:\n");
	for(i=fromRow;i<=toRow;i++)
	{
		for(j=fromCol;j<=toCol;j++)
		{
			printf("%d\t",v[i][j]);
		}
		printf("\n");
	}
}
int main(void)
{
	int row,col,m,s,n;
	int result[100][100];
	printf("Please input the bound of two martixes. eg(2*3*4):\n");
	scanf("%d*%d*%d",&m,&s,&n);
	fflush(stdin);
	printf("\nInput the first matrix:\n(Tips:If u wanna input a matrix of 2*3,input the row first.)\n");
	for(row=1;row<=m;row++)
	{
		for(col=1;col<=s;col++)
		{
			scanf("%d",&a[row][col]);
		}
	}
	fflush(stdin);
	printf("\nInput another matrix:\n");
	for(row=1;row<=s;row++)
	{
		for(col=1;col<=n;col++)
		{
			scanf("%d",&b[row][col]);
		}
	}
	for(row=1;row<=m;row++)
	{
		for(col=1;col<=n;col++)
		{
			result[row][col]=newElement(row,col,s);
		}
	}
	print(result,1,m,1,n);
	return 0;
}
