#include<stdio.h>
int total(int n)
{
	if(n==1)
	{
		return n;
	}
	else 
	{
		return total(n-1)+n+1;
	}
}
int main(void)
{
	int n;
	scanf("%d",&n);
	printf("%d",total(n));
	return 0;
}
