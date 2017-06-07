#include<stdio.h>
int main(void)
{
	int x=3,y;
	do
	{
		y=x--;
		if(!y)
		{
			printf("*");
			system("pause");
			continue;
		}
		printf("#");
	}
	while(1<=x<=2);
	return 0;
}
