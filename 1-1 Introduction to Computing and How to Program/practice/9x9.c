#include<stdio.h>
#define M 20
#define N 10
void print(int [][N]);
int main(void)
{
	int i,j,m,n;
	int multiply[M][N]={0};
	for(i=0;i<=M-1;i++)
	{
		multiply[i][0]=i;
	}
	for(j=0;j<=N-1;j++)
	{
		multiply[0][j]=j;
	}
	for(m=1;m<=M-1;m++)
	{
		for(n=1;n<=N-1;n++)
		{
			multiply[m][n]=m*n;
		}
	}
	print(multiply);
	return 0;
}
void print(int multiply[][N])
{
	int i,j;
	for(i=0;i<=M-1;i++)
	{
		for(j=0;j<=N-1;j++)
		{
			printf("%5d",multiply[i][j]);
		}
		printf("\n");
		j=0;
	}
}
