#include<stdio.h>
int main(void)
{
	long string,pro;
	int cou=0;
	scanf("%ld",&string);
	pro=string;
	do
	{
		pro/=10;
		cou++;
	}
	while(pro!=0);
	printf("\nresult:%d",cou);
	return 0;
}
