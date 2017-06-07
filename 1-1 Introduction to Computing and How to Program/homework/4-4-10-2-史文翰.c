#include<stdio.h>
#define MAXPTR 1000
#define MAXLEN 10000
int main(void)
{
	char*wordPtr[MAXPTR];
	char wordArray[MAXLEN];
	int j=0,flag=0;
	gets(wordArray);
	for(int i=0;wordArray[i]!='\0';i++)
	{
		if(wordArray[i]!=' '&&flag==0)
		{
			wordPtr[j++]=&wordArray[i];
			flag=1;
		}
		if(wordArray[i]==' ')
		{
			wordArray[i]='\0';
			flag=0;
		}
	}
	wordPtr[j]=NULL;
	for(int i=0;wordPtr[i]!=NULL;i++)
	{
		printf("%s\n",wordPtr[i]);
	}
	return 0;
}
