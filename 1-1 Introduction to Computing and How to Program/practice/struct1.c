#include<stdio.h>
int main(void)
{
	struct date
	{
		int year;
		int month;
		int day;
	} birthday;
	struct student
	{
		int num;
		char name[20];
		float score;
		struct date birthday;
	};
	 struct student student1=
	{
		2,
		"shiwenhan",
		100,
		{
			1995,12,5
		}
	};
	printf("%d\n%s\n%f\n%d",student1.num,student1.name,student1.score,sizeof(struct student));
	printf("%p",&student1);
	return 0;
}
