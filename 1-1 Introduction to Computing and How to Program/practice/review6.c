#include<stdio.h>
int main(void)
{
	float sum=0,p=1,sign=1;
	while(fabs(1.0/p)>1e-4)
	{
		sum+=1.0/p*sign;
		p++;
		sign*=-1;
	}
	printf("%f",sum);
	return 0;
}
