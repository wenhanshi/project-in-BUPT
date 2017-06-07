#include<stdio.h>
#include<string.h>
void get(char**p)
{
	*p=malloc(100);
}
int main(void)
{
	char**str=NULL;
	get(str);
	strcpy(*str,"hello");
	puts(*str);
	return 0;
}
//in function "get",input the pointer "p"
