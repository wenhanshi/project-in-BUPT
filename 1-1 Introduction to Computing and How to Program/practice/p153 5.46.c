#include<stdio.h>
int main(void)
{
	int c;
	if((c=getchar()!=EOF))
	{
		main();
		printf("%c",c);
	}
	return 0;
}

