
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

// 查找形式完全一样，只是在arr[mid]==key的时候的查找方向不同了，而且要把答案记录一下。
/* LeetCode 上一个经典的题目：找出开始索引和结束索引 */
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(2,-1);
    if(nums.size()==0)
        return result;
    
    int left=0,right=nums.size();
    while(left<right)
    {
        int mid = left+(right-left)/2;
        if(nums[mid]==target)
        {
            result[0]=mid;
            right=mid;
        }
        else if(nums[mid]<target)
            left=mid+1;
        else
            right=mid;
    }
    left = 0,right=nums.size();
    while(left<right)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]==target)
        {
            result[1]=mid;
            left=mid+1;
        }
        else if(nums[mid]<target)
            left=mid+1;
        else
            right=mid;
    }
    return result;
}
