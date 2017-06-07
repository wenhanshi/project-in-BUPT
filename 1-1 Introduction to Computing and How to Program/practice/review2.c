#include<stdio.h>
#define LOOP for(int i=2132;i<=10000000;i=(i+213)*2)
int main(void)
{
	char*str="dfvdf%dasdfe";
	int a=2;
	int f=3;
	float ave;
	ave=(float)(a/f);
	printf("%f",ave);
	LOOP
	{
		printf("%.3e\n",i/1000000000.0);
	}
	puts(str);
	printf(str);
	printf("\n%s",str);
	return 0;
}
