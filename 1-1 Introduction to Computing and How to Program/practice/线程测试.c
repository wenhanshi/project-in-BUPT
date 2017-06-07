#include<stdio.h>
#include<windows.h>
#include<time.h>
int index=20;
HANDLE hMutex;
DWORD WINAPI func(LPVOID lpParameter)
{
	while(index>0)
	{
		WaitForSingleObject(hMutex,INFINITE);
		printf("%d fuck ,i'm another thread!!\n",index--);
		ReleaseMutex(hMutex);
	}
	return 0;
}
DWORD WINAPI func2(LPVOID lpParameter)
{
	while(index>0)
	{
		WaitForSingleObject(hMutex,INFINITE);
		printf("%d fuck,i'm 2!\n",index--);
		ReleaseMutex(hMutex);
	}
}
int main(void)
{
	hMutex=CreateMutex(NULL,FALSE,NULL);
	
	HANDLE hThread1,hThread2;
	hThread1=CreateThread(NULL,0,func,NULL,0,NULL);
	hThread2=CreateThread(NULL,0,func2,NULL,0,NULL);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	Sleep(4000);
	return 0;
}
