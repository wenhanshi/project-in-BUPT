#include<stdio.h>

#define ALPHA ((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
#define UNDERLINE (c=='_')
#define NUMBER (c>='0'&&c<='9')
#define COMMA (c==',')

int main(void)
{
	char c;
	int state=0;
	int over=1;
	
	while(((c=getchar())!=';')&&over==1)
	{
		switch(state)
		{
			case 0:
				if(c=='i')
				{
					state=1;
				}
				else
				{
					over=0;
				}
				break;
			case 1:
				if(c=='n')
				{
					state=2;
				}
				else
				{
					over=0;
				}
				break;
			case 2:
				if(c=='t')
				{
					state=3;
				}
				else
				{
					over=0;
				}
				break;
			case 3:
				if(c==' ')
				{
					state=4;
				}
				else
				{
					over=0;
				}
				break;
			case 4:
				if(UNDERLINE||ALPHA)
				{
					state=5;
				}
				else
				{
					over=0;
				}
				break;
			case 5:
				if(UNDERLINE||ALPHA||NUMBER)
				{
					;
				}
				else if(COMMA)
				{
					state=4;
				}
				else
				{
					over=0;
				}
				break;
		}
	}
	
	if(over==1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
