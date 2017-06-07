#include<stdio.h>
int orderJudge(int*a)
{
	int i,j,h,flag;
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=6;j++)
		{
			if(a[j]>a[j+1])
			{
				h=a[j];
				a[j]=a[j+1];
				a[j+1]=h;
			}
		}
	}
	i=0,flag=1;
	while(flag&&i<=6)
	{
		if(a[i]!=a[i+1])
		{
			i++;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main(void)
{
	int a[8]={1,2,3,4,5,6,7,8};
	int b[8]={1,1,3,4,5,6,7,8};
	printf("%d%d",orderJudge(a),orderJudge(b));
	return 0;
}
