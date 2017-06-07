#include<stdio.h>
int main(void)
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(i==(2*n-1)/2)
			printf("*");
		else
			printf(" ");
	}
}
