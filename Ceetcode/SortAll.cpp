/***************************************************************************
*  @file       main.cpp
*  @author     Fu Xing
*  @date       10  July 2019
*  @remark     10  July 2019
*  @theme      Sorting Algorithm Testing
***************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int* generateRandomArray(int n)
{
	int * arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand();
	return arr;
}

int partition(int* array, int start, int end)
{
	int left = start, right = end;
	int pivot = array[end];
	while (left<right)
	{
		while (left<right && array[left]<pivot)
			left++;
		while (left<right && array[right] >= pivot)
			right--;
		if (left<right)
			swap(array[left], array[right]);
	}
	swap(array[left], array[end]);
	return left;
}

void QuickSort(int* array, int start, int end)
{
	if (start<end) { // 至少有一个元素
		int k = partition(array, start, end);
		QuickSort(array, start, k - 1); // K-1, k +1
		QuickSort(array, k + 1, end);
	}
}

void Merge(int a[], int left, int mid, int right)
{
	// 两端区间长度
	int length1 = mid - left;
	int length2 = right - mid;

	//分配内存
	int *l1 = new int[length1];
	int *l2 = new int[length2];

	for (int i = 0; i<length1; i++)
		l1[i] = a[left + i];
	for (int j = 0; j<length2; j++)
		l2[j] = a[right + j];

	int i = 0, j = 0;
	while (i<length1 && j<length2)
	{
		if (l1[i] <= l2[j])
			a[left++] = l1[i++];
		else
			a[left++] = l2[j++];
	}
	while (i<length1)
		a[left++] = l1[i++];
	while (j<length2)
		a[left++] = l2[j++];

	// 删除分配的内存
	delete[] l1;
	delete[] l2;
}

void MergeSort(int a[], int left, int right)
{
	if (right - left > 1)
	{
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid, right);
		Merge(a, left, mid, right);
	}
}

void InsertSort(int* array, int length)
{
	for (int i = 1; i<length; i++)
	{
		int temp = array[i];
		while (i>0 && temp<array[i - 1])
			array[i--] = array[i - 1];
		array[i] = temp;
	}
}

void ShellSort(int* array, int length)
{
	int gap = length / 2;
	while (gap != 0)
	{
		for (int i = gap; i<length; i++)
		{
			int temp = array[i];
			while (i>gap && temp < array[i - gap]) {
				array[i] = array[i - gap];
				i -= gap;
			}
			array[i] = temp;
		}
		gap /= 2;
	}
}

void BubbleSort(int* array, int length)
{
	for (int i = 0; i<length; i++)
	{
		for (int j = 0; j<length - i - 1; j++)
		{
			if (array[j]<array[j + 1])
				swap(array[j], array[j + 1]);
		}
	}
}

// 或许只有对于 array 指针引用，这样的方式才是有意义的
void Heapify(int* array, int n, int i)
{
	// 设定 n 为 array 的元素个数
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;

	if (left<n - 1 && array[left]>array[i])
		largest = left;
	if (left<n - 1 && array[right]>array[i])
		largest = right;
	if (largest != i) {
		swap(array[largest], array[i]);
		Heapify(array, n, largest);
	}

}

void HeapSort(int* array, int length)
{
	if (array == nullptr || length <= 1)
		return;
	for (int i = (length >> 1); i >= 0; i--) {
		Heapify(array, length, i);
	}
	for (int n = length; n >= 1; n--)
	{
		swap(array[n - 1], array[0]);
		Heapify(array, n - 1, 0);
	}
}


int main(int argc, char **argv)
{
	cout << "输入随机数组长度：";
	int n;
	cin >> n;
	int* arr = generateRandomArray(n);
	cout << "快速排序：";
	clock_t Start_time = clock();
	MergeSort(arr,0,n);
	clock_t End_time = clock();
	cout << "Running time is :" << static_cast<double>(End_time - Start_time) / CLOCKS_PER_SEC * 1000 << " ms" << endl;


	return 0;
}

