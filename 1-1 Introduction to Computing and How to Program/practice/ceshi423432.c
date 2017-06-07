#include<stdio.h>
char**lineptr,**temp;
int main(void)
{
	int i,n,len;
	scanf("%d",&n);
	lineptr=malloc(sizeof(char*)*n);
	scanf("%d",&len);
	temp=lineptr;
	getchar();
	for(i=0;i<=n-1;i++)
	{
		*(temp++)=malloc(sizeof(char)*len);
	}
	temp=lineptr;
	for(i=0;i<=n-1;i++)
	{
		gets(temp++);
	}
	for(i=0;i<=n-1;i++)
	{
		printf("%s\n",lineptr++);
	}
	return 0;
}
