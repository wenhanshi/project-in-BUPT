#include<stdio.h>
main()
{
	float ave;
	int sum,cou,score;
	
	sum=0;
	cou=0;
	
	printf("your grade is:\n");
	scanf("%d",&score);
	
	while(score!=-1){
		sum=sum+score;
		cou=cou+1;
		printf("your grade is:\n");
		scanf("%d",&score);
	}
	ave=(float)sum/cou;
	printf("your average is:%.2f\n",ave);
	return 0;
}
