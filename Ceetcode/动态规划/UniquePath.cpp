/* 这一题是最典型的动态规划，方法没有任何新意，只是想记录一下对于动态规划表空间复杂度的处理
   1.当边界条件不需要单独的 */

/* 问题：从左上角到右下角，只准向下或向右移动，有多少种走法？ */
// 矩阵没有阻碍
int uniquePaths(int m, int n) {
    vector<int> dp(n,1);
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[j]=dp[j-1]+dp[j];
        }
    }
    return dp[n - 1];
}

// 矩阵中有阻碍，必须绕过
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(),n = obstacleGrid[0].size();
    vector<long> dp(n,0);
    dp[0]=1; // 这个初始化非常重要
    for(int i=0;i<m;i++){
        dp[0]=(obstacleGrid[i][0]==1?0:dp[0]); // 一定注意第一列的值如何初始化，dp[i][0]=d[i-1][0]:0
        for(int j=1;j<n;j++){
            dp[j]=(obstacleGrid[i][j]==1)?0:dp[j]+dp[j-1];
        }
    }  
    return dp[n-1];
}

/* 可以简单地总结一下，问题1中，我们直接从初始化第一行全为1，从第二行 走到 最后一行 i=1,i<m,i++
   对于列的处理，我们也是，直接从第二列开始，这是因为边界条件可以直接用于初始
   而问题二，因为有障碍，若要初始化第一行和第一列，我们需要先遍历矩阵，这样代码会变得复杂；
   所以，直接将边界条件扩展到第 0 行，代码量减少，逻辑更加完整，这里格外注意第一列的初始化。
   这个思路和 最长公共子序列 的做法是一样的。