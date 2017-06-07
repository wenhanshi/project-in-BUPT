#include<stdio.h>
#define FROM 1
#define MED 2
#define TO 3
int move(int n,int from,int med,int to)
{
	if(n==1)
	{
		printf("n=%d,%d-->%d\n",n,from,to);
	}
	else
	{
		move(n-1,from,to,med);
		printf("n=%d,%d-->%d\n",n,from,to);
		move(n-1,med,from,to);
	}
}
int main(void)
{
	int n;
	scanf("%d",&n);
	move(n,FROM,MED,TO);
	return 0;
}
