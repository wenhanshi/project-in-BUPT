#include<stdio.h>
int v[100][100];
float aveRow(int v[][100],int row,int maxCol)
{
	int sum=0;
	for(int col=0;col<=maxCol-1;col++)
	{
		sum+=v[row][col];
	}
	return (float)sum/maxCol;
}
int findMin(float a[],int n)
{
	int min=1001,loc=0;
	for(int i=0;i<=n-1;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			loc=i;
		}
	}
	return loc;
}
void print(int v[][100],int row,int maxCol)
{
	for(int i=0;i<=maxCol-1;i++)
	{
		printf("%d ",v[row][i]);
	}
	printf("\n");
}
int main(void)
{
	int n,row,col,pass,min;
	float mark[100];
	printf("Please input the row of the matrix:");
	scanf("%d",&n);
	printf("Please input the elements of the matrix:\n");
	for(row=0;row<=n-1;row++)
	{
		for(col=0;col<=n-1;col++)
		{
			scanf("%d",&v[row][col]);
		}
	}
	for(row=0;row<=n-1;row++)
	{
		mark[row]=aveRow(v,row,n);
	}
	printf("mark:\n");
	for(int i=0;i<=n-1;i++)
	{
		printf("%f ",mark[i]);
	}
	printf("\nThe result is:\n");
	for(pass=0;pass<=n-1;pass++)
	{
		min=findMin(mark,n);
		print(v,min,n);
		mark[min]=1001;
	}
	return 0;
}
