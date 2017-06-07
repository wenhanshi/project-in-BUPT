#include<stdio.h>
int data[100][100];
int findRowMax(int data[][100],int row,int maxCol)
{
	int max=0,imax=0;
	for(int i=0;i<=maxCol-1;i++)
	{
		if(data[row][i]>max)
		{
			max=data[row][i];
			imax=i;
		}
	}
	return imax;
}
int findColMin(int data[][100],int col,int maxRow)
{
	int min=999,imin;
	for(int i=0;i<=maxRow-1;i++)
	{
		if(data[i][col]<min)
		{
			min=data[i][col];
			imin=i;
		}
	}
	return imin;
}
int main(void)
{
	int count=0,row,col,maxRow,maxCol,rowNeed,colNeed;
	scanf("%d*%d",&maxRow,&maxCol);
	for(row=0;row<=maxRow-1;row++)
	{
		for(col=0;col<=maxCol-1;col++)
		{
			scanf("%d",&data[row][col]);
		}
	}
	fflush(stdin);
	row=col=0;
	while(row<=maxRow-1)
	{
		colNeed=findRowMax(data,row,maxCol);
		rowNeed=findColMin(data,colNeed,maxRow);
		if(row==rowNeed)
		{
			count++;
			printf("The %d point is:%d.\n",count,data[row][colNeed]);
		}
		row++;
	}
	if(count==0)
	{
		printf("There is no point that u want.");
	}
	return 0;
}
