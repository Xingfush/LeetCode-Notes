#include "stdafx.h"
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int Partition(int*arr, int start, int end)
{
	int left = start, right = end;
	int pivot = arr[end];
	while (left < right)// 全是left<right
	{
		while (left < right && arr[left] < pivot)
			left++;
		while (left<right && arr[right]>=pivot)
			right--;
		if (left < right)
			swap(arr[left], arr[right]);
	}
	swap(arr[left], arr[end]);
	return left;
}

int GetMiddle(int *arr, int size)
{
	if (arr == nullptr || size == 0)
		return NULL;
	if (size == 1)
		return arr[0];
	
	int start = 0, end = size-1;
	int mid = start + size / 2;
	int div = Partition(arr, start, end);
	while (div != mid)
	{
		if (div < mid)
			div = Partition(arr, div + 1, end);
		else
			div = Partition(arr, start, div - 1);
	}
	return arr[mid];
}

// C++优先队列默认是最小堆，这里将其变为最大堆
struct Compare
{
	int operator()(int left, int right)
	{
		return left > right;
	}
};

int getMiddle(int *arr, int size)
{
	int len = (size+1) / 2;//确保中心偏右
	priority_queue<int, vector<int>,Compare> q;
	for (int i = 0; i < len; i++)
	{
		q.push(arr[i]);
	}
	for (int i = len; i < size; i++)
	{
		if (arr[i] > q.top())
		{
			q.pop();
			q.push(arr[i]);
		}
	}
	if (!q.empty())
		return q.top();
}

int main()
{
	int a[8] = { -10,1,18,0,9,7,0,5 };
	cout << getMiddle(a, 8) << endl;
    return 0;
}