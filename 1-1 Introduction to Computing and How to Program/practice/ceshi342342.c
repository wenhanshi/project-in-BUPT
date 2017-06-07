#include<stdio.h>
char*get(void)
{
	char p[]="hello";
	return p;
}
int main(void)
{
	char*str=NULL;
	str=get();
	printf(str);
	return 0;
}
//临时内存，被收回？ 
//mark:row4  char*p="hello";
