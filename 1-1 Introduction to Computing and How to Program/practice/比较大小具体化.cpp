#include<stdio.h>
main()

{
	int a,b;
	scanf("%d%d",&a,&b);
	
	if(a>b)
	printf("%d is larger.",a);
	
	if(a<b)
	printf("%d is larger.",b);
	
	if(a==b)
	printf("these numbers are equal.");
	
	return 0; 
}
