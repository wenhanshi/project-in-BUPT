#include<stdio.h>
int strcmp(char*s,char*t)
{
	for(;*s==*t;s++,t++)
	{
		;
	}
	return *s-*t;
}
int main(void)
{
	char s[100],t[100];
	gets(s);
	gets(t);
	printf("%d",strcmp(s,t));
	return 0;
}
