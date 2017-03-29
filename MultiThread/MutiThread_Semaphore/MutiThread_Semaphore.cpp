// MutiThread_Semaphore.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <process.h>


using namespace std;

int data = 0;
HANDLE hEvent;
CRITICAL_SECTION section;
HANDLE hSemaphore;
unsigned int _stdcall threadFunc(PVOID pM)
{
	DWORD dwWaitResult = WaitForSingleObject(hSemaphore, INFINITE);
	switch (dwWaitResult)
	{
	case WAIT_OBJECT_0:
		ReleaseSemaphore(hSemaphore, 1, NULL);
		cout << "I get semahore and I will add data in criticalsection" << endl;
		cout << endl;
		EnterCriticalSection(&section);
		data++;
		LeaveCriticalSection(&section);
		break;
	default:
		break;
	}
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hThread[10];
	
	// intialize Critical section
	InitializeCriticalSection(&section);
	// Create a semaphore 
	hSemaphore =  CreateSemaphore(NULL,0,1,L"MySemaphore");
	if (NULL == hSemaphore)
	{
		cout << "Create Semaphore failed!" << endl;
		exit(0);
	}

	// create thread
	for (int i = 0; i < 10; i++)
	{
		hThread[i] = (HANDLE)_beginthreadex(NULL,0,threadFunc,NULL,0,NULL);
	}
	cout << "Main Thread add data!" << endl;
	data++;
	ReleaseSemaphore(hSemaphore,1,NULL);
	for (int i = 0; i < 10; i++)
	{
		WaitForSingleObject(hThread[i],INFINITE);
	}
	cout << " data : " << data << endl;
	CloseHandle(hSemaphore);
	system("pause");
	return 0;
}

