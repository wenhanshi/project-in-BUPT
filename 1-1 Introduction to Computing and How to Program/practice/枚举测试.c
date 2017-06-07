#include<stdio.h>

enum ins{
	G,V,ID,R,Q
};

int main(void)
{
	char ch;
	enum ins instruction=ID;
	
	printf("%d",instruction+1);
	return 0;
	
}
