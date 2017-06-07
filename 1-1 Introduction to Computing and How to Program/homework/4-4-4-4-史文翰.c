#include<stdio.h>
int GCD(int,int);
int LCM(int,int);
int main(void)
{
	int a,b;
	printf("Please in put two integers:");
	scanf("%d%d",&a,&b);
	printf("The greatest common divisor is %d and the lowest common multiple is %d.",GCD(a,b),LCM(a,b));
	return 0;
}
int GCD(int x,int y)
{
	int h;
	if(x<y)
	{
		h=x;
		x=y;
		y=h;
	}
	while(x%y!=0)
	{
		h=y;
		y=x%y;
		x=h;
	}
	return y;
}
int LCM(int x,int y)
{
	return x*y/GCD(x,y);
}
