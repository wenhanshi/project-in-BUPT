#include<stdio.h>
int main(void)
{
	double a,b,c,d,re;
	
	printf("Please input four float numbers:");
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	re=(a+b)*(a-b)+c/d;
	printf("The result is %lf",re);
	return 0;
}
