#include<stdio.h>
#define MAX 999
int main(void)
{
	int a[MAX]={0};
	int p=2,i,count=0;
	for(i=p+1;i<=MAX-1;i++)
	{
		if(i%2==0)
		{
			a[i]=1;
		}
	}
	p++;
	while(p*p<=MAX)
	{
		for(i=p+1;i<=MAX-1;i++)
		{
			if(i%p==0)
			{
				a[i]=1;
			}
		}
		p++;
		while(a[p]!=0)
		{
			p++;
		}
	}
	for(i=2;i<=MAX-1;i++)
	{
		if(a[i]==0)
		{
			printf("%d\t",i);
			count++;
		}
		if(count!=0&&count%5==0)
		{
			printf("\n");
			count=0;
		}
	}
}
