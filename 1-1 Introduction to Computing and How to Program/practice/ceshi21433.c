#include<stdio.h>
#define LOOP for(int i=0;i<=9;i++)
int main(void)
{
	float f=3.1415926;
	LOOP
	{
		printf("%.*g\n",i,f);
	}
	return 0;
}
