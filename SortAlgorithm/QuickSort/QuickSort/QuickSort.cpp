// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//交换序列中指定位置的两个元素的值
void swap(vector<int>& vec,int left, int right)
{
	/*用不开辟临时变量的方法交换两个数的值*/

	vec[left] = vec[left] + vec[right];
	vec[right] = vec[left] - vec[right];
	vec[left] = vec[left] - vec[right];

	/*使用临时变量的方法交换两个数的值*/
	//int tmp = vec[left];
	//vec[left] = vec[right];
	//vec[right] = tmp;
}
void QuickSort(vector<int>& vec, int left, int right)
{
	int key = left;
	int r = right;
	int l = left;
	while (left < right)   //此循环控制整个排序算法的结束（包含多趟排序）
	{ 
		/*
		* 序列尾指针right不断向前移动，直到不满足条件
		* 注意： 循环终止条件中的 left < right 是必要的，如果没有此条件，可能会出现
		* right一直递减最终小于left的情况
		*/
		while (vec[right] >= vec[key] && left < right)
			right--;
		//交换尾指针指向的元素与参考元素的值，并且更新参考元素的小标
		//注意：此处应判断while循环是否是因为vec[right] >= vec[key]条件不满足而终止，因为只有这种情况下
		//我们才需要交换这两个元素的值
		if (left < right)
		{
			swap(vec,key,right);
			key = right;
		}
		
		// 序列头指针，不断前移，直到不满足前移条件为止
		while (vec[left] <= vec[key] && left < right)
			left++;
		if (left < right)
		{
			swap(vec,key,left);
			key = left;
		}
		
	}
	//递归调用，对参考元素的两边的子序列分别进行排序
	//注意： 为防止数组下标越界，应该做一些必要的判断
	if (key -1 > l)
		QuickSort(vec,l,key-1);
	if (key + 1 < r)
		QuickSort(vec,key+1,r);
}

int OneSort(vector<int>& vec, int left, int right)
{
	int key = left;
	while (left < right)
	{ 
		while (vec[right] >= vec[key] && left < right)
		right--;
		if (left < right)
		{
			swap(vec, key, right);
			key = right;
		}

		while (vec[left] <= vec[key] && left < right)
			left++;
		if (left < right)
		{
			swap(vec, key, left);
			key = left;
		}
	}
	return key;
}

//非递归实现快速排序
void QuickSortWithoutRecurise(vector<int>& vec)
{
	int key = 0;
	int left = 0;
	int right =(int) vec.size() - 1;
	while (left < right)
	{
		key = OneSort(vec,left,right);
		while (key - 1 > left)
		{
			right = key-1;
			key = OneSort(vec, left, right); 
		}

		while (key + 1 < right)
		{
			left = key + 1;
			key = OneSort(vec, left, right);
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(9);
	vec.push_back(3);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(1);
	vec.push_back(5);
	int right = vec.size()-1;
	
	QuickSort(vec,0,right);
	for (size_t i = 0; i != vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

