#include<stdio.h>
int judgeSame(int*v,int n)
{
	int i,flag;
	i=0;
	flag=1;
	while(i<=n&&flag==1)
	{
		if(v[i]!=v[0])
		{
			flag=0;
		}
		i++;
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
	int i=0,j=0,count=0,x,puppet;
	int even[20],odd[20];
	scanf("%d",&x);
	puppet=x;
	while(puppet>0)
	{
		if((count++)%2==0)
		{
			even[i++]=puppet%10;
		}
		else
		{
			odd[j++]=puppet%10;
		}
		puppet/=10;
	}
	if((x>=0&&x<=99)||judgeSame(even,i-1)+judgeSame(odd,j-1)==2&&odd[0]!=even[0])
	{
		printf("Yes!\n");
	}
	else
	{
		printf("No!\n");
	}
	return 0;
}
