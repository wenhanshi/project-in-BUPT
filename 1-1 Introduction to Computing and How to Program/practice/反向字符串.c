#include<stdio.h>
#include<string.h>
int main(void)
{
	int i,j,h;
	char a[100];
	gets(a);
	for(i=0,j=strlen(a)-1;i<j;i++,j--)
	{
		h=a[i];
		a[i]=a[j];
		a[j]=h;
	}
	puts(a);
	return 0;
}
