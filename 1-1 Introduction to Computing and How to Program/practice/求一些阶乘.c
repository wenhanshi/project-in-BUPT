#include<stdio.h>
int main(void)
{
	long long i,p,ans=0;
	p=1;
	for(i=1;i<=50;i++)
	{
		p*=i;
		ans+=p;
	}
	printf("%e",ans);
	return 0;
}
