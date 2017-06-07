#include<stdio.h>
int main(void)
{
	int i,j,k,num;
	scanf("%d",&k);
	num=2*k-1;
	for(i=0;i<=num+1;i++)
	{
		for(j=0;j<=num+1;j++)
		{
			if(i>=(k-j)&&i>=(j-k)&&i<=(j+k)&&i<=(3*k-j)&&(k%2==0?((i+j)%2!=0):((i+j)%2==0)))
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
