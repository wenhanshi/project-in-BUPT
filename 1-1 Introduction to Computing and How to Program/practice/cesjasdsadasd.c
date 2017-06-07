#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[20],*temp=str;
	gets(str);
	temp++;
	while(*str++=*temp++);
	puts(str);
	return 0;
}
