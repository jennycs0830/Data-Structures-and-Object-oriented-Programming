#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<stdlib.h>
using namespace std;

const int Max = 10000;

void Merge(vector<int>&Arr, int start, int mid, int end)
{
	vector<int> Leftchild(Arr.begin() + start, Arr.begin() + mid + 1);
	//用.begin()回傳頭的位置再加上所需的start位置,最後尾巴多加一是為了提供多一格存Max以供比較時表示陣列以完全比較完
	vector<int>Rightchild(Arr.begin() + mid + 1, Arr.begin() + end + 1);

	Leftchild.insert(Leftchild.end(), Max);
	Rightchild.insert(Rightchild.end(), Max);

	int IndexLeft = 0, IndexRight = 0;
	for (int i = start; i <= end; i++)
	{
		if (Leftchild[IndexLeft] < Rightchild[IndexRight])
		{
			Arr[i] = Leftchild[IndexLeft];
			IndexLeft++;
		}
		else
		{
			Arr[i] = Rightchild[IndexRight];
			IndexRight++;
		}
	}
	return;
}

void MergeSort(vector<int>&Arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(Arr, start, mid);
		MergeSort(Arr, mid + 1, end);
		Merge(Arr, start, mid, end);
	}
	return;
}

void PrintArr(vector<int>&Arr)
{
	for (int i = 0; i < Arr.size(); i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int Array[50];
	int min = 2;
	int max = 500;
	/*只產生2到500內的亂數*/
	int x;
	srand(time(NULL));
	for (int i = 0; i < 50; i++)
	{
		int x = rand() % (max - min + 1) + min;
		Array[i] = x;
	}
	vector<int> Arr(Array, Array + (sizeof(Array) / sizeof(int)));
	cout << "original array:" << endl;
	PrintArr(Arr);
	MergeSort(Arr, 0, Arr.size() - 1);
	cout << "after sorted array:" << endl;
	PrintArr(Arr);
	return 0;
}