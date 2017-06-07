#include<stdio.h>
int main(void)
{
	int j,n=1,number;
	scanf("%d",&number);
	for(;n<=number;n++)
	{
		for(j=1;j<=n;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(n=number;n>=1;n--)
	{
		for(j=1;j<=n;j++)
			printf("*");
		printf("\n");
	}	
	return 0;	
}
