#include<stdio.h>
int main(void)
{
	char a;
	int i=1,eng=0,num=0,spa=0,other=0;
	printf("Please input a string:");
	a=getchar();
	while(a!='\n')
	{
		if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))
		{
			eng++;
		}
		else if(a>='0'&&a<='9')
		{
			num++;
		}
		else if(a==' ')
		{
			spa++;
		}
		else
		{
			other++;
		}
		a=getchar();
		i++;
	}
	if(i>100)
	{
		printf("You suck.");
	}
	else
	{
	printf("The number of English characters,spaces,numbers,other characters are:%d %d %d %d",eng,spa,num,other);
	}
	return 0;
}
	
