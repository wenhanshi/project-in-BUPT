#include<stdio.h>
int main(void)
{
	int i,j,a[10][10];
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			a[i][j]=i+j;
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
