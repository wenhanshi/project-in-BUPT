#include<stdio.h>
#define SIZE 10
int main(void)
{
	int i,j;
	int sample[SIZE]={10,3,6,12,4,5,7,9,11,2};
	printf("%s\t%s\t%s\n","Number","Value","Chart");
	for(i=0;i<=SIZE-1;i++)
	{
		printf("%d\t%d\t",i,sample[i]);
		for(j=1;j<=sample[i];j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
