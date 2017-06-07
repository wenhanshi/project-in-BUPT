#include<stdio.h>
int a[9];
int orderJudge(int*a)
{
	int i,j,h,flag;
	for(i=0;i<=8;i++)
	{
		for(j=0;j<=7;j++)
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
	while(flag&&i<=7)
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
	int count=0,number;
	for(number=100;number<=333;number++)
	{
		a[0]=number/100;
		a[1]=number/10%10;
		a[2]=number%10;
		a[3]=2*number/100;
		a[4]=2*number/10%10;
		a[5]=2*number%10;
		a[6]=3*number/100;
		a[7]=3*number/10%10;
		a[8]=3*number%10;
		if(orderJudge(a)==1)
		{
			printf("Group %d:%d %d %d\n",++count,number,2*number,3*number);
		}
	}
	return 0;
}
