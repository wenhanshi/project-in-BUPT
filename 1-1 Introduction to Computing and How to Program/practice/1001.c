#include<stdio.h>
int main(void)
{
	long double R;
	int k,n;
	scanf("%llf%d",&R,&n);
	for(k=2;k<=n;k++){
		R=R*R;
	}
	printf("%llf",R);
	return 0;
}
