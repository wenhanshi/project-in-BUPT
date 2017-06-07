#include<stdio.h>
int main(void)
{
	int a,b,sq,cu;
	printf("Please input two integers:");
	scanf("%d%d",&a,&b);
	
	if((1<=a&&a<=b&&b<=100)&&((b-a)<15)){
	    printf("number\tsquare\tcube\n");
		for(;a<=b;a++){
			sq=a*a;
			cu=a*a*a;
			printf("%d\t%d\t%d\t\n",a,sq,cu);
		}
	}
	else
		printf("The data is fault.");
	return 0;
	
}
