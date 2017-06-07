#include<stdio.h>
int GCD(int x,int y)
{
	return x%y==0?y:GCD(y,x%y);
}
int main(void)
{
	int a;
	a=GCD(21,14);
	printf("%d",a);
	return 0;
}
