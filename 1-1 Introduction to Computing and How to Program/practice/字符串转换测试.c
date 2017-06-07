#include<stdio.h>
char* itos_Norm(int);
char num[4];

int main(void)
{
	printf("%s",itos_Norm(232));

	return 0;
}


char* itos_Norm(int client_Num)
{
	for(int i=2;i>=0;i--)
	{
		num[i]=client_Num%10+48;
		client_Num=(client_Num-(client_Num%10))/10;
	}
	num[3]='\0';
	return num;
}
