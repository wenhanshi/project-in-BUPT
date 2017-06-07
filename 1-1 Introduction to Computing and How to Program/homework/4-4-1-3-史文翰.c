#include<stdio.h>
int main(void)
{
	char a,b,c;
	int k;
	printf("Please input three char:");
	scanf("%c%c%c",&a,&b,&c);
	if((a-b==-1&&b-c==-1)&&(a>='a'&&a<='z'&&b>='a'&&b<='z'&&c>='a'&&c<='z')||(a>='A'&&a<='Z'&&b>='A'&&b<='Z'&&c>='A'&&c<='Z'))
	{
		printf("The letters are adjacent with each other.");
	} 
	else
		printf("The letters are not abjacent with each other.");
	return 0; 
	
}
