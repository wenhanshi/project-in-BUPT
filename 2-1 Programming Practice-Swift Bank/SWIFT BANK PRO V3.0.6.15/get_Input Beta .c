//get_Input V1.0
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"get_Input.h"

LPVOID WINAPI get_Input(LPVOID lpParameter)
{
	while((event=getchar())!=EOF)
	{	
		getchar();
		WaitForSingleObject(head_Mutex,INFINITE);
		event_Control(event);
		ReleaseMutex(head_Mutex);
	}
}

