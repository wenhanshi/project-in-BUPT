#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[10];
	gets(str);
	printf("\n\n%d",atoi(str));
	return 0;
}
