#include<stdio.h>
#include<stdlib.h>
#define SIZE 6
void mean(int []);
void order(int []);
void median(int []);
int main(void)
{
	int data[SIZE]={2,1,2,3,10,11};
	mean(data);
	median(data);
	system("pause");
 	return 0;
}
void mean(int sample[])
{
	int i,sum=0;
	float result;
 	printf("******Let's do mean******\n");
 	for(i=0;i<=SIZE-1;i++)
	{
		sum+=sample[i];
	}
	result=(float)sum/SIZE;
	printf("The mean is:%.2f\n",result);
}
void order(int sample[])
{
	int pass,j,hold,i;
	for(pass=1;pass<=SIZE-1;pass++)
	{
  		for(j=0;j<=SIZE-2;j++)
		{
   			if(sample[j]>sample[j+1])
			{
				hold=sample[j];
	   			sample[j]=sample[j+1];
	   			sample[j+1]=hold;
			}
		}
	}
	for(i=0;i<=SIZE-1;i++)
	{
		printf("%3d",sample[i]);
	}
	printf("\n");
}		
void median(int sample[])
{
	order(sample);
	printf("******Let's do median******\n");
	if(SIZE%2!=0)
	{
		printf("The middle is:%d",sample[SIZE/2]);
	}
	else
	{
		printf("The middle is:%.2f",(float)(0.5*(sample[SIZE/2-1]+sample[SIZE/2])));
	}
}
