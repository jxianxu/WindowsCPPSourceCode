// MutiThread_Event.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <process.h>

using namespace std;
int data = 0;
HANDLE hEvent;
unsigned int _stdcall threadFunc(PVOID pM)
{
	DWORD dwWaitResult = WaitForSingleObject(hEvent,INFINITE);
	switch (dwWaitResult)
	{
	case WAIT_OBJECT_0:
		cout << "the event is signaled! I will add the data!" << endl;
		data++;
		ResetEvent(hEvent); //set event to unsignaled status
		break;
	default:
		break;
	}
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hThread;
	//Create Event
	hEvent = ::CreateEvent(NULL,TRUE/*default security attr*/,FALSE/*if manual reset*/,L"MyEvent");
	
	if (NULL == hEvent)
	{
		cout << "Create Event failed!" << endl;
		exit(0);
	}
	hThread = (HANDLE)_beginthreadex(NULL,0,threadFunc,NULL,0,NULL);
	data++;
	cout << "Main thread add data!" << endl;
	Sleep(1000);

	//set event to signal status to notify child thread
	SetEvent(hEvent);
	WaitForSingleObject(hThread,INFINITE);
	cout << "data: " << data << endl;
	system("pause");
	return 0;
}

