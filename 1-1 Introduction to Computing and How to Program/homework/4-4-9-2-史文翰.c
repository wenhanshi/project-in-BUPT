#include<stdio.h>
int recurBinarySearch(int v[],int key,int low,int high)
{
	int middle;
	if(low>high)
	{
		return -1;
	}
	middle=(low+high)/2;
	if(v[middle]==key)
	{
		return middle;
	}
	else
	{
		if(key>=v[middle])
		{
			return recurBinarySearch(v,key,middle+1,high);
		}
		else
		{
			return recurBinarySearch(v,key,low,middle-1);
		}
	}
}
int main(void)
{
	int v[100000],i,m,n,p;
	scanf("%d %d",&n,&m);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&v[i]);
	}
	for(i=0;i<=m-1;i++)
	{
		scanf("%d",&p);
		printf("%d ",recurBinarySearch(v,p,0,n-1));
	}
	return 0;
}
