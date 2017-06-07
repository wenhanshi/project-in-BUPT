#include<stdio.h>
long f(int x)
{
	int i;
	long result=1;
	for(i=x;i>=1;i--)
	{
		result*=i;
	}
	return result;
}
int main(void)
{
	int m,n;
	long result;
	scanf("%d%d",&m,&n);
	printf("%ld",result=f(m)/(f(n)*(f(m-n))));
	return 0;
}
