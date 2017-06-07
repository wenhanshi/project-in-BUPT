#include<stdio.h>
int main(void)
{
	char c;
	int flag=1,count=0;
	while((c=getchar())!=EOF)
	{
		if(c!=' '&&flag)
		{
			count++;
			flag=0;
		}
		else if(!flag&&c==' ')
		{
			flag=1;
		}
	}
	printf("%d",count);
	return 0;
}
