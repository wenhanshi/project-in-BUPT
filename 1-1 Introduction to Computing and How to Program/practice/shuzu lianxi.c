#include<stdio.h>
#define SAMPLE_SIZE 20
#define RATING_SIZE 11
int main(void)
{
	int i,j;
	int sample[SAMPLE_SIZE]={2,2,3,4,5,6,7,5,5,3,3,2,3,4,5,8,9,3,2,3};
	int rating[RATING_SIZE]={0};
	for(i=0;i<=SAMPLE_SIZE-1;i++)
	{
		rating[sample[i]]++;
	}
	printf("%s\t%s\n","Rate","Frequency");
	for(j=1;j<=RATING_SIZE-1;j++)
	{
		printf("%d\t%d\n",j,rating[j]);
	}
	return 0;
}
