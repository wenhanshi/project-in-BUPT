#include<stdio.h>
int main(void)
{
	int i=0,p=0,q=0,n,temp,count;
	int odd[100];
	int even[100];
	scanf("%d",&n);
	while(i++<=n-1)
	{
		scanf("%d",&temp);
		if(temp%2==0)
		{
			even[p++]=temp;
		}
		else
		{
			odd[q++]=temp;
		}
	}
	i=0;
	count=q;
	q=0;
	while(i++<=count)
	{
		even[p++]=odd[q++];
	}
	for(i=0;i<=n-1;i++)
	{
		if(i<=n-2)
		printf("%d ",even[i]);
		else
		printf("%d\n",even[i]);
	}
	return 0;
}
