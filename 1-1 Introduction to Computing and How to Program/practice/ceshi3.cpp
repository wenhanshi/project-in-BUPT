#include<stdio.h>
int main(void)
{
	char a[10];
	for(int i=0;i<=9;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='\n')
		{
			break;
		}
	}
	for(int i=0;i<=9;i++)
	{
		printf("%c",a[i]);
	}
	return 0;
}
