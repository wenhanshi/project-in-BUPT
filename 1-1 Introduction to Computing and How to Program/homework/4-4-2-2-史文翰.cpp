#include<stdio.h>
int main(void)
{
	int n,m,i;
	int j=0;
	
	printf("Please input two integers:");
	scanf("%d%d",&n,&m);
	if(n>10000)
	{
		printf("your data is not fit for the promble.");
	}
	else
	{
		printf("The result is:\n");
		for(i=1;i<=n;i++)
		{
			if((i/m)==(i/1000)*(i/1000)+(i%1000/100)*(i%1000/100)+(i%100/10)*(i%100/10)+(i%10)*(i%10))
			{
				printf("%d\t",i);
				j++;
				if(j!=0&&j%5==0)
				{
					printf("\n");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
