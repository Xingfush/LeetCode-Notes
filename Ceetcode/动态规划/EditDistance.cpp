/* 动态规划+滚动数组：经典实现，初始条件一定找好 */

int minDistance(string word1, string word2) {
    int m = word1.size(),n=word2.size();
    vector<int> dp(n+1,0);
    vector<int> dp2(n+1,0);
    for(int i=0;i<n+1;i++)
        dp2[i]=i; // 初始条件 1
    for(int i=1;i<=m;i++){
        dp[0]=i;  // 初始条件 2
        for(int j=1;j<=n;j++){
            if(word1[i-1]==word2[j-1])
                dp[j]=dp2[j-1];
            else
                dp[j]=min(dp2[j-1],min(dp[j-1],dp2[j]))+1;
        }
        // swap(dp,dp2)，使用 vector::swap()方法而不是 STL::swap()
        dp.swap(dp2); // 常数时间复杂度操作
    }
    return dp2[n];
}