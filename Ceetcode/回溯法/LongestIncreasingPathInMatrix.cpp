class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        rows = matrix.size();
        cols = matrix[0].size();
        int res = 0;
        dp = vector<vector<int>>(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                res = max(res,dfs(matrix,i,j));
            }
        }
        return res;
    }
private:
/* 设置全局变量 */
    int rows ,cols;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if(dp[i][j]>0)  // dp 也起到了防止重复访问的作用
            return dp[i][j]; // 已访问，作剪枝
        int res = 1;
        if(i>0 && matrix[i][j]>matrix[i-1][j]) // 终止条件和扩张方向合在一起 
            res = max(res, dfs(matrix, i-1, j)+1);
        if(i<rows-1 && matrix[i][j]>maxtrix[i+1][j]) 
            res = max(res, dfs(matrix, i+1, j)+1);
        if(j>0 && matrix[i][j]>maxtrix[i][j-1])
            res = max(res, dfs(matrix, i, j-1)+1);
        if(j<cols-1 && matrix[i][j]>matrix[i][j+1])
            res = max(res, dfs(matrix, i, j+1)+1);
        dp[i][j] = res; // 四个方向遍历完之后才最作为该位置的 dp，下一次剪枝，状态更新
        return res;
    }

    /* 这个问题没有收敛条件 */
};

/* 对于求最大值的问题，一边要设置一个 max 不断更新最大值，一边要返回本结点的
    状态，本题用了动态规划来进行剪枝 */


