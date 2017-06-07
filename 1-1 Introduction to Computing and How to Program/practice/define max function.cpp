#include<stdio.h>
int maxi(int,int,int);
int main(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",maxi(a,b,c));
	return 0;
}
int maxi(int p,int q,int f)
{
	int max=f;
	if(p>max)
		max=p;
	if(q>max)
		max=q;
	return max;
}
