#include<stdio.h>
long long GCD(long long,long long);
int main(void)
{
	long long m,n;
	scanf("%lld%lld",&m,&n);
	printf("%lld",GCD(m,n));
}
long long GCD(long long x,long long y)
{
	long long h;
	if(x<y)
	{
		h=x;
		x=y;
		y=h;
	}
	else
	{
		while(x%y!=0)
		{
			h=y;
			y=x%y;
			x=h;
		}
		return y;
	}
}
