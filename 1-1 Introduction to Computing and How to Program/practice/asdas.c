#include<stdio.h>
int main(void)
{
	int n,ans=1;
	scanf("%d",&n);
	while(n>=1)
	{
		ans*=n--;
	}
	printf("%d",ans);
	return 0;
}
