#include<stdio.h>
#define SIZE 10
void f(int[],int);
int main(void)
{
	int a[SIZE]={32,27,64,18,95,14,90,70,60,37};
	printf("The value in the array are:\n");
	f(a,SIZE);
	printf("\n");
	return 0;
}
f(int b[],int size)
{
	if(size>0)
	{
		f(&b[1],size-1);
		printf("%d ",b[0]);
	}
}
