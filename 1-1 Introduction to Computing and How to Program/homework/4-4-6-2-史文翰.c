#include<stdio.h>
#include<stdlib.h>
int year,month;
int isLeap(int year)
{
	if(year%400==0||(year%4==0&&year%100!=0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int GetMonthDays(int year,int month)
{
	if(isLeap(year)==1)
	{
		switch(month)
		{
			case 1:return 31;break;
			case 2:return 29;break;
			case 3:return 31;break;
			case 4:return 30;break;
			case 5:return 31;break;
			case 6:return 30;break;
			case 7:return 31;break;
			case 8:return 31;break;
			case 9:return 30;break;
			case 10:return 31;break;
			case 11:return 30;break;
			case 12:return 31;break;
		}
	}
	else
	{
		switch(month)
		{
			case 1:return 31;break;
			case 2:return 28;break;
			case 3:return 31;break;
			case 4:return 30;break;
			case 5:return 31;break;
			case 6:return 30;break;
			case 7:return 31;break;
			case 8:return 31;break;
			case 9:return 30;break;
			case 10:return 31;break;
			case 11:return 30;break;
			case 12:return 31;break;
		}
	}
}
int GetWeekDay(int year,int month,int day)
{
	day=1;
	long days;
	if(isLeap==1)
	{
		switch(month)
		{
			case 1:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+1;break;
			case 2:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+32;break;
			case 3:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+61;break;
			case 4:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+92;break;
			case 5:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+122;break;
			case 6:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+153;break;
			case 7:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+183;break;
			case 8:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+214;break;
			case 9:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+245;break;
			case 10:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+275;break;
			case 11:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+306;break;
			case 12:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+336;break;
		}
	}
	else
	{
		switch(month)
		{
			case 1:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+1;break;
			case 2:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+32;break;
			case 3:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+60;break;
			case 4:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+91;break;
			case 5:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+121;break;
			case 6:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+152;break;
			case 7:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+182;break;
			case 8:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+213;break;
			case 9:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+244;break;
			case 10:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+274;break;
			case 11:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+305;break;
			case 12:days=(year-1)*365+(year-1)/400+(year-1)/4-(year-1)/100+335;break;
		}
	}
	return days%7;
}
void print(int startday,int monthdays)
{
	int i;
	printf("%d-%d\nSun.\tMon.\tTue.\tWen.\tThu.\tFri.\tSat.\n",year,month);
	if(startday!=0)
	{
		for(i=1;i<=startday;i++)
		{
			printf("\t");
		}
	}
	for(i=1;i<=monthdays;i++)
	{
		printf("%d\t",i);
		if(i%7==(7-startday))
		{
			printf("\n");
		}
	}
}
int main(void)
{
	scanf("%d%d",&year,&month);
	print(GetWeekDay(year,month,1),GetMonthDays(year,month));
	system("pause");
	return 0;
}
