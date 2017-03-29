// BubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
template<class T>
void Display(vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}
template<class T>
void BubbleSort(vector<T> & vec)
{
	int flags = 0;
	int k = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		k = flags;
		bool bChange = false;
		for (int j = k; j < vec.size(); j++)
		{
			if (vec[i] > vec[j])
			{
				T tmp = vec[i];
				vec[i] = vec[j];
				vec[j] = tmp;
				if (!bChange)
				{
					flags = j;
					bChange = true;
				}
			}
		}
		if (!bChange)
			break;
		Display(vec);
		
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec;
	vec.push_back(9);
	vec.push_back(7);
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
	BubbleSort<int>(vec);


	cout << "///////////////////////////" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

