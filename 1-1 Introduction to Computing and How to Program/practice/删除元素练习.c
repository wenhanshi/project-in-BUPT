#include<stdio.h>
int m=10;
void del(int v[],int n)
{
	int j,i;
	for(i=0;i<m;i++)
	{
		if(v[i]==n)
		{
			for(j=i+1;j<m;j++)
			{
				v[j-1]=v[j];
			}
			i--;
			m--;
		}
	}
}
int main(void)
{
	int v[10];
	int n,i;
	for(i=0;i<=9;i++)
	{
		scanf("%d",&v[i]);
	}
	scanf("%d",&n);
	del(v,n);
	for(i=0;i<m;i++)
	{
		printf("%d ",v[i]);
	}
	return 0;
}
