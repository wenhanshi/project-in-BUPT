#include<stdio.h>
int main(void)
{
	long string,pro;
	int cou=0;
	scanf("%ld",&string);
	pro=string;
	while(pro!=0)
	{
		pro/=10;
		cou++;
	}
	printf("\nresult:%d",cou);
	return 0;
}
