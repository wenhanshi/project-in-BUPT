#include<stdio.h>
int main(void)
{
	char a;
	int cou=0;
	while(a!='\n')
	{
		a=getchar();
		cou++;		
	}
	printf("%d",cou);
	return 0;
}
