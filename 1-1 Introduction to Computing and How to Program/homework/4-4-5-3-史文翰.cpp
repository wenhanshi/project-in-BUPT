#include<stdio.h>
int n;
int isPrime(int n)
{
	int flag=1,i=2;
	while(i*i<n&&flag==1)
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
void printFactor(int n)
{
	printf("%d=",n);
	if(isPrime(n)==0)
	{
		printf("%d\n",n);
	}
	else
	{
		i=2;
		while(n!=1)
		{
			if(isPrime(i)==1&&n%i==0)
			{
				printf("%d*",i);
				n/=i;
			}
			else
			{
				i++;
			}
		}
		printf("\b \n");
	}
}
int main(void)
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	printf("The result is:\n");
	for(i=a;i<=b;i++)
	{
		printFactor(i);
	}
	return 0;
}
