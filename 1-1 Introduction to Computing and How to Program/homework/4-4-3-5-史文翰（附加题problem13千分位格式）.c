#include<stdio.h>
#include<math.h>
int main(void)
{
	int count=0;
	long number,head,rest;
	scanf("%ld",&number);

	while(number>999)
	{
		rest=number;
		while(rest>999)
		{
		rest/=1000;
		count++;
		}
		head=rest;
		printf("%ld,",head);
		number-=head*pow(1000,count);
		count=0;
	}
	printf("%ld",number);
	return 0;
}
