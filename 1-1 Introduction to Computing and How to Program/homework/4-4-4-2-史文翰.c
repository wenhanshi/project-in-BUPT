#include<stdio.h>
int main(void)
{
	int p=2,q=1,h,n,i;
	double sum=2.00;
	printf("Please input an integer:");
	scanf("%d",&n);
	if(n==1)
	{
		printf("The result is:%.2lf",sum);
	}
	else
	{
		for(i=2;i<=n;i++)
		{
			h=p;
			p=p+q;
			q=h;
			sum+=(double)p/q;
		}
		printf("The result is:%.2lf",sum);
	}
	return 0;
}
