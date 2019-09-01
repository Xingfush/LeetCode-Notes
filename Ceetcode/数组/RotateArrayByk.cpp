/* 将一个数组旋转 k 位，例如
  1 2 3 4 5 6 7, 旋转 k = 3
  5 6 7 1 2 3 4,
  要求 O(n) 时间复杂度， O(1) 空间复杂度，也就是不能使用辅助数组，
  这里优先想到使用 旋转的方法，in-place，解法有很多，这里选一种简单的。
   */

void rotate(vector<int>& nums, int k)
{
	if(nums.empty()) return;
	int n = nums.size(), start = 0;
	while(n && (k% = n))
	{
		for(int i = 0;i<k;i++)
			swap(nums[i+start], nums[n-k+i+start]);
		// 根本思想就是不断地进行小范围内的旋转
		n -= k;
		start += k;
	}
}

