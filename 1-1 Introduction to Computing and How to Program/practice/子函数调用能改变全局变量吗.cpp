#include<stdio.h>
int x=10;
void f(void)
{
	x=100;
}
int main(void)
{
	int x=99; 
	f();
	printf("%d",x);
	return 0;
}
