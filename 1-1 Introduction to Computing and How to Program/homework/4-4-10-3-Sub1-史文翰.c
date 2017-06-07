#include<stdio.h>
int*Create1(int n)
{
	int*a;
	a=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",a+i);
	}
	return a;
}
int main(void)
{
	int*p,n;
	scanf("%d",&n);
	p=Create1(n);
	for(int i=0;i<=n-1;i++)
	{
		printf("%d ",-10**(p+i));
	}
	free(p);
	return 0;
}
