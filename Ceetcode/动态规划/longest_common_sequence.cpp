/* 最长公共子序列：经典的动态规划题目，时常复习，解法经典 */
/* 下面是测试通过的案例 */


int LongestCommonSequence(const string& A,
                          const string& B){
    int m = A.size(), n = B.size();
    if(m<n) return LongestCommonSequence(B,A);

    vector<int> dp(n+1,0),dp2(n+1,0);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[j] = (A[i]==B[j]?dp2[j-1]+1:max(dp[j-1],dp2[j]));
        }
        dp.swap(dp2);
    }

    return dp2[n];
}

