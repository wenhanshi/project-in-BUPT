#include<stdio.h>
int GCD(int a,int b)
{
	return a%b==0?b:GCD(b,a%b);
}
int main(void)
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d",GCD(x,y));
	return 0;
}
