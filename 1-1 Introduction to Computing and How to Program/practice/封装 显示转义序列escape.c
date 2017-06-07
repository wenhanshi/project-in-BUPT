#include<stdio.h>
//t-->s,in the array t,there are '\t','\n'...
void escape(char*s,char*t)
{
	int i,j;
	for(i=j=0;t[i]!='\0';i++)
	{
		switch(t[i])
		{
			case '\n':
				s[j]='\\';
				s[j+1]='n';
				j+=2;
				break;
			case '\t':
				s[j]='\\';
				s[j+1]='t';
				j+=2;
				break;
			default:
				s[j]=t[i];
				j++;
				
				break;
		}
	}
	s[j]='\0';
}
int main(void)
{
	int i=0;
	char c;
	char s[100];
	char t[7]={"a\te\nfg"};
	escape(s,t);
	for(i=0;t[i]!='\0';i++)
	{
		printf("%c",t[i]);
	}
	printf("\n\n");
	for(i=0;s[i]!='\0';i++)
	{
		printf("%c",s[i]);
	}
	return 0;
}
