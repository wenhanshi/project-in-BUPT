#include<stdio.h>
int main(void)
{
	int*aPtr=NULL;
	int a=1;
	
	aPtr=&a;
	printf("%p   %p\n",aPtr,&a);
	printf("%d   %d\n",*aPtr,a);
	return 0;
}
