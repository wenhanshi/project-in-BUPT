#include<stdio.h>
#define SIZE 10
int a[10];
int search(int [],int,int,int);
int main(void)
{
	int i;
	int key;
	for(i=0;i<=SIZE-1;i++)
	{
		a[i]=i*i;
	}
	printf("Enter your key:");
	scanf("%d",&key);
	printf("\nresult:%d",search(a,0,SIZE-1,key));
	return 0;
}
int search(int a[],int low,int high,int key0)
{
	int middle;
	while(low<=high)
	{
		middle=(low+high)/2;
		if(a[middle]==key0)
		{
			return middle;
		}
		else if(a[middle]>key0)
		{
			high=middle-1;
		}
		else
		{
			low=middle+1;
		}
	}
}
