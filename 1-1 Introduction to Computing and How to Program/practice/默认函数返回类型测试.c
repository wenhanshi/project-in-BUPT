#include<stdio.h>
f(int x)
{
	return x;
}
main()
{
	float a=3.14;
	a=f(a);
	printf("%.2f",a);
}
