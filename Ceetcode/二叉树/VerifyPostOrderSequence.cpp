/* 给定一个数组，判断这个数组是否可能是一个二叉搜索树的后序遍历 */
bool isPostOrder(vector<int>& nums) {
	return isPostOrderCore(nums,0,nums.size()-1);
}

bool isPostOrderCore(vector<int>& nums, int start, int end) {
	if (start >= end) return true;
	int k = nums[end];
	int i = start;
	for (; i < end; i++) {
		if (nums[i] > k) break;
	}
	for (int j = i; j < end; j++) {
		if (nums[j] <= k) return false;
	}
	return isPostOrderCore(nums, start, i - 1) && isPostOrderCore(nums, i, end - 1);
}
