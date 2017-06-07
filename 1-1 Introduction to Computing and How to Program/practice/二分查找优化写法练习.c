#include<stdio.h>
int search(int v[],int num,int low,int high)
{
	int middle;
	middle=(low+high)/2;
	if(low<=high)
	{
		if(num==v[middle])
		{
			return middle;
		}
		else if(num>v[middle])
		{
			return search(v,num,middle+1,high);
		}
		else
		{
			return search(v,num,low,middle-1);
		}
	}
	return -1;
}
int main(void)
{
	int a[5]={1,2,3,4,5};
	printf("%d",search(a,7,0,4));
	return 0;
}
