#include<stdio.h>
int main(int argc,char *argv[])
{
	int x=3;
	int y;
	y=(++x)+(x++)+(x++);
	printf("%d",y);
	return 0;
}
