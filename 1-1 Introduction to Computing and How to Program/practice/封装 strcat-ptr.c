#include<stdio.h>
void strcat(char*s,char*t)
{
	while(*s)
	{
		s++;
	}
	while(*s++=*t++)
	{
		;
	}
}
int main(void)
{
	char s[100],t[100];
	gets(s);
	gets(t);
	strcat(s,t);
	puts(s);
	return 0;
}
