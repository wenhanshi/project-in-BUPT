#define SYSTEM 3
#if SYSTEM==1
	#define pass 1
#elif SYSTEM==2
	#define pass 2
#else
	#define pass 3
#endif
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char *p="1231242543423";
	printf("%lf\n0",atof(p));
	printf("%d",pass);
	return 0;
}
