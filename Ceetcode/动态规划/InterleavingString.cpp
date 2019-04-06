/* 动态规划的经典题目： */

bool isInterleave(string s1, string s2, string s3) {
    int m=s1.size(), n =s2.size();
    int len= s3.size();
    if(m+n!=len) return false;
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    dp[0][0]=true;
    for(int i=1;i<=m;i++)
        dp[i][0]=dp[i-1][0] && (s1[i-1]==s3[i-1]);
    for(int j=1;j<=n;j++)
        dp[0][j]=dp[0][j-1] && (s2[j-1]==s3[j-1]);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if((dp[i][j-1] && s2[j-1]==s3[j+i-1]) || (dp[i-1][j] && s1[i-1]==s3[j+i-1]))
               dp[i][j]=true;
        }
    }
    return dp[m][n];
}

/* 动态规划+滚动数组：空间复杂度降低 */
bool isInterleave(string s1, string s2, string s3) {
    int m=s1.size(), n =s2.size();
    int len= s3.size();
    if(m+n!=len) return false;
    vector<bool> dp(n+1,false);
    vector<bool> dp2(n+1,false);
    
    dp2[0]=true;
    for(int j=1;j<=n;j++)
        dp2[j]=dp2[j-1] && (s2[j-1]==s3[j-1]);
    for(int i=1;i<=m;i++){
        dp[0]=dp2[0] && (s1[i-1]==s3[i-1]);
        for(int j=1;j<=n;j++){
            if((dp[j-1] && s2[j-1]==s3[j+i-1]) || (dp2[j] && s1[i-1]==s3[j+i-1]))
                dp[j]=true;
            else
                dp[j]=false;
        }
        swap(dp,dp2);
    }
    return dp2[n];
}