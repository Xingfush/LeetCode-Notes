/* 使用有限的给定的字符，尽可能多的构成数组中的元素，来源于0-1背包问题的自顶向下的思想，仔细体会。 */

int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    
    for(int i=1;i<=len;i++){
        int ones = count(strs[i-1].begin(),strs[i-1].end(),'1');
        int zeros = strs[i-1].size()-ones;
        for(int j=m;j>=zeros;j--){
            for(int k=n;k>=ones;k--){
                dp[j][k]=max(dp[j][k],dp[j-zeros][k-ones]+1);     
            }
        }
    }
    return dp[m][n];
}

