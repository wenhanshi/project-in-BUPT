#include<stdio.h>
int atoi(char*s)
{
	int i,number;
	for(i=0;s[i]>='0'&&s[i]<='9';i++)
	{
		number=number*10+s[i]-'0';
	}
	return number;
}
