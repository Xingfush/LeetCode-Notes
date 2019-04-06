/* 解法1：使用动态规划，这里的 dp[i]表示在索引i 的位置，剩余的步数，如何理解这里的剩余步数，
	因为这里的 nums[i] 表示最多跳的步数，而不是必须要跳这么多，那么从这一步调到下一步的任何可到达范围，
	都会产生剩余的步数，从[0,dp[i-1]-1]，或者我们发现调到这个位置之后，这个位置的nums[i-1]很大，我们
	就选择这个位置进行下一次的起跳，以获得更大的剩余步数。 */

bool canJump(vector<int>& nums) {
    vector<int> dp(nums.size(),0);
    for(int i=1;i<nums.size();i++){
        dp[i]=max(dp[i-1],nums[i-1])-1;
        if(dp[i]<0) return false;
    }
    return true;
}

/* 另一种贪心解法 */

bool canJump(vector<int>& nums){
	int n = nums.size(), reach =0;
	for(int i=0;i<n;i++){
		if(reach<i || reach>=i-1) // 先判断 reach 能不能到达现在的位置，然后在更新 reach
			break;
		reach = max(reach, i+nums[i]);
	}
	return reach>=i-1;
}