#include "stdafx.h"
#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

/* 采用左开右闭表示法 */
int InversePairsCore(int* data, int* copy, int start, int end)
{
	if (end-start<=1)
	{
		copy[start] = data[start];
		return 0; // 只有一个元素，返回0个逆序对
	}

	int middle = start + (end - start)/2;

	int leftPairs = InversePairsCore(copy, data, start, middle);
	int rightPairs = InversePairsCore(copy, data, middle, end);

	int i = start;
	int j = middle;

	int indexCopy = start;

	int count = 0;
	while (i < middle && j < end)
	{
		if (data[i] > data[j])
		{
			count += middle - i;
			copy[indexCopy++] = data[j++];
		}
		else
		{
			copy[indexCopy++] = data[i++];
		}
	}
	while (i < middle)
		copy[indexCopy++] = data[i++];
	while (j < end)
		copy[indexCopy++] = data[j++];

	return leftPairs + count + rightPairs;
}

int InversePairs(int *data, int length)
{
	if (data == nullptr || length <= 0)
		return 0;

	int *copy = new int[length];
	for (int i = 0; i < length; i++)
		copy[i] = data[i];

	int count = InversePairsCore(data, copy, 0, length);
	delete [] copy;

	return count;
}


int main(int argc, char **argv)
{
	clock_t Start_time = clock();
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	//MergeSort(a, 0, 10);
	for (size_t i = 0; i != 10; ++i)
	{
		cout << a[i] << " ";
	}
	int pairs = InversePairs(a, 10);
	cout << endl;

	cout << "逆序对数目：" << pairs << endl;
	clock_t End_time = clock();
	cout << "Running time is :" << static_cast<double>(End_time - Start_time) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	//cin.get();
	return 0;
}