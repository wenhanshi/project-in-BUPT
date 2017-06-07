#include<stdio.h>
int main(void)
{
	int i=2;
	int k;
	int isprim=1;
	scanf("%d",&k);
	while(i*i<=k&&isprim)
	{
		if(k%i==0)
		{
			isprim=0;
		}
		else
		{
			i++;
		}
	}
	if(isprim==0)
	{
		printf("not zhishu");
	}
	else
	{
		printf("zhishu");
	}
	return 0;
}
