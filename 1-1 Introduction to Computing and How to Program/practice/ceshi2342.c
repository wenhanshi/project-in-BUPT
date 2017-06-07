#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n;
	enum boolean{
		NO=10000,YES
	};
	printf("%d %d",NO,YES);
	int *p;
	p=malloc(sizeof(int)*n);
	n=10;
	for(int i=0;i<=n-1;i++)
	{
		*(p++)=i;
	}
	for(int i=0;i<=n-1;i++)
	{
		printf("%d ",*(p-i));
	}
	return 0;
}
