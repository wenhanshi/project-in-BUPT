#include<stdio.h>
#include<string.h>

void func(int,char*);

int main(void)
{
	char a[100],*pa=a;
	int m;
	gets(a);
	scanf("%d",&m);
	func(m,pa);
	puts(a);
	return 0;
}

void func(int m,char* pa)
{
	int count=0;
	int i=0;
	char* temp=pa;
	char* dest;
	char* tempp;
	
	while(count<m)
	{
		count++;
		temp++;
	}
	
	tempp=temp;
	while(*temp)
	{
		dest[i]=*temp;
		i++;
		temp++;
	}

	printf("\n%c\n",*pa);
	while(pa!=tempp)
	{
		dest[i]=*pa;
		i++;
		pa++;
	}
	dest[i]='\0';
	pa=dest;
}
