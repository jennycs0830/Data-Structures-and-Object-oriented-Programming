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
	//��.begin()�^���Y����m�A�[�W�һݪ�start��m,�̫���ڦh�[�@�O���F���Ѧh�@��sMax�H�Ѥ���ɪ�ܰ}�C�H���������
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
	/*�u����2��500�����ü�*/
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