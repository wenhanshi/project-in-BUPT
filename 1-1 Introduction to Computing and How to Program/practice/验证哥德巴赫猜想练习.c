#include<stdio.h>
int isprim(int x)
{
	int flag=1,n=2;
	while(n*n<=x&&flag)
	{
		if(x%n==0)
		{
			flag=0;
		}
		else
		{
			n++;
		}
	}
	if(flag==1)
	{
		return 1;
	}
	return 0;
}
int main(void)
{
	int i,j;
	for(i=36122;;i+=2)
	{
		for(j=2;j<=i/2;j++)
		{
			if(isprim(j)==1&&isprim(i-j)==1)
			printf("%d=%d+%d\n",i,j,i-j);
			system("pause");
		}
	}
	return 0;
}
