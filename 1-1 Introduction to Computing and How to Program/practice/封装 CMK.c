#include<stdio.h>
#define MAXVAL 20

void CMK(int m,int k,int num[])
{
	if(k==1)
	{
		printf("%d\n",num[0]);
		if(m==1)
		{
			return;
		}
		else
		{
			CMK(m-1,1,&num[1]);
		}
	}
	else
	{
		for(int i=0;i<=m-k+1-1;i++)
		{
			printf("%d ",num[i]);
			CMK(m-(i+1),k-1,&num[i+1]);
		}
	}
}


int main(void)
{
	int m,k,num[MAXVAL];
	
	scanf("%d%d",&m,&k);
	for(int i=0;i<=m-1;i++)
	{
		scanf("%d",&num[i]);
	}
	CMK(m,k,num);
	return 0;
}
