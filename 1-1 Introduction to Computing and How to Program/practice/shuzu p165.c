#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 7
int main(void)
{
	int face[SIZE];
	int times=6000,i,j;
	srand(time(NULL));
	for(i=1;i<=times;i++)
	{
		face[rand()%6+1]++;
	}
	printf("Face\tTimes\n");
	for(j=1;j<=SIZE-1;j++)
	{
		printf("%d\t%d\n",j,face[j]);
	}
	return 0;
}
