#include<stdio.h>
void delcharfun(char str[],char ch)
{
	int i=0,j=0;
	for(i,j;str[i]!='\0';i++)
	{
		if(str[i]!=ch)
		{
			str[j++]=str[i];
		}
	}
	str[j]='\0';
}
int main(void)
{
	char str[100],ch;
	gets(str);
	fflush(stdin);
	scanf("%c",&ch);
	delcharfun(str,ch);
	if(str[0]!='\0')
	{
		for(int i=0;str[i]!='\0';i++)
		{
			printf("%c",str[i]);
		}
	}
	return 0;
}
