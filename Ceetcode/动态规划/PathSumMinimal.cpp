int minPathSum(vector<vector<int>>& grid) {
    if(grid.size()==0 || grid[0].size()==0)
        return 0;
    int m =grid.size(), n=grid[0].size();

    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for(int i=0;i<m;i++){
        dp[0] += grid[i][0];
        for(int j=1;j<n;j++){
            dp[j]=min(dp[j-1],dp[j])+grid[i][j];
        }
    }
    return dp[n-1];
}