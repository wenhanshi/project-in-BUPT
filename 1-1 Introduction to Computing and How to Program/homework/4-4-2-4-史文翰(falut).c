clude<stdio.h>
#include<math.h>
double f(double);
int main(void)
{
	double x0; 
	printf("Please input a float number:");
	scanf("%lf",&x0);
	printf("The result is:%.4lf",f(x0));
	return 0;
}
double f(double x)
{
	long fenmu=1;
	double sum=0;
	int i=1;
	for(i;((pow(x,i))/fenmu)>(1e-8);i++) 
	{
		for(i;i>=1;i--)
		{
			fenmu*=i;
		}
		sum+=((pow(x,i))/fenmu);
	}
	return sum;
}
