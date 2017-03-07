#include<iostream>
#include<ctime>
#define MAX 100000000
using namespace std;
int a[MAX+1];
void insertSort(int arr[],int start,int end)
{
	int p;
	for(int i=start+1;i<=end;i++)
	{
		arr[0]=arr[i];
		for(p=i;p>=1;p--)
		{
			if(arr[0]<=arr[p]&&arr[0]>arr[p-1])//hint: <= must be put firstly to break
				break;
		}
		for(int j=i-1;j>=p;j--)
		{
			arr[j+1]=arr[j];
		}
		arr[p]=arr[0];
	}
}
int Partition(int arr[],int start,int end)
{
	int pivot;
	arr[0]=arr[start];
	pivot=arr[0];
	while(start<end)
	{
		while(start<end && arr[end]>=pivot)
		{
			end--;
		}
		arr[start]=arr[end];
		while(start<end && arr[start]<=pivot)
		{
			start++;
		}
		arr[end]=arr[start];
	}
	arr[start]=pivot;
	return start;
}
int findMax(int arr[],int start,int end)
{
	int mid=(start+end)/2;
	if(arr[start]<arr[end] && arr[mid]>arr[end])
		return end;
	if(arr[start]>arr[end] && arr[start]<arr[mid])
		return start;
	return mid;
}
int Partition_Int(int arr[],int start,int end)
{
	int pivot,p;
	p=findMax(arr,start,end);
	pivot=arr[p];
	arr[0]=arr[p];
	arr[p]=arr[start];
	while(start<end)
	{
		while(start<end && arr[end]>=pivot)
		{
			end--;
		}
		arr[start]=arr[end];
		while(start<end && arr[start]<=pivot)
		{
			start++;
		}
		arr[end]=arr[start];
	}
	arr[start]=pivot;
	return start;
}
void quickSort_Int(int arr[],int start,int end)
{
	int pivot;
	if(start<end)
	{
		pivot=Partition_Int(arr,start,end);
		quickSort_Int(arr,start,pivot-1);
		quickSort_Int(arr,pivot+1,end);
	}
}
void quickSort(int arr[],int start,int end)
{
	int pivot;
	if(start<end)
	{
		pivot=Partition(arr,start,end);
		quickSort(arr,start,pivot-1);
		quickSort(arr,pivot+1,end);
	}
}
void initArr_Rand(int arr[],int maxNum)
{
	arr[0]=17;
	for(int i=1;i<=maxNum;i++)
	{
		arr[i]=(arr[i-1]+34435453)%100000007;
	}
}
void initArr_Seq(int arr[],int maxNum)
{
	for(int i=1;i<=maxNum;i++)
	{
		arr[i]=MAX-i;
	}
}
void printArr(int arr[],int maxNum)
{
	for(int i=1;i<=maxNum;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(void)
{
	int time_s,time_e;
	initArr_Rand(a,MAX+1);
	time_s=clock();
	quickSort_Int(a,1,MAX+1);
	time_e=clock();
	cout<<"quickSort_Int(rand):"<<time_e-time_s<<endl;
	initArr_Rand(a,MAX+1);
	time_s=clock();
	quickSort(a,1,MAX+1);
	time_e=clock();
	cout<<"quickSort(rand):"<<time_e-time_s<<endl;
	initArr_Rand(a,MAX+1);
	time_s=clock();
	insertSort(a,1,MAX+1);
	time_e=clock();
	cout<<"insertSort(rand):"<<time_e-time_s<<endl;
	/*
	initArr_Seq(a,MAX+1);
	time_s=clock();
	quickSort_Int(a,1,MAX+1);
	time_e=clock();
	cout<<"quickSort_Int(seq):"<<time_e-time_s<<endl;
	initArr_Seq(a,MAX+1);
	time_s=clock();
	quickSort(a,1,MAX+1);
	time_e=clock();
	cout<<"quickSort(seq):"<<time_e-time_s<<endl;
	initArr_Seq(a,MAX+1);
	time_s=clock();
	insertSort(a,1,MAX+1);
	time_e=clock();
	cout<<"insertSort(seq):"<<time_e-time_s<<endl;
	*/
	return 0;
}
