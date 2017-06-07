#include<stdio.h>
#include<time.h>
#include<windows.h>
void time_Count(int dur)
{
	clock_t start,finish;
	int total=0;
	start=clock();
	while(total<dur)
	{
		finish=clock();
		total=(finish-start)/CLOCKS_PER_SEC;
	}
}

int main(void)
{
	int downCount;
	scanf("%d",&downCount);
	for(int i=downCount;i>=1;i--)
	{
		time_Count(1);
		printf("%d\n",i);
	}
	time_Count(1);
	printf("Over!");
	
	return 0;
}

