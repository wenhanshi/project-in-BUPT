#include<stdio.h>
int main(void)
{
	int a[200],count=0,n,i,j,temp;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	fflush(stdin);
	for(i=0;i<=n-1;i++)
	{
		if(a[i]%2==0)
		{
			temp=a[i];
			for(j=i-1;j>=count;j--)
			{
				a[j+1]=a[j];
			}
			a[count++]=temp;
		}
	}
	for(i=0;i<=n-1;i++)
	{
		if(i<=n-2)
		printf("%d ",a[i]);
		else
		printf("%d\n",a[i]);
	}
	return 0;
}
