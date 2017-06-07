#include<stdio.h>
static int x;
void f(void)
{
	x++;
}
int main(void)
{
	x=2;
	printf("%d\n",x);
	f();
	printf("%d\n",x);
	f();
	printf("%d\n",x);
	return 0;
}
