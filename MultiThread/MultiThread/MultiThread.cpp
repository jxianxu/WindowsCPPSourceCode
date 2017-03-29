// MultiThread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <process.h>
using namespace std;
unsigned int _stdcall threadFunc(PVOID pm);
CRITICAL_SECTION section;
static int data = 0;
int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hHandle[5];
	unsigned threadid;
	// initialize critical section
	InitializeCriticalSection(&section);

	for (int i = 0; i < 5; i++)
	{
		hHandle[i] = (HANDLE )_beginthreadex(NULL, 0, threadFunc, NULL, 0, NULL);
	}
	//::WaitForSingleObject(hHandle, INFINITE);
	for (int i = 0; i < 5; i++)
	{
		::WaitForMultipleObjects(5,hHandle,true,INFINITE);
	}
	cout << "data: " << data << endl;
	//delete critical section
	DeleteCriticalSection(&section);
	system("pause");
	return 0;
}
unsigned int _stdcall threadFunc(PVOID pm)
{
	cout << "Thread start!" << endl;
	EnterCriticalSection(&section);
	data++;
	cout << "data ++ " << endl;
	LeaveCriticalSection(&section);
	Sleep(3000);
	cout << "Thread end!" << endl;
	return 0;
}

