#include<stdio.h>
int isPrim(int x)
{
	int i=2,flag=1;
	while(flag&&i*i<x)
	{
		if(x%i==0)
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
int reverse(int x)
{
	int p,rev=0;
	while(x>0)
	{
		p=x%10;
		rev=rev*10+p;
		x/=10;
	}
	return rev;
}
int main(void)
{
	int n;
	scanf("%d",&n);
	printf("%d\n%d\n",isPrim(n),reverse(n));
	return 0;
}

