#include<stdio.h>
char*match(char*str,char ch)
{
	while(str++)
	{
		if(*str==ch)
		{
			return str;
		}
	}
	return NULL;
}
int main(void)
{
	char*str;
	char ch;
	gets(str);
	ch=getchar();
	if(match(str,ch))
	{
		puts(match(str,ch));
	}
	else
	{
		printf("fuck");
	}
	return 0;
}
