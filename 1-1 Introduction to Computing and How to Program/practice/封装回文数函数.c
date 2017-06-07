#include<stdio.h>
long n;
long reverse(long n)
{
	long reverseNumber=0,store;
	store=n;
	while(store>0)
	{
		reverseNumber=reverseNumber*10+store%10;
		store/=10;
	}
	return reverseNumber;
}
int main(void)
{
	scanf("%ld",&n);
	printf("%ld",reverse(n));
	return 0;
}
