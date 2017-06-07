#include<stdio.h>
main()
{
	int k,counter,total,ave;
	
	total=0;
	counter=1;
	k=999;
	
	while(counter>=1){
		
		scanf("%d",&k);
		total=k+total;
		counter=counter+1;
		
	}
	printf("it is:%d\n",total);
	
}
