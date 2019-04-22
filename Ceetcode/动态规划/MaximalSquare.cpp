/* 本题和 maximal rectangle 很相似，但是解法差别很大，注意 */
int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    int res = 0;
    vector<int> dp(n,0),dp2(n,0);
    for(int i=0;i<m;i++){
        dp[0]=(matrix[i][0]=='0')?0:1;
        res = max(res,dp[0]);
        for(int j=1;j<n;j++){
            if(matrix[i][j]=='0')
                dp[j]=0;
            else
                dp[j]=min(dp[j-1],min(dp2[j-1],dp2[j]))+1;
            res = max(res,dp[j]);
        }
        swap(dp2,dp);
        fill(dp.begin(),dp.end(),0);
    }
    return res*res;
}

