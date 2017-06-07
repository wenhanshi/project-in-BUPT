#include<stdio.h>
int count;
int countBinary(int n)
{
	count++;
	if(n==0)
	{
		return 0;
	}
	else
	{
		return n%2+countBinary(n/2)*10;
	}
}
int main(void)
{
	int x;
	scanf("%d",&x);
	countBinary(x);
	printf("%d",count-1);
	return 0;
}
