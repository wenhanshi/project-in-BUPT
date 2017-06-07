#include<stdio.h>
#define MAX 5
void bubbleSort(int v[],int n)
{
	int temp;
	for(int pass=1;pass<=MAX-1;pass++)
	{
		for(int i=0;i<=MAX-1-pass;i++)
		{
			if(v[i]>v[i+1])
			{
				temp=v[i];
				v[i]=v[i+1];
				v[i+1]=temp;
			}
		}
	}
}
void print(int v[],int n)
{
	for(int i=0;i<=n-1;i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
}
int main(void)
{
	int a[5]={9,3,7,1,4};
	bubbleSort(a,5);
	print(a,5);
	return 0;
}
