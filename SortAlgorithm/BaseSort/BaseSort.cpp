// BaseSort.cpp : Defines the entry point for the console application.
//
/*
* 基数排序
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
int GetIndex(int data, int len)
{
	//len: 1: 表示取data的个位数，2：表示取data的十位数，以此类推.....
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
	//先找到数列中最大的数
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > maxData)
			maxData = vec[i];
	}
	//求得最大的数的宽度
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
	int max = GetMaxLength(data); //得到排序数列中最大的数的位数
	while (max > 0)               //控制基数排序的趟数
	{
		flags ++;  //flags：1 表示取个位数，2： 表示取10位数，3： 取百位数........
		
		for (int i = 0; i < data.size(); i++)
		{
			int index = GetIndex(data[i], flags);
			vec[index].push_back(data[i]);
		}
		
		//将桶中的数依次放回排序数列中，在放回之前，先删除排序数列中原来的旧数据
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
		//将桶中给的数据放回排序序列后，清空桶中的数据
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

