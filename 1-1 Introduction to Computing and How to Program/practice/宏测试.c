#define DEBUG
#define DEBUG2

#include<stdio.h>

int main(void)
{
	#undef DEBUG
	#ifndef DEBUG
	printf("fuck");
	

#endif
#ifdef DEBUG
 printf("haha");
#elif DEBUG2
	printf("hehe");
#else
	printf("baga");
#endif


	return 0;
}
