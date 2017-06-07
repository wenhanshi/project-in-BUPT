#include<stdio.h>
#include<math.h>
int main(void)
{
	int a,b,c,d,flag=1;
	double p=1,h1,h2,h3;
	printf("Please input four integers:");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while(flag==1)
	{
		h1=p;
		p=p-(a*p*p*p+b*p*p+c*p+d)/(3*a*p*p+2*b*p+c);
		h2=p;
		if(fabs(h1-h2)<1e-5)
		{
			printf("\nThe solution is:%lf",h2);
			flag=0;
		}
	}
	return 0;
}
