#include<stdio.h>
char*locateSubStr(char*str1,char*str2)
{
	char*ptr1=NULL;
	char*ptr2=str2;
	while(*str1&&*str2)
	{
		if(*str1==*str2)
		{
			if(ptr1==NULL)
			{
				ptr1=str1;
			}
			str2++;
		}
		else
		{
			str2=ptr2;
			ptr1=NULL;
		}
		str1++;
	}
	if(!*str2)
	{
		return ptr1;
	}
	return NULL;
}
int main(void)
{
	char*ptr=NULL;
	char str1[500],str2[500];
	gets(str1);
	gets(str2);
	ptr=locateSubStr(str1,str2);
	if(ptr==NULL)
	{
		
		printf("NULL!");
	}
	else
	{
		while(*ptr)
		{
			printf("%c",*ptr);
			ptr++;
		}
	}
	return 0;
}
