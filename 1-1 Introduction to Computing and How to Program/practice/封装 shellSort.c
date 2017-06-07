#include<stdio.h>
#define MAX 5
void shellSort(int*v,int n)
{
	int gap,temp,i,j;
	for(gap=n/2;gap>0;gap/=2)//store the longest gap,half of the former
	{
		for(i=gap;i<=n-1;i++)//in such gap,move the standard within the same gap
		{
			for(j=i-gap;j>=0&&v[j]>v[j+gap];j-=gap)//examine every two numbers which in such gap
			{
				temp=v[j+gap];
				v[j+gap]=v[j];
				v[j]=temp;
			}
		}
	}
}
int main(void)
{
	int i;
	int a[MAX]={4,7,10,3,6};
	shellSort(a,5);
	for(i=0;i<=MAX-1;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
