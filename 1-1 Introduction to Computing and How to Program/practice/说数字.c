#include<stdio.h>
int main(void)
{
	char p,minus;
	p=getchar();
	while(p!='\n')
	{
		if(p=='0')
		{
			printf("LING");
		}
		switch(p)
		{
		case'-':
			printf("FU ");
			break;
		case'1':
			printf("YI ");
			break;
		case'2':
			printf("ER ");
			break;
		case'3':
			printf("SAN ");
			break;
		case'4':
			printf("SI ");
			break;
		case'5':
			printf("WU ");
			break;
		case'6':
			printf("LIU ");
			break;
		case'7':
			printf("QI ");
			break;
		case'8':
			printf("BA ");
			break;
		case'9':
			printf("JIU ");
			break;
		default:
			break;
		}
		minus=p;
		p=getchar();
		if(p!='\n'&&minus!='-')
		{
			printf("SHI ");
		}
	}
	return 0;
}
