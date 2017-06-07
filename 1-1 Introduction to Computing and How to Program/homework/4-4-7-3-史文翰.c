#include<stdio.h>
int search(int*v,int n,int x)
{
	for(int i=0;i<=n-1;i++)
	{
		if(v[i]==x)
		{
			return i;
		}
	}
	return -1;
}
int main(void)
{
	int n,np,p,y;
	int v[100];
	scanf("%d",&n);
	getchar();
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&v[i]);
	}
	getchar();
	scanf("%d",&np);
	for(int i=1;i<=np;i++)
	{
		scanf("%d",&p);
		y=search(v,n,p);
		if(y==0)
		{
			printf("%d\n",v[1]);
		}
		else if(y==n-1)
		{
			printf("%d\n",v[n-2]);
		}
		else if(y==-1)
		{
			printf("NULL\n");
		}
		else
		{
			printf("%d %d\n",v[y-1],v[y+1]);
		}
	}
	return 0;
}
