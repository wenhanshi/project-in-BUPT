#include<stdio.h>
int main(void)
{
	double t=2.0;
	long double g=2.0;
	scanf("%lf",&g);
	printf("%.6f",t+(double)g);
	return 0;
}
