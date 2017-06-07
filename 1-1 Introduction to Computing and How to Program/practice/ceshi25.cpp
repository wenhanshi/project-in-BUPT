#include<stdio.h>
int main(void)
{
	int n;
	int a[n]={0};
	scanf("%d",&n);
	for(int i=0;i<=n-1;i++)
	{
		printf("%d\n",*(a+i));
	}
	return 0;
	
}
