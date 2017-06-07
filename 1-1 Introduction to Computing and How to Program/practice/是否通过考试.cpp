#include<stdio.h>
main()
{
	int k;
	
	printf("Enter your grade:\n");
	scanf("%d",&k);
	printf("%s\n",k>=60?"Pass":"wtf");
	return 0;
}
