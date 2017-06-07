#include<stdio.h>
int main(void)
{
	char p;
	int interval=0,longest=0,count0=0,count1=0;
	p=getchar();
	while(p!='#')
	{
		if(p=='1')
		{
			count1++;
			if(interval>0)
			{
				if(interval>longest)
				{
					longest=interval;
					interval=0;
				}
			}
		}
		if(p=='0')
		{
			count0++;
			if(count1>0)
			{
				interval++;
			}
		}
		p=getchar();
	}
	printf("cars:%d\n",count1);
	printf("times:%d\n",count0);
	printf("max:%d\n",longest);
	return 0;
}
