#include "stdafx.h"
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int Partition(int*arr, int start, int end)
{
	int left = start, right = end; 
	// 这里一定是right=end，而不是right=end-1，因为当初始start=end时会出错
	int pivot = arr[end];
	while (left < right)// 全是left<right，终止条件肯定是left撞上了right，而不会是right撞left
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

int findMedian(vector<int>& nums)
{
	int k = (nums.size() - 1) >> 1;
	int left = 0, right = nums.size() - 1;
	int result=0;
	while (true)
	{
		int q = partition(nums, left, right);
		if (q == k)
		{
			result = nums[q];
			break;
		}
		else if (q < k)
			left = q + 1;
		else
			right = q - 1;
	}
	return result;
}

// C++优先队列默认是大顶堆，也就是队头元素最大，这里将其变为小顶堆
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