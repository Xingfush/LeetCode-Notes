/* 最经典的一题，绝对不能做错 */

/* 状态转移方程：max_end_here = max(max_end_here+array[i],array[i]) */

int maxSubArray(vector<int>& nums) {
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

vector<int> maxSubArray(vector<int>& nums){
	int start = 0, end = 0;
	int max_end_here = nums[0];
	int max_so_far = nums[0];
	int j = 0;
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
	vector<int> result(2,0);
	result[0] = start;
	result[1] = end;
	return result;
}
