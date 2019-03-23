#include<iostream>
#include<time.h>
#include<vector>
#include<functional>
#include<algorithm> // pop_heap,push_heap等STL函数都包含在 algorithm中

using namespace std;

class DynamicArray
{
public:
	void Insert(int num)
	{
		if (((max.size() + min.size()) & 0x1) == 0) // 偶数个元素加入最小堆
		{
			if (max.size() > 0 && max[0] > num)
			{
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());
				num = max[0];
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}
		else
		{
			if (min.size() > 0 && min[0] < num)
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(),greater<int>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}
	}

	int GetMedian()
	{
		int size = min.size() + max.size();
		if (size == 0)
			throw exception("No numbers are avaiable");
		int median = 0;
		if ((size & 0x1) == 1)
			median = min[0];
		else
			median = (max[0] + min[0]) / 2;

		return median;
	}
private:
	vector<int> max;
	vector<int> min;
};