#include<stdio.h>
float div(float x,float y)
{
	printf("%f %f\n",x,y);
	return x/y;
}
int main(void)
{
	int i=3;
	printf("%f",div(i,++i));
	return 0;
}
