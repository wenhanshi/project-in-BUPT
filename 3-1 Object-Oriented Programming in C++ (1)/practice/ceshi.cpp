#include<stdio.h>
#include<string.h>
int main(void)
{
	char s[10]="D";
	char t[10];
	strncpy(t,&s[0],0);
	printf("%d %d",t[0],t[1]);
	return 0;
}
