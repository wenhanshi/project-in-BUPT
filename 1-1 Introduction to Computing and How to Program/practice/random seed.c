#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i,j;
	unsigned seed;
	scanf("%u",&seed);
	srand(seed);
	for(j=1;;j++)
	{
		for(i=1;i<=10;i++)
		{
			printf("%2d",(rand()%10));
		}
	system("pause");
	}
	return 0;
}
