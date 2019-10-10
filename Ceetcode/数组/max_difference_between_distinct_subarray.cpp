/* 有一个数组，找到两个不重复的连续子序列，使其差最大 */

int MaxSumHelper(const vector<int>& nums){
	int n = nums.size();
	vector<int> sum1(n,0), sum2(n,0);

	// 一次遍历，找到每个坐标位的之前的最大和
	// 本质就是 max subarray sum
	int sum = 0, temp = INT_MIN;
	for(int i=0;i<nums.size();i++){
		sum += nums[i];
		temp = max(temp, sum);
		sum1[i] = temp;
		if(sum<0) sum = 0;
	}

	// 二次遍历，找到每个坐标位之前的最小和
	// 本质就是 min subarray sum
	sum = 0, temp = INT_MAX;
	for(int i=nums.size()-1;i>=0;i--){
		sum += nums[i];
		temp = min(temp, sum);
		sum2[i] = temp;
		if(sum>0) sum = 0;
	}

	int res = INT_MIN;
	for(int i=0;i<nums.size()-1;i++)
		res = max(res, sum1[i]-sum2[i+1]); // 这里要求两个子序列都不为空，因此要错开

	return res;
}

int MaxSum(vector<int> nums){
	int a = MaxSumHelper(nums);
	reverse(nums.begin(),nums.end());
	int b = MaxSumHelper(nums);
	return max(a,b);
}

/* 例 {1,2,5,10,-14,12,-1,-2,-3,-5};
 输出为 [1,2,5,10] - [-1,-2,-3,-5] = 32
 这里需要注意，由于我们假设了最大最序列在左，最小子序列在右，
 因此需要将 nums reverse一下，然后在取最大值。 */


