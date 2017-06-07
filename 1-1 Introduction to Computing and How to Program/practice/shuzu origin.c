#include<stdio.h>
#define SIZE 100
int main(void)
{
	int c[SIZE];
	int i,j;
	for(i=0;i<=SIZE-1;i++)
	{
		c[i]=2*i+2;
	}
	printf("Number\tValue\n");
	for(j=0;j<=SIZE-1;j++)
	{
		printf("%d\t%d\n",j,c[j]);
	}
	return 0;
}
