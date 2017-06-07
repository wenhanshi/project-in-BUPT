#include<stdio.h>
void bubbleSort(int*a,int n)
{
	int i,j,temp;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(a[j]<a[j+1])
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
	int a[100],b[100];
	int n,m,i;
	scanf("%d",&n);
	getchar();
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<=n-1;i++)
	{
		b[i]=a[i];
	}
	getchar();
	bubbleSort(b,n);
	scanf("%d",&m);
	getchar();
	for(i=0;i<=n-1;i++)
	{
		if(a[i]==b[m-1])
		{
			break;
		}
	}
	printf("a[%d]=%d",i,a[i]);
	return 0;
}
