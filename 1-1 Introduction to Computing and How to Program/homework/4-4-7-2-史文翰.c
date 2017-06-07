#include<stdio.h>
void bubbleSort(int*a,int n)
{
	int i,j,temp;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2;j++)
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
	int a[100],sum=0;
	int n;
	double ave;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	ave=(double)sum/n;
	bubbleSort(a,n);
	printf("ave=%lf\nmax=%d,min=%d",ave,a[0],a[n-1]);
	return 0;
}
