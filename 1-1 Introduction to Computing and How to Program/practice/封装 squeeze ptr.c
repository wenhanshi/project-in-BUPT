#include<stdio.h>
#include<limits.h>
void squeeze(char*v,char c)
{
	char*vp=v;
	for(v;*v!='\0';v++)
	{
		if(*v!=c)
		{
			*(vp++)=*v;
		}
	}
	*vp='\0';
}
int main(void)
{
	int x=4;
	int p=0;
	char s[]="hello";
	char*sp="what the fuck";
	sp+=4;
	p=-++x;
	char ch='o';
	squeeze(s,ch);
	puts(s);
	puts(sp);
	printf("%d",p);
	return 0;
}
