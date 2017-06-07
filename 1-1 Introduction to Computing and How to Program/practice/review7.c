#include<stdio.h>
int main(void)
{
	char c;
	int nword,nspace,nother,nnum;
	nword=nspace=nother=nnum=0;
	while((c=getchar())!='\n')
	{
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')
		{
			nword++;
		}
		else if(c>='0'&&c<='9')
		{
			nnum++;
		}
		else if(c==' ')
		{
			nspace++;
		}
		else
		{
			nother++;
		}
	}
	return 0;
}
