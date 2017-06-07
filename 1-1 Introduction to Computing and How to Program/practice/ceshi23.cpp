#include<stdio.h>
void add(int p)
{
	p++;
	printf("%d",p);
}
int main(void)
{
	int p=1;
	add(p);
	printf("%d",p);
	return 0;
}
