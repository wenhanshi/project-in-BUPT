#include<stdio.h>
long f(long,int);
int count=1;
int main(void)
{
	int i=0;
	long t=0;
	for(i=1;i<=10;i++)
	{
		t=f(i,count);
		printf("%2d!=%ld\n\n",i,t);
	}
	return 0;
}
long f(long number,int count)
{
	for(int i=1;i<=count;i++)
	{
		printf("\t");
	}
	printf("parameter:%ld\n",number);
	if(number<1)
	{
		return 1;
	}
	return number*f(number-1,count+1);
}
