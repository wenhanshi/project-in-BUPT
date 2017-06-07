#include<stdio.h>
int x;
int f(int x)
{
	if(x==0||x==1)
	{
		return 1;
	}
	else
	{
		return f(x-1)+f(x-2);
	}
}
int main(void)
{
	int i;
	for(i=1;i<=10;i++)
	{
		printf("%d\n",f(i));
	}
	return 0;
}

