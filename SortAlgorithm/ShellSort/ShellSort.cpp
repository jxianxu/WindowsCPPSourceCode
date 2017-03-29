// ShellSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

//��ÿһ��Ԫ�ؽ���ֱ�Ӳ�������
void InsertSort(vector<int>& vec,int start, int end,int gap)
{
	int i = 0;
	int element = vec[end];
	for (i = start; i < end; i += gap)
	{
		if (vec[i] > element)
		{
			break;
		}	
	}
	if (i < end)
	{
		int j = end - gap;
		for (; j >= i; j -= gap)
		{
			vec[end] = vec[j];
		}
		vec[i] = element;
	}
}
void ShellSort(vector<int>& vec)
{
	int gap = vec.size() / 2;
	while (gap >= 1) // �����������������gap����1ʱ��Ϊ���һ������
	{
		//��ʼһ������
		for (int i = 0; i+gap < vec.size(); i++)
		{
			for (int j = i; j < vec.size(); j+= gap)
			{
				InsertSort(vec,i,j,gap);
			}
		}
		//һ����������󣬲�Ҫ���Ǹ��²���gap��ֵ
		gap /= 2;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec;
	vec.push_back(9);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(5);
	ShellSort(vec);

	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

