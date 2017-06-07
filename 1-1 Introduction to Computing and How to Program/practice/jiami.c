#include<stdio.h>
int main(void)
{
	char i;
	i=getchar();
	if(i>='a'&&i<='w')
	{
		printf("%c",i+3);
	}
	else
	{
		printf("%c",i-23);
	}
	return 0;
}
