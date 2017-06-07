
#include<stdio.h>
#define MAXCOL 100
#define MAXROW 100
int det(int v[][MAXCOL],int n)
{
	int sum=0;
	if(n==1)
	{
		return v[0][0];
	}
	else
	{
		for(int col=0;col<=n-1;col++)
		{
			sum+=v[0][col]*detMod(v,col,n);
		}
		return sum;
	}
}
int detMod(int p[][MAXCOL],int col,int n)
{
	int son[MAXROW][MAXCOL];
	int newRow=0,newCol=0;	
	for(int oriRow=1;oriRow<=n-1;oriRow++)
	{
		for(int oriCol=0;oriCol<=n-1;oriCol++)
		{
			if(oriCol!=col)
			{
				son[newRow][newCol++]=p[oriRow][oriCol];
				if(newCol%(n-1)==0&&newCol!=0)
				{
					newRow++;
					newCol=0;
				}
			}
		}
	}
	if(col%2!=0)
	{
		return -det(son,n-1);
	}
	return det(son,n-1);
}
int main(void)
{
	int n;
	int v[MAXROW][MAXCOL];
	printf("Please input the order of the matrix:");
	scanf("%d",&n);
	printf("Then,input the elements of your matrix:\n");
	for(int row=0;row<=n-1;row++)
	{
		for(int col=0;col<=n-1;col++)
		{
			scanf("%d",&v[row][col]);
		}
	}
	printf("The result is:%d\n",det(v,n));
	return 0;
}
