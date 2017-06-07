#include<stdio.h>
int**Create2(int n,int m)
{
	int **a;
	a=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<=n-1;i++)
	{
		a[i]=(int*)malloc(sizeof(int)*m);
	}
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=m-1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	return a;
}
int main(void)
{
	int n,m,**p;
	scanf("%d%d",&n,&m);
	p=Create2(n,m);
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=m-1;j++)
		{
			printf("%d ",-10*p[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<=n-1;i++)
	{
		free(p[i]);
	}
	free(p);
}
