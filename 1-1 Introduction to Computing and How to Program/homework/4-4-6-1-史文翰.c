#include<stdio.h>
int judgeTriangle(int a,int b,int c)
{
	if(a+b<=c||a+c<=b||b+c<=a)
	{
		return -1;
	}
	else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
	{
		return 1;
	}
	else if(a==b&&b==c)
	{
		return 3;
	}
	else if(a==b||a==c||b==c)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}
int main(void)
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	switch(judgeTriangle(x,y,z))
	{
		case -1:printf("not");break;
		case 0:printf("normal");break;
		case 1:printf("right-angled");break;
		case 2:printf("isosceles");break;
		case 3:printf("equilateral");break;
		default:break;
	}
	return 0;
}
