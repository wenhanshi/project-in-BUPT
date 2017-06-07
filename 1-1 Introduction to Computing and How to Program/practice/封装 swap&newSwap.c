#include<stdio.h>
void swap(int x,int y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
	printf("%d %d\n",x,y);
}
void newSwap(int*px,int*py)
{
	int temp;
	temp=*px;
	*px=*py;
	*py=temp;
}
void swapArray(int*v,int i,int j)
{
	int temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}
int main(void)
{
	int x=2,y=3,v[5]={1,2,3,4,5};
	swap(x,y);
	printf("%d %d\n",x,y);
	newSwap(&x,&y);
	printf("%d %d\n",x,y);
	swapArray(v,1,4);
	for(int i=0;i<=4;i++)
	{
		printf("%d ",v[i]);
	}
	return 0;
}
