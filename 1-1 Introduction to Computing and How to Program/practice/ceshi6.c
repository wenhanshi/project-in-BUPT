#include<stdio.h>
int count=0;
long f(long);
int main(void)
{
	int i=0;
	long t=0;
	for(i=1;i<=10;i++)
	{
		t=f(i);
		printf("%2d!=%ld\n\n",i,t);
	}
	return 0;
}
long f(long number)
{
	count++;
	for(int i=0;i<=count;i++)
	{
		printf("\t");
	}
	printf("parameter:%ld\n",number);
	if(number<1)
	{
		return 1;
	}
	return number*f(number-1);
}
