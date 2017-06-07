#include<stdio.h>
int twoPow(int x)
{
	int p=1,i;
	for(i=1;i<=x;i++)
	{
		p*=2;
	}
	return p;
}
void tenTotwo(int n)
{
	int count=0,h,store;
	int p=2;
	while(n>p)
	{
		count++;
		p*=2;
	}
	store=n;
	for(count;count>=0;count--)
	{
		h=store%(twoPow(count));
		if(h==store)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
		store%=(twoPow(count));
	}
}
int main(void)
{
	int number;
	scanf("%d",&number);
	tenTotwo(number);
	return 0;
}
