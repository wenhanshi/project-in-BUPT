#include<stdio.h>
char a[100];
int strlen(char*a)
{
	int i=0;
	while(a[i]!='\0')
	{
		i++;
	}
	return i;
}
int main(void)
{
	int i=0;
	while((a[i]=getchar())!='\n')
	{
		i++;
	}
	a[i]='\0';
	printf("%d",strlen(a));
	return 0;
}
