/* 题目要求比较严格，n个元素的数组，每个元素的范围是[0,n-1]，但是有若干个元素重复了
   若干次，请找出任意一个重复的元素
   要求：线性时间复杂度，空间复杂度为常数，即不能使用哈希表 */

int duplicate(int *array, int length)
{
	if (array == nullptr|| length<1)
		return -1;

	for (int i = 0; i < length; i++)
	{
		if (array[i] > length - 1|| array[i] < 0)
			return -1;
	}

	for (int i = 0; i < length; i++)
	{
		while (array[i] != i)
		{
			if (array[array[i]] == array[i])
				return array[i];
			swap(array[i], array[array[i]]);
		}
	}
	return -1;
}