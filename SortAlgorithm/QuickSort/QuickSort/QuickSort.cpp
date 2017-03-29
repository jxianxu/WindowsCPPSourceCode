// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//����������ָ��λ�õ�����Ԫ�ص�ֵ
void swap(vector<int>& vec,int left, int right)
{
	/*�ò�������ʱ�����ķ���������������ֵ*/

	vec[left] = vec[left] + vec[right];
	vec[right] = vec[left] - vec[right];
	vec[left] = vec[left] - vec[right];

	/*ʹ����ʱ�����ķ���������������ֵ*/
	//int tmp = vec[left];
	//vec[left] = vec[right];
	//vec[right] = tmp;
}
void QuickSort(vector<int>& vec, int left, int right)
{
	int key = left;
	int r = right;
	int l = left;
	while (left < right)   //��ѭ���������������㷨�Ľ�����������������
	{ 
		/*
		* ����βָ��right������ǰ�ƶ���ֱ������������
		* ע�⣺ ѭ����ֹ�����е� left < right �Ǳ�Ҫ�ģ����û�д����������ܻ����
		* rightһֱ�ݼ�����С��left�����
		*/
		while (vec[right] >= vec[key] && left < right)
			right--;
		//����βָ��ָ���Ԫ����ο�Ԫ�ص�ֵ�����Ҹ��²ο�Ԫ�ص�С��
		//ע�⣺�˴�Ӧ�ж�whileѭ���Ƿ�����Ϊvec[right] >= vec[key]�������������ֹ����Ϊֻ�����������
		//���ǲ���Ҫ����������Ԫ�ص�ֵ
		if (left < right)
		{
			swap(vec,key,right);
			key = right;
		}
		
		// ����ͷָ�룬����ǰ�ƣ�ֱ��������ǰ������Ϊֹ
		while (vec[left] <= vec[key] && left < right)
			left++;
		if (left < right)
		{
			swap(vec,key,left);
			key = left;
		}
		
	}
	//�ݹ���ã��Բο�Ԫ�ص����ߵ������зֱ��������
	//ע�⣺ Ϊ��ֹ�����±�Խ�磬Ӧ����һЩ��Ҫ���ж�
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

//�ǵݹ�ʵ�ֿ�������
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

