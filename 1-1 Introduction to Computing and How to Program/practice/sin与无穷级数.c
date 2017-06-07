#include<stdio.h>
#include<math.h>
int main(void)
{
	double x,p;
	double sum;
	int i=1;
	scanf("%lf",&x);
	p=x;
	while(fabs(p)>=1e-6)
	{
		sum+=p;
		i++;
		p=-p*x*x/((2*i-1)*(2*i-2));
	}
	printf("\n%.2lf",sum);
	return 0;
}
