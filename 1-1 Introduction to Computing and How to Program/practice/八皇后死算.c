#include<stdio.h>
int mark[7];
int mark1[7];
int mark2[7];
int count;
int orderJudge(int*a)
{
	int i,j,h,flag;
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=6;j++)
		{
			if(a[j]>a[j+1])
			{
				h=a[j];
				a[j]=a[j+1];
				a[j+1]=h;
			}
		}
	}
	i=0,flag=1;
	while(flag&&i<=6)
	{
		if(a[i]!=a[i+1])
		{
			i++;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void print(int*a)
{
	int i;
	for(i=0;i<=7;i++)
	{
		printf("row:%d,col:%d\n",i,a[i]);
	}
	count++;
}
int main(void)
{
	int i;
	for(mark[0]=0;mark[0]<=7;mark[0]++)
	{
		for(mark[1]=0;mark[1]<=7;mark[1]++)
		{
			if(mark[1]!=mark[0])
			for(mark[2]=0;mark[2]<=7;mark[2]++)
			{
				if(mark[2]!=mark[0]&&mark[2]!=mark[1])
				for(mark[3]=0;mark[3]<=7;mark[3]++)
				{
					if(mark[3]!=mark[0]&&mark[3]!=mark[1]&&mark[3]!=mark[2])
					for(mark[4]=0;mark[4]<=7;mark[4]++)
					{
						if(mark[4]!=mark[0]&&mark[4]!=mark[1]&&mark[4]!=mark[2]&&mark[4]!=mark[3])
						for(mark[5]=0;mark[5]<=7;mark[5]++)
						{
							if(mark[5]!=mark[0]&&mark[5]!=mark[1]&&mark[5]!=mark[2]&&mark[5]!=mark[3]&&mark[5]!=mark[4])
							for(mark[6]=0;mark[6]<=7;mark[6]++)
							{
								if(mark[6]!=mark[0]&&mark[6]!=mark[1]&&mark[6]!=mark[2]&&mark[6]!=mark[3]&&mark[6]!=mark[4]&&mark[6]!=mark[5])
								for(mark[7]=0;mark[7]<=7;mark[7]++)
								{
									if(mark[7]!=mark[6]&&mark[7]!=mark[5]&&mark[7]!=mark[4]&&mark[7]!=mark[3]&&mark[7]!=mark[2]&&mark[7]!=mark[1]&&mark[7]!=mark[0])
									for(i=0;i<=7;i++)
									{
										mark1[i]=mark[i]+i;
									}
									for(i=0;i<=7;i++)
									{
										mark2[i]=mark[i]-i;
									}
									if(orderJudge(mark1)==1&&orderJudge(mark2)==1)
									{						
										print(mark);
										printf("\n");
									}
								}
							}
						}
					}
				}	
			}
		}
	}
	printf("%d",count);	
	return 0;
}
