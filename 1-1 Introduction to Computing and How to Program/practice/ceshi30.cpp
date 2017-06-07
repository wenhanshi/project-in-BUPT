#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(void)
{
	srand(time(NULL));
	printf("%d",rand()%3+1);
	return 0;
}
