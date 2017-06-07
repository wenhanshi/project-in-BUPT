#include<stdio.h>
int main(void)
{
	char str[20]="STOPPOLLUTION";
	int i=0;
	while(str[i]!='\0')
	{
		str[i]=(17*(str[i]-'A')+22)%26+'A';
		i++;
	}
	puts(str);
	return 0;
}
