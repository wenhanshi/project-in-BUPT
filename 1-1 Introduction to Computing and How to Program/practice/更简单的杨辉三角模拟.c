#include<stdio.h>
int main(void)
{
	int a[10][10],row,col;
	for(row=0;row<=9;row++)
	{
		for(col=0;col<=row;col++)
		{
			if(col==0||row==col)
			{
				a[row][col]=1;
			}
			else
			{
				a[row][col]=a[row-1][col-1]+a[row-1][col];
				printf("%d\t",a[row][col]);
			}
		}
		printf("\n");
	}
	return 0;
}
