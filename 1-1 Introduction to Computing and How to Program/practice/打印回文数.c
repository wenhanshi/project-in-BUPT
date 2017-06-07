#include<stdio.h>
long f(long);
int main(void)
{
	long i,n,refer,store;
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
	{
		refer=i%10;
		store=i/10;
		while(store!=0)
		{
			refer=refer*10+store%10;
			store/=10;
		}
		if(refer==i)
		{
			printf("%ld\n",i);
		}
	}
	return 0;
}
long f(long x)
{
	long p=1;
	while(x!=0)
	{
		x/=10;
		p*=10;
	}
	p/=10;
	return p;
}
