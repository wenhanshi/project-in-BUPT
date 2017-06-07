#include<stdio.h>
void formRotSquare(int v[][100],int n)
{
	int low=0,high=n-1,count=1,i;
	while(low<=high)
	{
		for(i=n-high-1;i<=high-1;i++)
		{
			v[low][i]=count++;
		}
		for(i=n-high-1;i<=high-1;i++)
		{
			v[i][high]=count++;
		}
		for(i=high;i>=low+1;i--)
		{
			v[high][i]=count++;
		}
		for(i=high;i>=low+1;i--)
		{
			v[i][low]=count++;
		}
		low++;
		high--;
	}
	if(n%2!=0)
	{
		v[(n-1)/2][(n-1)/2]=count;
	}
}
int main(void)
{
	int v[100][100];
	int n;
	printf("Please input the row:");
	scanf("%d",&n);
	formRotSquare(v,n);
	printf("The result is:\n");
	for(int row=0;row<=n-1;row++)
	{
		for(int col=0;col<=n-1;col++)
		{
			printf("%d ",v[row][col]);
		}
		printf("\n");
	}
	return 0;
}
