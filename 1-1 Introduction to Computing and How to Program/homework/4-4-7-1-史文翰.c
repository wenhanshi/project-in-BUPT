#include<stdio.h>
int isWaveNumber(int n)
{
	int temp;
	if(n<=99)
	{
		if(n<10) return 1;
		if(n>10&&n/10!=n%10) return 1;
		return 0;
	}
	else
	{
		temp=n/100;
		if(isWaveNumber(temp)==0)
		{
			return 0;
		}
		if(temp%100==n%100)
		{
			return 1;
		}
		if(temp<10&&temp==n%10)
		{
			return 1;
		}
		return 0;
	}
}
int main(void)
{
	int x;
	scanf("%d",&x);
	if(isWaveNumber(x)==1)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}
