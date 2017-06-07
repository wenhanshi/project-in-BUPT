#include<stdio.h>
int n,base;
void tenToAny(int n,int base)
{
	int quan=1,count=0;
	while(n>quan)
	{
		quan*=base;
	}
	quan/=base;
	while(quan>0)
	{
		printf("%d",n/quan);
		n=n%quan;
		quan=quan/base;
	}
}
int main(void)
{
	scanf("%d%d",&n,&base);
	tenToAny(n,base);
	return 0;
}
