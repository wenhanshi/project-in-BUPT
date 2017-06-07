#include<stdio.h>
int main(void)
{               
	char grade;
	int excellent=0,normal=0,bad=0;
	printf("Enter your grade,if wanna quit,enter EOF\n");
	scanf("%c",&grade);
	while(grade!="EOF"){
		switch(grade){
			case'A':case'a':
				excellent++;
				break;
			case'B':case'b':
				normal++;
				break;
			case'C':case'c':
				bad++;
				break;
			case'\n':case' ':
				break;
			default:
				printf("you suck\n");
				break;
		}
	}
	printf("%d\n%d\n%d\n",excellent,normal,bad);
	return 0;
	
}
				                     
