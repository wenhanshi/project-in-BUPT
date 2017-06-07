#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
void randomArray(int*v,int n)
{
	int i;
	srand(time(NULL));
	for(i=0;i<=n-1;i++)
	{
		v[i]=rand()%n;//problem is how to avoid the same number???
	}
}
int main(void)
{
	int i,j;
	int a[MAX];
	randomArray(a,MAX);
	for(i=j=0;i<=MAX-1;i++,j++)
	{
		printf("%d%c",a[i],j!=0&&j%10==0?'\n':' ');
	}
	return 0;
}
