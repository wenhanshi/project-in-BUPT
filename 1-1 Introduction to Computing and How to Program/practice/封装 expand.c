#include<stdio.h>
//expand a-z in s1 to abcd...xyz in s2.
void expand(char*s1,char*s2)
{
	int i,j;
	char c;
	i=j=0;
	while((c=s1[i])!='\0')
	{
		i++;
		if(s1[i]=='-'&&s1[i+1]>=c)
		{
			i++;
			while(c<s1[i])//the important detail '<' ,resisting print the same char for twice
			{
				s2[j]=c;
				j++;
				c++;
			}
		}
		else
		{
			s2[j]=c;//if not,copy the chars
			j++;
		}
	}
	s2[j]='\0';
}
int main(void)
{
	int i;
	char s1[100]="d-oj-l-p";
	char s2[100];
	expand(s1,s2);
	for(i=0;s2[i]!='\0';i++)
	{
		printf("%c",s2[i]);
	}
	return 0;
}
