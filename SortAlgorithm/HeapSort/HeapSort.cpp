// HeapSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void HeapInsert(vector<int>& heap, int elements)
{
	int insert_position = heap.size();
	heap.push_back(elements);

	for (int parent_index = (insert_position - 1) / 2; parent_index >= 0; parent_index = (parent_index - 1) / 2)
	{
		if (elements < heap[parent_index])
		{
			int tmp = heap[insert_position];
			heap[insert_position] = heap[parent_index];
			heap[parent_index] = tmp;
			insert_position = parent_index;
		}
	}
}
void AdjustHeapFromTop(vector<int>& heap, int index)
{
	if (index >= heap.size() || 2 * index + 1 >= heap.size())
		return;
	if (2 * index + 2 < heap.size())
	{
		if (heap[2 * index + 1] > heap[2 * index + 2])
		{
			if (heap[index] > heap[2 * index + 2])
			{
				int tmp = heap[index];
				heap[index] = heap[2 * index + 2];
				heap[2 * index + 2] = tmp;
				AdjustHeapFromTop(heap, 2 * index + 2);
			}
		}
		else
		{
			if (heap[index] > heap[2 * index + 1])
			{
				int tmp = heap[index];
				heap[index] = heap[2 * index + 1];
				heap[2 * index + 1] = tmp;
				AdjustHeapFromTop(heap, 2 * index + 1);
			}
		}
	}
	else
	{
		if (heap[index] > heap[2 * index + 1])
		{
			int tmp = heap[index];
			heap[index] = heap[2 * index + 1];
			heap[2 * index + 1] = tmp;
			AdjustHeapFromTop(heap, 2 * index + 1);
		}
	}

}
int HeapDelete(vector<int>& heap)
{
	int ret = heap[0];
	if (heap.size() > 0)
	{
		
		heap[0] = heap[heap.size() - 1];
		heap.erase(heap.end()-1);
		AdjustHeapFromTop(heap,0);
	}
	return ret;
}

void ChangeArrayToHeap(vector<int>& vec)
{
	int len = vec.size();
	int loc = len / 2 - 1;
	
	for (int i = loc; loc >= 0; loc--)
	{
		AdjustHeapFromTop(vec,loc);
	}
}

void HeapSort(vector<int>& vec,vector<int>& result)
{
	while (!vec.empty())
	{
		ChangeArrayToHeap(vec);
		int ret = HeapDelete(vec);
		result.push_back(ret);
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
	
	int data[] = { 9, 12, 17, 30, 50, 20, 60, 65, 4, 19 };
	vector<int> vec(begin(data), end(data));
	ChangeArrayToHeap(vec);
	vector<int> result;
	HeapSort(vec,result);
	display(result);
	system("pause");

	return 0;
}

