#include<stdio.h>
int main(void)
{
	int x;
	for(x=1;x<=10;x++){
		if(x%2==0)continue;
		printf("x=%d\n",x);
}
	return 0;
}
