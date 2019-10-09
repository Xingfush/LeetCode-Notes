/* 动态规划+滚动数组：经典实现，初始条件一定找好 */

int EditDistance(const string& s,
                 const string& t){
    int m = s.size(), n = t.size();
    vector<int> dp(n+1), dp2(n+1);
    for(int j=0;j<=n;j++)
        dp2[j] = j; // 长度为 j 的 t 如何变为 s 的空串
    for(int i=1;i<=m;i++){
        dp[0] = i; // t 为空串时，通过插入变为长度为 i 的 s
        for(int j=1;j<=n;j++){
            dp[j] = (s[i]==t[j]?dp2[j-1]:min(dp2[j-1],min(dp[j-1],dp2[j]))+1);
        }
        // swap(dp,dp2)，使用 vector::swap()方法而不是 STL::swap()
        dp.swap(dp2);
    }
    
    return dp2[n];
}