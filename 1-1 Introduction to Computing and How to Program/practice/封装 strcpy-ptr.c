#include<stdio.h>
void strcpy(char*s,char*t)
{
	while(*s++=*t++)
	{
		;
	}
}
int main(void)
{
	char s[100];
	char t[]="hello";
	strcpy(s,t);
	puts(s);
	return 0;
}
