#include<stdio.h>
#include<math.h>
void itoa(int n,char s[])
{
	static int i;
	if(n/10)
	{
		itoa(n/10,s);
	}
	else
	{
		i=0;
		if(n<0)
		{
			s[i++]='-';
		}
	}
	s[i++]=abs(n)%10+'0';
	s[i]='\0';
}
int main(void)
{
	int n;
	char str[100];
	scanf("%d",&n);
	itoa(n,str);
	puts(str);
	return 0;
}
