#include<stdio.h>

int sum(int* S,int* top)
{
	int *temp=S;
	int SUM=0;
	while(temp!=top)
	{
		SUM+=*temp;
		temp++;
	}
	return SUM;
 } 
void printS(int* S,int* top)
{
	int* temp=S;
	while(temp!=top)
	{
		printf("%d ",*temp);
		temp++;
	}
	printf("\n");
}
int main(void)
{
	int S[100];
	int num[100];
	int weight,n;
	
	int* base=S;
	int* top=S;
	int cur=0;
	int p=0;
	
	printf("input the weight:\n");
	scanf("%d",&weight);
	printf("input the number of things:\n");
	scanf("%d",&n);
	printf("input the weight of each:\n");
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&num[i]);
	}
	
	S[0]=num[0];
	top++;
	cur++;
	while(*base!=num[n-1])
	{
		if(sum(S,top)==weight)
		{
			printS(S,top);
			top--;
			*top=num[cur];
			cur++;
		}
		else if(sum(S,top)<weight)
		{
			if(cur==n-1)
			{
				top--;
				cur=p+1;
			}
			else
			{
			
				p=cur;
				*top=num[cur];
				top++;
				cur++;
			}
		}
		else//sum>weight
		{
			top--;
			if(cur==n-1)
			{
				cur=p+1;
			}
			else
			{
				cur++;
			}
		}
	}
	return 0;
 } 
