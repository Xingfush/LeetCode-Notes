
/* 二分法查找的变形：找到重复的排序数组的出现的第一个位置 */

int BinarySearchFirst(int* array, unsigned left, unsigned right, int key)
{
	int res = -1;
	while (left < right)
	{
		unsigned mid = left + (right - left) / 2;
		if (array[mid] == key)
		{
			res = mid;
			right = mid;
		}
		else if (array[mid] < key)
			left = mid + 1;
		else
			right = mid;
	}
	return res;
}

/* 二分法查找的变形：找到重复的排序数组的出现的最后一个位置 */

int BinarySearchLast(int* array, unsigned left, unsigned right, int key)
{
	int res = -1;
	while (left < right)
	{
		unsigned mid = left + (right - left) / 2;
		if (array[mid] == key)
		{
			res = mid;
			left = mid+1;
		}
		else if (array[mid] < key)
			left = mid + 1;
		else
			right = mid;
	}
	return res;
}