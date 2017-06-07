#include<stdio.h>
#define MAX 20
int searcharray(int*,int);
int main(void)
{
	int number[MAX]={0};
	int i=0,value;
	while(++i<=MAX)
	{
		printf("Enter a integer:");
		scanf("%d",&value);
		if(searcharray(number,value))
		{
			printf("%d\n",value);
		}
	}
}
int searcharray(int*serch,int num)
{
	int*temp=serch;
	while(serch<&temp[MAX]&&*serch&&*serch!=num)
	{
		++serch;
	}
	if(serch<&temp[MAX]&&*serch!=num)
	{
		return*serch=num;
	}
	return 0;
}
