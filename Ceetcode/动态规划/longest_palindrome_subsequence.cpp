/* 最长回文子序列：
    dp[i][j] = s[i]==s[j]?dp[i+1][j-1]:max(dp[i+1][j],dp[i][j-1]) */

int LongestPalindromeSubsequence(const string& s){
    int n = s.size();
    vector<int> dp(n,0),dp2(n,0);
    for(int i=n-1;i>=0;i--){ // 这个动态规划的顺序和平常的不太一样
        dp[i] = 1;
        for(int j=i+1;j<n;j++){ // j>i，此时 dp2[j-1] +2才成立，否则可能只是 +1
            dp[j] = (s[i]==s[j]?dp2[j-1]+2:max(dp2[j],dp[j-1]));
        }
        dp.swap(dp2);
    }
    
    return dp2[n-1];
}