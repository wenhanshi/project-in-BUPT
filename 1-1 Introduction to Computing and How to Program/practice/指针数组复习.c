#include<stdio.h>
#include<string.h>
#define ALO1 malloc(n*sizeof(char*))
#define ALO2 malloc(m*sizeof(char))
#define LOOP for(int i=0;i<=n-1;i++)
void bubbleSort(char**v,int n)
{
	char*ptr=NULL;
	for(int pass=1;pass<=n-1;pass++)
	{
		for(int i=0;i<=n-pass-1;i++)
		{
			if(strcmp(v[i],v[i+1])>0)
			{
				ptr=v[i];
				v[i]=v[i+1];
				v[i+1]=ptr;
			}
		}
	}
}
int main(void)
{
	int n,m;
	char**p;
	scanf("%d%d",&n,&m);
	p=ALO1;
	if(p==NULL)
	{
		printf("FUCK u");
	}
	getchar();
	LOOP
	{
		p[i]=ALO2;
		if(p[i]==NULL)
		{
			printf("fuck u ");
		}
		gets(p[i]);
	}
	bubbleSort(p,n);
	LOOP
	{
		puts(p[i]);
	}
	return 0;
}
