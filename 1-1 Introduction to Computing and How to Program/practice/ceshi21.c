#include<stdio.h>
void squeeze(char*s,char c)
{
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	{
		if(s[i]!=c)
		{
			s[j]=s[i];
			printf("%c",s[j]);
			j++;
		}
	}
	s[j]='\0';
}
int main(void)
{
	squeeze("abc",'c');
	return 0;
}
