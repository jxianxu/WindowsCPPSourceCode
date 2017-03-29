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
�����������ڶ����֮����̻߳��⣬�������ȹؼ��λ���һ�������õ����ԡ�����������
����Ĵ���������һ��ռ�û��������߳��ڵ���ReleaseMutex()����������ǰ����
����ֹ�ˣ��൱�ڸû����������������ˣ�����ô���еȴ�������������߳��Ƿ������
�û������޷�������������һ������ĵȴ��������ˣ�����Ȼ��������Ϊռ��ĳ����
�������̼߳�Ȼ��ֹ��������֤��������ʹ�ñ��û�������������Դ��������Щ��Դ��
ȫ����Ӧ���������߳���ʹ�á���������֡�����������£�ϵͳ�Զ��Ѹû������ڲ���
�߳�ID����Ϊ0���������ĵݹ����������Ϊ0����ʾ����������������ˡ�Ȼ��ϵͳ��
����ƽ�ء�ѡ��һ���ȴ��߳�����ɵ��ȣ���ѡ�е��̵߳�WaitForSingleObject()�᷵
��WAIT_ABANDONED_0����

��˼���»������ܴ��������������ԭ����ʵ������Ϊ���С��߳�����Ȩ�����
��ϵͳ��һ�����߳̽�����ϵͳ���ж��Ƿ��л�����������߳�ռ�У�����У�
ϵͳ�Ὣ�⻥���������ڲ����߳�ID�Ž�����ΪNULL���ݹ��������Ϊ0�����ʾ
�û������Ѿ���Ϊ�κ��߳�ռ�ã����ڴ���״̬�������ȴ�������������߳̾���
˳��ִ����ȥ�ˡ�
*/

