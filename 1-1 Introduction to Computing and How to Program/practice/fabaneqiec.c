#include<stdio.h>
long f(int);
int main(void)
{
	int i,j;
	long result;
	
	printf("enter your number:");
	scanf("%d",&i);
	for(j=1;j<=i;j++)
	{
		result=f(j);
		printf("%ld\n",result);
	}
	return 0;	
}
long f(int x)
{
	if(1==x||0==x)
	{
		return x;
	}
	else
	{
		return f(x-1)+f(x-2);
	}
}
