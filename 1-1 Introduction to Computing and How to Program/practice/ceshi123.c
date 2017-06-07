#include<stdio.h>
#define dprint(expr) printf(#expr"=%g\n",expr)
int main(void)
{
	int x=5,y=5;
	dprint(x/y);
	return 0;
}
