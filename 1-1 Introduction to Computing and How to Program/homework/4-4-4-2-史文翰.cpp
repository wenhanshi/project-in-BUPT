#include<stdio.h>
int main(void)
{
	int p=2,q=1;
	double sum=2;
	printf("Please input an integer:");
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		p=p+q;
		q=p;
		sum+=(double)p/q;
	}
	printf("The result is:%.2lf",sum);
	return 0;
}
