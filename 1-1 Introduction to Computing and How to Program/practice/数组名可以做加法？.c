#include<stdio.h>
int main(void)
{
	int a[]={1,1,1,1,1,1,1,1,1};
	printf("%d",a[*(a+a[3])]);
	return 0;
}
