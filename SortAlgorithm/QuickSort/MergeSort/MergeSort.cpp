// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
void merge(int *data, int start, int end, int * result)
{
	int middle = (start + end) / 2;
	int left_start = start;
	int right_start = middle + 1;
	int result_start = start;

	while (left_start <= middle && right_start <= end)
	{
		if (data[left_start] < data[right_start])
		{
			result[result_start++] = data[left_start++];
		}
		else
		{
			result[result_start++] = data[right_start++];
		}
	}
	while (left_start <= middle)
		result[result_start++] = data[left_start++];
	while (right_start <= end)
		result[result_start++] = data[right_start++];

}
void MergeSort(int * data, int start, int end, int * result)
{
	if (1 == end - start)
	{
		if (data[start] > data[end])
		{
			int tmp = data[start];
			data[start] = data[end];
			data[end] = tmp;
		}
		
		return;
	}
	else if (start == end)
	{
		return;
	}
	MergeSort(data, start, (start + end) / 2, result);
	MergeSort(data,(start+end)/2 +1,end,result);
	merge(data,start,end,result);
	for (int i = start; i <= end; i++)
	{
		data[i] = result[i];
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	int data[] = { 9, 6, 7, 22, 20, 33, 16, 20 };
	const int length = 8;
	int result[length];
	cout << "Before sorted:" << endl;
	for (int i = 0; i < length; ++i)
		cout << data[i] << "  ";
	cout << endl;
	cout << "After sorted:" << endl;
	MergeSort(data, 0, length - 1, result);
	for (int i = 0; i < length; ++i)
		cout << data[i] << "  ";
	cout << endl;
	system("pause");
	return 0;
}

