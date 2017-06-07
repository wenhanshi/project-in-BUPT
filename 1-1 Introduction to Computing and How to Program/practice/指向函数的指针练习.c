#include<stdio.h>
int test(int x,int (*comp)(int m,int n))
{
	return x+*comp;
}
int sum(int x,int y)
{
	return x+y;
}
int main(void)
{
	int (*comp)(int,int),p;
	comp=sum;
	p=sum(2,3);
	printf("%d %d\n",(*comp)(1,2),p);
	printf("%d",test(1,sum(2,3))); 
	return 0;
}
