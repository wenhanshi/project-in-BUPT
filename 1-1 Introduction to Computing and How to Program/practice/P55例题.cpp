#include<stdio.h>
main()
{
	int result,cou1,cou2,cou;
	
	cou1=0;
	cou2=0;
	cou=1;

	while(cou<=10){
		printf("Enter result:");
	    scanf("%d",&result);
		if(result==1)
			cou1++;
		else
			cou2++;
		cou++;
	}
	
	printf("Passed:%d\nFailed:%d\n",cou1,cou2);
	if(cou1>=8)
		printf("Raise tuition.");
	else
		printf("you are safe.");
	
	
}
