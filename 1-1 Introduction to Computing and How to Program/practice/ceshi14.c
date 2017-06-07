#include<stdio.h>
int main(void)
{
	char c,s[80];
	int i=0;
	puts("hahahahahahaha\n");
	while((c=getchar())!='\n')
	{
		s[i]=c;
		i++;
	}
	puts(s);
	return 0;
}
