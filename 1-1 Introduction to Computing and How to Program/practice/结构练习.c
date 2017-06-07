#include<stdio.h>
#include<limits.h>
#define NVAL 10
struct val{
	int x;
	int y;
	char ch;
	int *pt;
};
int main(void)
{
	typedef struct val Dummy;
	Dummy a[NVAL]={ 1,2,'c',NULL};
	Dummy *pt=a;
	int v[5]={1,2,3,4,6};
	printf("%d",a[0].x);
	printf("%d",pt->y);
	printf("\n%d %d",EOF,INT_MAX);
	return 0;
}
