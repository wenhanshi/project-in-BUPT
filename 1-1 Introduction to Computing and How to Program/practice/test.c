#include<stdio.h>
int x=1;
void test(int);
int main(void)
{
	printf("%d\n",x);
	test(x);
}
void test(int k)
{
	printf("%d",k);
}

