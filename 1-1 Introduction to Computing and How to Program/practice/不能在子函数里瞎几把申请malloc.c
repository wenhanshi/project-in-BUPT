#include<stdio.h>
void getM(char*q)
{
	q=malloc(100);
}
int main(void)
{
	char**p=NULL;
	char*q=NULL;
	p=&q;
	getM(q);
	strcpy(q,"fuck u");
	puts(q);
	return 0;
}
