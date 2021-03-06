/* 最经典的一题，绝对不能做错 */

/* 状态转移方程：max_end_here = max(max_end_here+array[i],array[i]) */

int MaxSubArray(const vector<int>& nums) {
    int max_end_here = nums[0];
    int max_so_far = nums[0];
    for(int i=1;i<nums.size();i++)
    {
        max_end_here = max(max_end_here+nums[i],nums[i]);
        max_so_far = max(max_end_here, max_so_far);
    }
    return max_so_far;
}

/* 需要返回坐标 */

vector<int> MaxSubArray(vector<int>& nums){
	int start = 0, end = 0, j = 0; // j 是游标
	int max_end_here = nums[0], max_so_far = nums[0];
	for(int i=1;i<nums.size();i++){
		if(max_end_here<0){
			max_end_here = 0;
			j = i;
		}
		max_end_here += nums[i];
		if(max_end_here>max_so_far){
			max_so_far = max_end_here;
			start = j;
			end = i;
		}
	}

	return {start,end}; // C++ 11的新规定，可以返回花括号列表用于初始化vector对象，注意，千万不是数组
}
