/* 本题就是最大子序列和的扩展 */

int MaxSubarraySum(const vector<int>& nums){
	int max_so_far = nums[0], max_end_here = nums[0];
	for(int i=1;i<nums.size();i++){
		max_end_here = max(nums[0], max_end_here+nums[0]);
		max_so_far = max(max_so_far, max_end_here);
	}
	return max_so_far;
}

int MaxSubmatrixSum(const vector<vector<int>>& m){
    if(m.empty() || m[0].empty()) return 0;
    int rows = m.size(), cols = m[0].size();
    int res = m[0][0], temp;

    for(int i=0;i<rows;i++){
        vector<int> dp(cols,0);
        for(int j=i;j<rows;j++){
            for(int k=0;k<cols;k++){
                dp[k] += dp[j][k];
            }
            temp = MaxSubarraySum(dp);
            res = max(res, temp);
        }
    }

    return res;
}
