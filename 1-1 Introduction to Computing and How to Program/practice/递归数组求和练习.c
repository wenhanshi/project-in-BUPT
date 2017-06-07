#include<stdio.h>
int sum(int v[],int size)
{
	if(size==1)
	return v[0];
	else
	{
		return sum(&v[1],size-1)+v[0];
	}
}
int main(void)
{
	int a[5]={1,2,3,4,5};
	printf("%d",sum(a,5));
	return 0;
}
