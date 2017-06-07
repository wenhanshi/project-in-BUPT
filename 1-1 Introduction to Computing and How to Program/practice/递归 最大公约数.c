#include<stdio.h>
int GCD(int x,int y)
{
	int h; 
	if(x<y)
	{
		h=x;
		x=y;
		y=h;
	}
	if(x%y!=0)
	{
		return GCD(y,x%y);
	}
	else
	{
		return y;
	}
}
int main(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",GCD(a,b));
	return 0;
}
