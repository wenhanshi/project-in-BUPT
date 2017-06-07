#include<stdio.h>
int powerPow(int x,int n)
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
	int i,temp,count,count0=0,sum=0,tale,store;
	for(i=100;i<=9999999;i++)
	{
		temp=i;
		count=0;
		while(temp>0)
		{
			count++;
			temp/=10;
		}
		temp=i;
		store=count;
		for(store;store>0;store--)
		{
			tale=temp%10;
			sum+=powerPow(tale,count);
			temp/=10;
		}
		if(sum==i)
		{
			printf("%d\n",i);
		}
		sum=0;
	}
	return 0;
}
