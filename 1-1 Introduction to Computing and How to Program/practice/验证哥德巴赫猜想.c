#include<stdio.h>
int isPrime(int n)
{
	int flag=1,i=2;
	while(flag&&i*i<=n)
	{
		if(n%i==0)
		{
			flag=0;
		}
		else
		{
			i++;
		}
	}
	if(flag==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main(void)
{
	int i,j;
	for(i=2;i<=1000;i+=2)
	{
		for(j=2;j<=i/2;j++)
		{
			if(isPrime(j)==1&&isPrime(i-j)==1)
			{
				printf("%d=%d+%d\n",i,j,i-j);
			}
		}
	}
	return 0;
}
