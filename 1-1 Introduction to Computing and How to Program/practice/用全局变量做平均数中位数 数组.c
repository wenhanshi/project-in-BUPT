#include<stdio.h>
#include<stdlib.h>
#define SIZE 6
int data[SIZE]={2,1,3,3,3,7};
void mean(int []);
void order(int []);
void median(int []);
void mode(int []);
int main(void)
{
	mean(data);
	median(data);
	mode(data);
	system("pause");
 	return 0;
}
void mean(int data[])
{
	int i,sum=0;
	float result;
 	printf("******Let's do mean******\n");
 	for(i=0;i<=SIZE-1;i++)
	{
		sum+=data[i];
	}
	result=(float)sum/SIZE;
	printf("The mean is:%.2f\n",result);
}
void order(int data[])
{
	int pass,j,hold,i;
	for(pass=1;pass<=SIZE-1;pass++)
	{
  		for(j=0;j<=SIZE-2;j++)
		{
   			if(data[j]>data[j+1])
			{
				hold=data[j];
	   			data[j]=data[j+1];
	   			data[j+1]=hold;
			}
		}
	}
}		
void median(int data[])
{
	order(data);
	printf("******Let's do median******\n");
	if(SIZE%2!=0)
	{
		printf("The middle is:%d\n",data[SIZE/2]);
	}
	else
	{
		printf("The middle is:%.2f\n",(float)(0.5*(data[SIZE/2-1]+data[SIZE/2])));
	}
}
void mode(int data[])
{
	int freq[10]={0};
	int i,j,largest;
	order(data);
	for(i=0;i<=SIZE-2;i++)
	{
		if(data[i]==data[i+1])
		{
			freq[data[i]]++;
		}
	}
	for(j=0;j<=9;j++)
	{
		if(freq[j]>freq[j+1])
		{
			largest=j;
		}
	}
	printf("******Let's do mode******\n");
	printf("The mode is:%d",largest);
	
}
void monitor(int data[])
{
	int i;
	for(i=0;i<=SIZE-1;i++)
	{
		printf("%3d",data[i]);
	}
	printf("\n");
}
