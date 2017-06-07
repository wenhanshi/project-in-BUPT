#include<stdio.h>
#define MAX 7
int binSearch(int x,int*array,int n)
{
	int mid,low=0,high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(x<array[mid])
		{
			high=mid-1;
		}
		else if(x>array[mid])
		{
			low=mid+1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main(void)
{
	int test[MAX]={1,2,3,4,5,7,9};
	printf("%d",binSearch(6,test,MAX));
	return 0;
}
