#include<stdio.h>
int main(void)
{
	int i,j,n,k;
	printf("Please input an integer:");
	scanf("%d",&k);
	n=k-1;
	printf("\nThe result is:\n");
	for(i=0;i<=2*n;i++)
	{
		for(j=0;j<=2*n;j++)
		{
			if((j==n-i||j==i+n||j==i-n||j==3*n-i))
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
