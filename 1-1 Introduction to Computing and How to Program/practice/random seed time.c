#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int i,j;
	srand(time(NULL));
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
