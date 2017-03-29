// MutiThread_Mutex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <process.h>
#include <windows.h>
#include <iostream>

using namespace std;
HANDLE hMutex;
static int data = 0;
unsigned int _stdcall threadFunc(PVOID pm)
{
	DWORD dwWaitResult = WaitForSingleObject(hMutex, INFINITE);
	switch (dwWaitResult)
	{
	case WAIT_OBJECT_0:
		data++;
		cout << "thread add data!" << endl;
		break;
	default:
		break;
	}
	Sleep(1000);
	if (!ReleaseMutex(hMutex))
		cout << "Release Mutex failed!";
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hHandle[5];
	
	// Create mutex 
	hMutex = ::CreateMutex(NULL,true,L"MyMutex");
	if (NULL == hMutex)
	{
		cout << "Create Mutex error!" << endl;
		return 0;
	}
	for (int i = 0; i < 5; i++)
	{
		hHandle[i] = (HANDLE)_beginthreadex(NULL, 0, threadFunc, NULL, 0, NULL);
	}
	data++;
	cout << "Main thread add data!" << endl;
	if (!ReleaseMutex(hMutex))
	{
		cout << "Main Thread Release Mutex failed!" << endl;
		exit(0);
	}
	//::WaitForSingleObject(hHandle, INFINITE);
	for (int i = 0; i < 5; i++)
	{
		::WaitForMultipleObjects(5, hHandle, true, INFINITE);
	}
	cout << "data: " << data << endl;
	system("pause");
	return 0;
}
/**
互斥量常用于多进程之间的线程互斥，所以它比关键段还多一个很有用的特性——“遗弃”
情况的处理。比如有一个占用互斥量的线程在调用ReleaseMutex()触发互斥量前就意
外终止了（相当于该互斥量被“遗弃”了），那么所有等待这个互斥量的线程是否会由于
该互斥量无法被触发而陷入一个无穷的等待过程中了？这显然不合理。因为占用某个互
斥量的线程既然终止了那足以证明它不再使用被该互斥量保护的资源，所以这些资源完
全并且应当被其它线程来使用。因此在这种“遗弃”情况下，系统自动把该互斥量内部的
线程ID设置为0，并将它的递归计数器复置为0，表示这个互斥量被触发了。然后系统将
“公平地”选定一个等待线程来完成调度（被选中的线程的WaitForSingleObject()会返
回WAIT_ABANDONED_0）。

再思考下互斥量能处理“遗弃”问题的原因，其实正是因为它有“线程所有权”概念。
在系统中一旦有线程结束后，系统会判断是否有互斥量被这个线程占有，如果有，
系统会将这互斥量对象内部的线程ID号将设置为NULL，递归计数设置为0，这表示
该互斥量已经不为任何线程占用，处于触发状态。其它等待这个互斥量的线程就能
顺利执行下去了。
*/

