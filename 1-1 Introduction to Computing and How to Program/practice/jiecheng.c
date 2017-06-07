#include<stdio.h>
#include<stdlib.h>
long f(int);
int main(void)
{
	int i;
	long result;
	printf("input:");
	scanf("%d",&i);
	result=f(i);
	printf("%ld",result);
	return 0;
}
long f(int x)
{
	if(x==1)
		return x;
	else
		return f(x-1)*x;
}
