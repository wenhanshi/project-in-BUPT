#include<stdio.h>
int main(void)
{
	int i,j,m,n,squ=0,rec=0,sum=0,sum1=0,sum2=0;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	{
		sum1+=i;
	}
	for(i=1;i<=m;i++)
	{
		sum2+=i;
	}
	sum=sum1*sum2;
	for(i=m,j=n;i>=1&&j>=1;i--,j--)
	{
		squ+=i*j;
	}
	rec=sum-squ;
	printf("The number of square is %d,The number of rectangle is %d.",squ,rec);
	return 0;
}
