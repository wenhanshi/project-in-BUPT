#include<stdio.h>
long f(long);
int main(void)
{
	long sum,i;
	printf("Please input you x:");
	scanf("%ld",&i);
	sum=f(i);
	printf("%ld",sum);
	return 0;
}
long f(long x)
{
	if(x==0||x==1)
	{
		return x;
	}
	else
		return f(x-1)+f(x-2);
}
