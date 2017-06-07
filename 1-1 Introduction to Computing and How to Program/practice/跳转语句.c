#include<stdio.h>
int main(void)
{
	int x=1;
	for(;;x++){
		printf("x=%d\n",x);
		if(x==10)goto haha;
}
	haha:;
	printf("you win\n");
	return 0;
}
