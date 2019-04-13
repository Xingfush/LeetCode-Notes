/***************************************************************************
*  @file       main.cpp
*  @author     MISAYAONE
*  @date       26  March 2017
*  @remark     26  March 2017
*  @theme      Merge Sort
***************************************************************************/
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<time.h>

using namespace std;
int _count = 0;

			   /*第一种方法，传入参数为数组指针，左开右闭*/
			   //函数作用：合并[left,mid][mid,right]
void Merge(int a[], int left, int mid, int right)
{
	//两段区间的长度
	int length1 = mid - left;
	int length2 = right - mid;

	//分配两段新的内存空间存储原内容
	int *l1 = new int[length1];
	int *l2 = new int[length2];

	for (int i = 0; i < length1; ++i)
	{
		l1[i] = a[left + i];
	}
	for (int j = 0; j < length2; ++j)
	{
		l2[j] = a[mid + j];
	}

	//存入原内容之后，比较两个序列
	int i = 0, j = 0;
	//比较两个序列的重合部分，进行排序
	while (i<length1 && j<length2)
	{
		if (l1[i] <= l2[j])
		{
			a[left++] = l1[i++];
		}
		else
		{
			_count += length1-i;
			a[left++] = l2[j++];
		}
	}
	//两序列的剩余部分分别放于结尾
	while (i<length1)
	{
		a[left++] = l1[i++];
	}

	while (j<length2)
	{
		a[left++] = l2[j++];
	}

	//分配的内存需要释放掉
	delete[]l1;
	delete[]l2;
}

void Merge_sort(int a[], int left, int right)
{
	if (left + 1 >= right)//一个元素直接返回
		return;
	else
	{
		int mid = (left + right) / 2;//首先进行分区，然后递归操作
		Merge_sort(a, left, mid);
		Merge_sort(a, mid, right);//第一次将其分为两个区间，进行合并操作
		Merge(a, left, mid, right);
	}
}

/*第二种方法，传入参数两个迭代器*/
//Merge函数的重载，接受三个迭代器
void Merge(vector<int>::iterator begin, vector<int>::iterator mid, vector<int>::iterator end)
{
	int length1 = mid - begin;
	int length2 = end - mid;

	int *p1 = new int[length1];
	int *p2 = new int[length2];

	for (int i = 0; i < length1; ++i)
	{
		p1[i] = *(begin + i);
	}
	for (int j = 0; j < length2; ++j)
	{
		p2[j] = *(mid + j);
	}

	int i = 0;
	int j = 0;
	int k = length1;
	while (i<length1 && j<length2)
	{
		if (p1[i] < p2[j])
		{
			*(begin++) = p1[i++];
		}
		else
		{
			*(begin++) = p2[j++];

		}
	}

	while (i < length1)
	{
		*begin++ = p1[i++];
	}
	while (j < length2)
	{
		*begin++ = p2[j++];
	}

	delete[]p1;
	delete[]p2;
}
//对函数进行重载，传入一对迭代器，并进行第一次改进
void Merge_sort(vector<int>::iterator begin, vector<int>::iterator end)
{
	//若只传递了一个参数，无需进行排序，直接输出
	if (begin+1 >= end)
	{
		return;
	}

	if (begin != end)
	{
		auto mid = begin + (end - begin) / 2;
		Merge_sort(begin, mid);
		Merge_sort(mid, end);//第一次将其分为两个区间，进行合并操作
		Merge(begin, mid, end);
	}
}

/* 排序AC代码 */
#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<queue>
#include<vector>

using namespace std;

int partition(int* arr, int start, int end)
{
	int left = start;
	int right = end;

	int pivot = arr[end];

	while (left < right)
	{
		while (left < right && arr[left] < pivot)
			left++;
		while (left < right && arr[right] >= pivot)
			right--;
		if (left < right)
			swap(arr[left], arr[right]);
	}
	swap(arr[end], arr[left]);

	return left;
}

void QuickSort(int* array, int start, int end) {
	if (start<end) {
		int k = partition(array, start, end);
		QuickSort(array, start, k - 1);
		QuickSort(array, k + 1, end);
	}
}

void merge(int* array, int left, int mid, int right) {// 左闭右开
	int len1 = mid - left, len2 = right - mid;
	int* array1 = new int[len1];
	int* array2 = new int[len2];
	for (int i = 0; i < len1; i++)
		array1[i] = array[left + i];
	for (int j = 0; j < len2; j++)
		array2[j] = array[mid + j];
	int i = 0, j = 0, k = left;
	while (i < len1 && j < len2) {
		if (array1[i] < array2[j])
			array[k++] = array1[i++];
		else
			array[k++] = array2[j++];
	}
	while (i < len1)
		array[k++] = array1[i++];
	while (j < len1)
		array[k++] = array2[j++];
	delete[]array1;
	delete[]array2;
}

void MergeSort(int*array, int start, int end) {
	if (end - start > 1) {
		int mid = (start + end) / 2;
		MergeSort(array, start, mid);
		MergeSort(array, mid, end);
		merge(array, start, mid, end);
	}
}

void InsertSort(int*array, int length) {
	for (int i = 1; i < length; i++) {
		int temp = array[i];
		while(i>0 && temp<array[i-1])
			array[i--] = array[i - 1];
		array[i] = temp;
	}
}

void ShellSort(int*array, int length) {
	int gap = length / 2;
	while (gap != 0) {
		for (int i = gap; i < length; i++) {
			int temp = array[i];
			while (i > gap && temp < array[i - gap]) {
				array[i] = array[i - gap];
				i -= gap;
			}
			array[i] = temp;
		}
		gap /= 2;
	}
}

void BubbleSort(int*array, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
		}
	}
}

int main(int argc, char **argv)
{
	clock_t Start_time = clock();
	int a[] = { -2,3,10,5,-4,3,8,8,1,3 };
	QuickSort(a, 0, 9);
	cout << "快速排序后：";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	MergeSort(a, 0, 10);
	cout << "归并排序后：";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	InsertSort(a, 10);
	cout << "插入排序后：";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	ShellSort(a, 10);
	cout << "插入排序后：";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	clock_t End_time = clock();
	cout << "Running time is :" << static_cast<double>(End_time - Start_time) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	return 0;
}