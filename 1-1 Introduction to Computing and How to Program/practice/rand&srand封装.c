#include<stdio.h>
#include<time.h>//deriving the function of rand 0-32767
unsigned int next=1;
int rand(int next)//refine the function,input the 'next'
{
	next=next*1103515245+12345;
	return (unsigned int)(next/65536)%32768;
}
void srand(unsigned int seed)
{
	next=seed;
}
int main(void)
{
	printf("%d",rand(time(NULL)));//no need to quote 'srand'function
	return 0;
}
