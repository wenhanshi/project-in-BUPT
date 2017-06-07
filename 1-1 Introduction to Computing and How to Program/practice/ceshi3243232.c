#include<stdio.h>
#include<string.h>
int main(void)
{
	char *p;
	char *s="hello";
	strcpy(p,s);
	puts(p);
	return 0;
}
//unseen the point of p
//mark:p=malloc(100)
