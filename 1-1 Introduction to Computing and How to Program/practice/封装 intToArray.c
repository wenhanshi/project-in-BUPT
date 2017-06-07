#include<stdio.h>
#include<string.h>
void intToArray(int n,char*v)//turn a int to a char-array
{
	int sign,i=0;
	if((n=sign)<0)
	{
		n=-n;
	}
	do//generate the number in contrary order
	{
		v[i++]=n%10+'0';//to be a char
	}
	while((n/=10)>0);
	if(sign<0)
	{
		v[i++]='-';
	}
	v[i]='\0';
	reverse(v);//change the order to normal
}
void reverse(char*v)
{
	int i,j,temp;
	for(i=0,j=strlen(v)-1;i<j;i++,j--)//the strlen do not deal wtih '/0'
	{
		temp=v[j];
		v[j]=v[i];
		v[i]=temp;
	}
}
int main(void)
{
	int x=7785;
	char str[100];
	intToArray(x,str);
	for(int i=0;str[i]!='/0';i++)
	{
		printf("%c",str[i]);
	}
	return 0;
}
