#include<stdio.h>
int main(void)
{
	int flag=1;
	int x,y;
	int r;
	int h;
	scanf("%d%d",&x,&y);
	if(x<y)
	{
		r=x;
		x=y;
		y=r;
	}
	else
	{
		while(1)
		{
			h=x%y;
			if(0==h)
			{
				printf("the result is:%d",y);
				break;
			}
			else
			{
				x=y;
				y=h;
			}
		}
	}
	return 0;
} 
