#include<stdio.h>
char s[80];
void reverse(char s[])
{
	if(s[0]=='\0')
	{
		return ;
	}
	else
	{
		reverse(&s[1]);
		putchar(s[0]);
	}
}
int main(void)
{
	gets(s);
	reverse(s);
	return 0;
}
