#include<stdio.h>
int maxLen(int a[],int n)
{
	int i,count=1,longest=1;
	for(i=1;i<=n-1;i++)
	{
		if(a[i]==a[i-1])
		{
			count++;
		}
		else if(count>longest)
		{
			longest=count;
			count=1;
		}
		else
		{
			count=1;
		}
	}
	return longest;
}
int main(void)
{
	int a[1000],n,i;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("the longest is:%d",maxLen(a,n));
	return 0;
}
