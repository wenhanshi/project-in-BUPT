#include<stdio.h>
int n;
int isPrime(int n)
{
	int flag=1,i=2;
	while(i*i<n&&flag)
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
	if(flag==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(void)
{
	scanf("%d",&n);
	printf("%d",isPrime(n));
	return 0;
}
