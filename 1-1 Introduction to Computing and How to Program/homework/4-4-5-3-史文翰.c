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
void printFactor(int n)
{
	int i,k;
	printf("%d=",n);
	if(isPrime(n)==1)
	{
		printf("%d",n);
	}
	else
	{
		i=2;
		k=n;
		while(k!=1)
		{
			if(isPrime(i)==1&&k%i==0)
			{
				k/=i;
				if(k!=1)
				printf("%d*",i);
				else
				printf("%d",i);
			}
			else
			{
				i++;
			}
		}
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
		if(i<b)
		{
			printf("\n");
		}
	}
	return 0;
}
