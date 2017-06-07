#include<stdio.h>//remove the char'c' from the string and print it
char str[100];
void removeC(char*str,char c)
{
	int i,j;
	for(i=j=0;str[i]!='\0';i++)
	{
		if(str[i]!=c)
		{
			str[j]=str[i];
			printf("%c",str[j]);
			j++;
		}
	}
	str[j]='\0';
}
int main(void)
{
	removeC("hahahahahaaasdaaaha",'a');
	return 0;
}

