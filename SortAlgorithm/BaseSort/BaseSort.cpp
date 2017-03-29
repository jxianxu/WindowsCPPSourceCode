// BaseSort.cpp : Defines the entry point for the console application.
//
/*
* ��������
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
int GetIndex(int data, int len)
{
	//len: 1: ��ʾȡdata�ĸ�λ����2����ʾȡdata��ʮλ�����Դ�����.....
	while (len > 1)
	{
		data = data / 10;
		len--;
	}
	return data % 10;
}
int GetMaxLength(vector<int>& vec)
{
	int max = 0;
	int maxData = 0;
	//���ҵ�������������
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > maxData)
			maxData = vec[i];
	}
	//����������Ŀ��
	while (maxData > 0)
	{
		maxData /= 10;
		max++;
	}
	return max;
}
void DisplayBiVec(vector< vector<int> >& biVec)
{
	for (int i = 0; i < biVec.size(); i++)
	{
		cout << i << ": ";
		if (biVec[i].size() > 0)
		{
			for (int j = 0; j < biVec[i].size(); j++)
			{
				cout << biVec[i][j] << " ";
			}
		}
		cout << endl;

	}
}

void BaseSort(vector<int>& data,vector< vector<int> >& vec)
{
	int flags = 0;
	int max = GetMaxLength(data); //�õ�������������������λ��
	while (max > 0)               //���ƻ������������
	{
		flags ++;  //flags��1 ��ʾȡ��λ����2�� ��ʾȡ10λ����3�� ȡ��λ��........
		
		for (int i = 0; i < data.size(); i++)
		{
			int index = GetIndex(data[i], flags);
			vec[index].push_back(data[i]);
		}
		
		//��Ͱ�е������ηŻ����������У��ڷŻ�֮ǰ����ɾ������������ԭ���ľ�����
		data.clear();
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i].size() > 0)
			{
				for (int j = 0; j < vec[i].size(); j++)
				{
					data.push_back(vec[i][j]);
				}
			}
		}
		//��Ͱ�и������ݷŻ��������к����Ͱ�е�����
		for (int i = 0; i < vec.size(); i++)
		{
			vec[i].clear();
		}
		max--;
		
	}
}

void display(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[] = { 73, 22, 93, 43, 55, 14, 28, 65, 39, 81 };
	vector<int> dataVec(begin(data),end(data));
	vector< vector<int> > baseVec;
	for (int i = 0; i < 10; i++)
	{
		vector<int> vec;
		baseVec.push_back(vec);
	}
	BaseSort(dataVec,baseVec);
	display(dataVec);
	system("pause");
	return 0;
}

