#include<stdio.h>
void reverse(char v[])
{
	int i,j;
	char temp;
	for(i=0,j=strlen(v)-1;i<j;i++,j--)
	{
		temp=v[i];
		v[i]=v[j];
		v[j]=temp;
	}
}
int main(void)
{
	char str[100];
	int sum=0;
	int power=1;
	gets(str);
	reverse(str);
	for(int i=0;i<=strlen(str)-1;i++)
	{
		sum+=(str[i]-'A')*power;
		power=power*26;
	}
	printf("%d\n",sum);
	return 0;
}
