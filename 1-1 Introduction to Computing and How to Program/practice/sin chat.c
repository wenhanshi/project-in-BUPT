#include<stdio.h>
#include<math.h>
int main(viod)
{
	double i=1,j=1;
	while(i<=100)
	{
		while(j<=100)
		{
			if(fabs(i-sin(j))<(1e-1))
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
			j++;
		}
		i++;
	}
	return 0;
}
