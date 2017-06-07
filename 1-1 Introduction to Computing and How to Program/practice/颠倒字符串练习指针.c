#include<stdio.h>
reverse(char*v)
{
	char temp;
	char*i,*j;
	for(i=v,j=v+strlen(v)-1;i<j;i++,j--)
	{
		temp=*i;
		*i=*j;
		*j=temp;
	}
}
int main(void)
{
	char str[20];
	gets(str);
	reverse(str);
	puts(str);
	return 0;
}
