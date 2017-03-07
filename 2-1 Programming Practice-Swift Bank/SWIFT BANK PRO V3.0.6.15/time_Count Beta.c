#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"alltype and alldefine.h"
#include"time_Count.h"

void time_Count(void)
{
	Time=(int)(clock()-start)/CLOCKS_PER_SEC;
	
	if(cur_VIP_Num>=VIPNUM_TO_STARTTIME)
	{
		VIP_Time++;
	}
	else
	{
		VIP_Time=0;
	}
	Sleep(1000);
}

