#include<stdio.h>
main()
{
	int a,b,k;
	float p;
	
	k=0;
	b=0;
	
	printf("Enter your score:");
	scanf("%d",&a);
	
	while(a!=-1){
		b=b+a;
		k=k+1;
		printf("Enter your score:%d");
		scanf("%d",&a);
		
	}
	if(b!=0){ 
		p=(float)b/k;
		printf("your final average is:%.2f",p);
	} 
	else
		printf("u r a sucker.");
		
	return 0;
}
