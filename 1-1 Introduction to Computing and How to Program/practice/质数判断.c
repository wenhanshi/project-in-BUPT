#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int num,i=2,isprim=1;
	for(num=1;;num++)
	{
		while(i*i<=num&&isprim)
		{
			if(num%i==0)
			{
				isprim=0;
			}
			else
			{
				i++;
			}
		}
		if(isprim!=0)
		{
			printf("%d\n",num);
			system("pause");
		}
		i=2;
		isprim=1;
	}
	return 0;
}
