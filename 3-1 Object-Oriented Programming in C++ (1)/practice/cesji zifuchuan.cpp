#include<stdio.h>
#include<string.h>
char sor[100]="hahaha";

char* f(void)
{
	return sor;
}

int main(void)
{
	char *p;
	p=f();
	puts(p);
	return 0;
}
