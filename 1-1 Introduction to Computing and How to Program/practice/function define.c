#include<stdio.h>
int square(int);
int main(void)
{
	int x;
	scanf("%d",&x);
	printf("%d",square(x));
}
int square(int x)
{
	return x*x;
}

