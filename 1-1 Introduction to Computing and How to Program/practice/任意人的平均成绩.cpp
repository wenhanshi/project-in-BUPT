#include<stdio.h>
main()
{
	float ave;
	int score,cou,total;
	
	total=0;
	cou=0;

	while(score!=-1){
		printf("Enter your score:\n");
		scanf("%d",&score);
		total=total+score;
		cou=cou+1;
	
	}
	ave=total/cou; 
	printf("what u want is:%.2f",ave);
	
	return 0; 
		
}
