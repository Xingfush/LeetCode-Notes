/* 本题就是最大子序列和的扩展 */

int maxSubArray(vector<int>& nums)
{
	int max_so_far = nums[0], max_end_here = nums[0];
	for(int i=1;i<nums.size();i++){
		max_end_here = max(nums[0], max_end_here+nums[0]);
		max_so_far = max(max_so_far, max_end_here);
	}
	return max_so_far;
}

int maxSubmatrix(vector<vector<int>>& a)
{
	if(a.empty() || a[0].empty()) return 0;
	int m = a.size(), n = a[0].size();
	int res = a[0][0], tmp;

	for(int i=0;i<m;i++){
		vector<int> dp(n, 0);
		for(int j=i;j<n;j++){
			for(int k=0;k<n;k++){
				dp[k] += a[j][k];
			}
			tmp = maxSubArray(dp);
			res = max(res, tmp);
		}
	}
	return res;
}
