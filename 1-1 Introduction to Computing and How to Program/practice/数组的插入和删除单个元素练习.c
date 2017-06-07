#include<stdio.h>
#define MAX 10
void innum(int v[],int loc,int num,int max)
{
	for(int i=max-2;i>=loc;i--)
	{
		v[i+1]=v[i];
	}
	v[loc]=num;
}
void outnum(int v[],int loc,int max)
{
	for(int i=loc+1;i<=max-1;i++)
	{
		v[i-1]=v[i];
	}
}
void print(int v[],int max)
{
	for(int i=0;i<=max-1;i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
}
int main(void)
{
	int a[MAX]={1,2,3,4,5,6,7,8,9,0};
	innum(a,3,100,MAX);
	print(a,MAX);
	outnum(a,3,MAX);
	print(a,MAX-1);
	return 0;
}
