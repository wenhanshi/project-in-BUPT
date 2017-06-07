#include<stdio.h>
#include<math.h>
int main(void)
{
	int n=1;
	double x;
	double sum;
	double p=1;
	printf("Please input an float number:");
	scanf("%lf",&x);
	sum=p;
	while(p>(1e-8))
	{
		p=p*x/n;
		sum+=p;
		n++;
	}
	printf("The result is %.4lf",sum);
	return 0;
}
