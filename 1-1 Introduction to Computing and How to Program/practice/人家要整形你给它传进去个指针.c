#include<stdio.h>
void fun(int*x)//这里原题错了，妈的 
{
	printf("%d",++*x);
}
int main(void)
{
	int a=25;
	fun(&a);
	return 0;
}
