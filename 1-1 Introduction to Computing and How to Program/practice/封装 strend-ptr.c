#include<stdio.h>
int strend(char*s,char*t)
{
	char*ends=s;//define another two pointers
	char*endt=t;
	for(;*ends;ends++)//let them move to the end of the array
	;
	for(;*endt;endt++)//..
	;
	for(;*ends==*endt;ends--,endt--)//scan from the end
	{
		if(ends==s||endt==t)//has been to the beginning
		{
			break;
		}
	}
	if(t==endt&&*ends==*endt&&*ends!='\0')//three conditions:1.position t=endt;2.the last value is the same
	{									  //3.now the ends is not point to '/0'	
		return 1;
	}
	return 0;
}
int main(void)
{
	char s[100],t[100];
	gets(s);
	gets(t);
	printf("%d",strend(s,t));
	return 0;
}
