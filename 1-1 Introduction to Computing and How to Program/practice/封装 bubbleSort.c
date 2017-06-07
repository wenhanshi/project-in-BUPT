#include<stdio.h>
#define MAX 5
void bubbleSort(int*a,int n)
{
	int i,j,temp;
	for(pass=1;pass<=n-1;pass++)//for(loc=size-1;loc>=1;loc--)
	{
		for(i=0;i<=n-pass-1;i++)//for(i=0;i<=loc-1;i++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main(void)
{
	int i;
	int a[MAX]={4,7,10,3,6};
	bubbleSort(a,5);
	for(i=0;i<=MAX-1;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
