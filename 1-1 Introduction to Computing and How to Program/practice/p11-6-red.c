#include<stdio.h>
int main(void)
{
	int a,b,c,trans,ori;
	scanf("%d",&ori);
	c=ori/100,b=ori%100/10,a=ori%10;
	trans=a*100+b*10+c;
	if(a!=0)
		printf("After changing,the new number is %d",trans);
	else
		printf("The number can't be changed.");
	return 0;
}
