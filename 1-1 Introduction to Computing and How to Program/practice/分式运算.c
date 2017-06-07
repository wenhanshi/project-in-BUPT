#include<stdio.h>
long long GCD(long long,long long);
int main(void)
{
	int i,n;
	long long summu=3,sumzi=1,store,store_sumzi;
	scanf("%d",&n);
	for(i=3;i<=n;i+=2)
	{
		store=summu;
		summu*=(i+2);
		sumzi=sumzi*(i+2)+store*i;
		store_sumzi=sumzi;
		sumzi/=GCD(sumzi,summu);
		summu/=GCD(store_sumzi,summu);
	}

	printf("\n%lld/%lld",sumzi,summu);
	return 0;
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
	while(x%y!=0)
	{
		h=y;
		y=x%y;
		x=h;
	}
	return y;
}
