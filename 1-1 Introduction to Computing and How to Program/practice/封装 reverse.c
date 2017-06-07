#include<stdio.h>
#include<string.h>
//in function reverse u can revert the string in the contrary order.
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
	int i;
	char s[]="hello world!";//if u dont know exactly how long the char array is,dont input the number
	reverse(s);
	for(i=0;s[i]!='\0';i++)
	{
		printf("%c",s[i]);
	}
	return 0;
}
