// InsertSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
template<class T>
void InsertSort(vector<T>& vec)
{
	int i, j;
	//从第一个元素开始插入
	for (i = 0; i < vec.size(); i++)
	{
		//遍历[0,i)区间内所以元素，寻找vec[i]应该存放的位置
		for (j = 0; j < i; j++)
		{
			if (vec[i] < vec[j])
				break;
		}

		if (j < i)
		{
			//在区间[0,i)中找到vec[i]应该存放的位置为j
			//将区间[j,i)之间的元素依次后移一个位置，空出j位置给vec[i]
			T tmp = vec[i];
			for (int k = i - 1; k >= j; k--)
			{
				vec[k + 1] = vec[k];
			}
			vec[j] = tmp;
		}
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
	InsertSort<int>(vec);

	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

