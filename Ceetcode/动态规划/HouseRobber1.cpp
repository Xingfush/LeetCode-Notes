/* 动态转移方程：dp[i] 表示到 i 为止能够收获的最大财富，分为两种情况
	1.抢当前的第 i 家：dp[i] = dp[i-2] + nums[i]
	2.不抢当前的第 i 家：dp[i] = dp[i-1] */

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    else if(n==1) return nums[0];
    else if(n==2) return max(nums[1],nums[0]);
    
    vector<int> dp(n+1,0);
    dp[1]=nums[0];
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
    }
    return dp[n];
} 