#include<stdio.h>
int x,n;
int mypow(int x,int n)
{
	int result=1,i;
	for(i=1;i<=n;i++)
	{
		result*=x;
	}
	return result;
}
int main(void)
{
	scanf("%d%d",&x,&n);
	printf("The result is %d.",mypow(x,n));
	return 0;
}
