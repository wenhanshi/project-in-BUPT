#include<stdio.h>
int main(void)
{
	int a[10];
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	fflush(stdin);
	for(int pass=1;pass<=9;pass++)
	{
		for(int i=0;i<=9-pass;i++)
		{
			if(a[i]>a[i+1])
			{
				int temp;
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
	for(int i=0;i<=9;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
