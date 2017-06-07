#include<stdio.h>
int main(void)
{
	int test[2][3]={1,2,3,4,5,6,};
	int i,j;
	for(i=0;i<=1;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("%3d",test[i][j]);
		}
		printf("\n");
		j=0;
	}		
}
