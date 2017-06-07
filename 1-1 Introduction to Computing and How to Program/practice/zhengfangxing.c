#include<stdio.h>
int main(void)
{
	int i=1,j=1;
	while(i<=100)
	{
		while(j<=100)
		{
			if((j==-i+2)||(j==-i+6)||(j==i-2)||(j==i+2))
				printf("*");
			else
				printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
	return 0;
}
