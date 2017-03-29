// C++11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <memory>
#include <windows.h>
#include <stdio.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int a[5] = { 1, 2, 3, 4, 6 };
	vector<int> vec(begin(a),end(a));
	for (int i = 0; i < vec.size(); i++)
	{
		//int& data = a[i];
		//data++;
		auto data = vec[i];
		data++;
	}
	for (auto i : vec)
	{
		cout << i << endl;
	}
	
	system("pause");
	return 0;
}

