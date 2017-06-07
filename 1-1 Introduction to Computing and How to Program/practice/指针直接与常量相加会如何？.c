#include<stdio.h>
int main(void)
{
	char*p="%d,a=%d,b=%d\n";
	int a=1,b=2,c=3;
	p+=3;
	printf(p,a,b,c);
	return 0;
}
