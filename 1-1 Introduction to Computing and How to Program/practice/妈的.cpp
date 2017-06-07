#include<stdio.h>
#define length 10
int *head,*tail;
void inqueue(int v[],int x)
{
	if(tail+1==head)
	{
		printf("The queue is full.\n");
	}
	else *tail=x;
	if(tail-v+1==length)
	{
		tail=v;
	}
	else
	{
		tail++;
	}
}
int dequeue(int v[])
{
	int temp=*head;
	if(head==tail)
	{
		printf("The queue is empty.\n");
		return -1;
	}
	else if(head-v+1==length)
	{
		head=v;
	}
	else
	{
		head++;
	}
	return temp;
}
int main(void)
{
	int v[length]={0,3,4,6,0,0,0,0};
	head=v+1;
	tail=v+4;
	inqueue(v,999);
	for(int i=0;i<=9;i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	printf("\n%d ",dequeue(v));
	
	return 0;
}
