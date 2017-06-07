#include<stdio.h>
void insertSort(int v[],int n)
{
	int pass,j,temp;
	for(pass=1;pass<=n-1;pass++)
	{
		temp=v[pass];
		for(j=pass;j>0&&v[j-1]>temp;j--)
		{
			v[j]=v[j-1];
		}
		v[j]=temp;
	}
}
int main(void)
{
	int v[1000],n,i;
	printf("Please input the number of interger:");
	scanf("%d",&n);
	printf("Please in put the integers:");
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&v[i]);
	}
	fflush(stdin);
	insertSort(v,n);
	printf("The result is:");
	for(i=0;i<=n-2;i++)
	{
		printf("%d ",v[i]);
	}
	printf("%d\n",v[n-1]);
	return 0;
}
