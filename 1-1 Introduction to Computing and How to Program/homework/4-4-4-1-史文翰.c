#include<stdio.h>
int main(void)
{
	char type;
	int i,amount;
	double sum=0;
	for(i=1;i<=5;i++)
	{
		printf("周%d销售情况:\n",i);
		while((type=getchar())!=EOF)
		{
			scanf("%d",&amount);
			switch(type)
			{
				case '1':
					sum+=amount*2.98;
					break;
				case '2':
					sum+=amount*4.50;
					break;
				case '3':
					sum+=amount*9.98;
					break;
				case '4':
					sum+=amount*4.49;
					break;
				case '5':
					sum+=amount*6.87;
				default:
					break;
			}
			getchar();
		}
	}
	printf("本周销售总额为:%lf",sum);
	return 0;
}
