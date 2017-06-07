#include<stdio.h>

struct point{
	int x;
	int y;
};
struct rect{
	struct point pt1;
	struct point pt2;
};
struct rect screen;
struct point middle;
struct point makepoint(int,int);

int main(void)
{
	struct point p,*pp;
	pp=&p;
	p=makepoint(1,2);
	printf("%d %d",pp->x,pp->y);
	return 0;
	
}
struct point makepoint(int x,int y)
{
	struct point temp;
	temp.x=x;
	temp.y=y;
	return temp;
}
