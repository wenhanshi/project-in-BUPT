#include<stdio.h>
int main(void)
{
	int n,k;
	long long sum=0;
	
	printf("Please input an integer:");
	scanf("%d",&n);
	if(n==0||n==1)
		printf("The result is:0");
	else
		for(k=3;k<=n;k++){
			sum+=k*(k-1)*(k-2);
		}
	printf("The result is:%lld",sum);
	return 0;
}
