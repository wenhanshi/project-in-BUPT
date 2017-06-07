#include<stdio.h>
int main(void)
{
	char a;
	int even=0,odd=0;
	a=getchar();
	while(a!='\n')
	{
		if((a-'0')%2==0)
		{
			even++;
		}
		else
		{
			odd++;
		}
		a=getchar();
	}
	if(0!=odd&&0!=even)
	{
		printf("both");
	}
	else if(0==odd)
	{
		printf("even only");
	}
	else
	{
		printf("odd only");
	}
	return 0;
}
