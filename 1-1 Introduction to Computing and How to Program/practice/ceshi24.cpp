#include<stdio.h>
int main(void)
{
	int i;
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	for(i=0;i<=9;i++)
	{
		printf("%p\n",a+i);
	}
	for(i=0;i<=9;i++)
	{
		printf("%d\n",*(a+i));
	}
	return 0;
}
