#include<stdio.h>
main()
{
	float ave;
	int score,cou,total;
	
	total=1;
	cou=-1;
	score=0;

	while(score!=-1){
		printf("Enter your score:\n");
		scanf("%d",&score);
		total=total+score;
		cou=cou+1;
	
	}
	ave=(float)total/cou; 
	printf("what u want is:%.2f",ave);
	
	return 0; 
		
}
