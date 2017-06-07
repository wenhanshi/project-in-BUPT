#include<stdio.h>
int convert(int n)
{
	if(n==0||n==1)
	{
		return n;
	}
	else
	{
		return n%10+convert(n/10)*2;
	}
}
int main(void)
{
	int x;
	scanf("%d",&x);
	printf("%d",convert(x));
	return 0;
}
