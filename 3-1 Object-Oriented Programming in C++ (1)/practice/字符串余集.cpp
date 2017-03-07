#include<stdio.h>
#define MAXLEN 100 
int main(void)
{
	char s[100];
	char t[100];
	char r[100];
	int p[100];
	gets(s);
	gets(t);
	char* ps=s;
	char* pt=t;
	char *pr=r;
	int* pp=p;
	int count=1,lenp=0,flag;
	while(*ps)
	{
		flag=1;
		while(*pt&&flag)
		{
			if(*pt==*ps) flag=0;
			pt++;
		}
		if(flag)
		{
			*pr=*ps;
			pr++;
			*pp=count;
			pp++;
			lenp++;
		}
		ps++;
		count++;
		pt=t;
	}
	*pr='\0';
	puts(r);
	for(int i=0;i<=lenp-1;i++)
	{
		printf("%d ",p[i]);
	}
	return 0;
 } 
