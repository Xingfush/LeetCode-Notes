/* 对一组数加上正负号，使得这组数和为0，求解法的总数
	这里使用最方便的动态规划来解，使用 dp[i][j] 表示到第 i-1 个数字且和为 j 的总数 */

int findTargetSumWays(vector<int>& nums, int S) {
    int n = nums.size();
    vector<unordered_map<int,int>> dp(n+1); // 这里使用 hash table主要是为了节省空间
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(auto &a:dp[i]){
            int sum= a.first, cnt = a.second;
            dp[i+1][sum+nums[i]] += cnt;
            dp[i+1][sum-nums[i]] += cnt;
        }
    }
    return dp[n][S];
}

/* 上述解法的内存空间显然可以进行优化，因为 dp[i+1]只和dp[i]有关 */
int findTargetSumWays(vector<int>& nums, int S) {
    int n = nums.size();
    unordered_map<int,int> dp;
    dp[0] = 1;
    for(int i=0;i<n;i++){
        unordered_map<int,int> dp2; // 清零初始化
        for(auto &a:dp){
            int sum= a.first, cnt = a.second;
            dp2[sum+nums[i]] += cnt;
            dp2[sum-nums[i]] += cnt;
        }
        dp=dp2;
    }
    return dp[S];
}