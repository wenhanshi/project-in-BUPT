#include<stdio.h>
int main(void)
{
	int row,col;
	int v[10][10]={0};
	for(row=0;row<=9;row++)
	{
		v[row][0]=1;
	}
	for(row=0,col=0;row<=9;row++,col++)
	{
		v[row][col]=1;
	}
	for(row=1;row<=9;row++)
	{
		for(col=1;col<=9;col++)
		{
			v[row][col]=v[row-1][col-1]+v[row-1][col];
		}
	}
	for(row=0;row<=9;row++)
	{
		for(col=0;col<=row;col++)
		{			
			printf("%d\t",v[row][col]);
		}
		printf("\n");
	}
}
