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
    int rows;
    int cols;
    vector<vector<int>> dp;
    
    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j]>0) return dp[i][j]; // 缓存加速，即动态规划
        int res = 1; // 每次的 res 从1开始计，是为了方便求出每个子问题的解，后面赋给 dp
        if(i>0 && matrix[i][j]>matrix[i-1][j]) res=max(res,dfs(matrix,i-1,j)+1); // 知道每一次的步进量，每次重新从子问题开始求，最优子问题
        if(i<rows-1 && matrix[i][j]>matrix[i+1][j]) res=max(res,dfs(matrix,i+1,j)+1);
        if(j>0 && matrix[i][j]>matrix[i][j-1]) res=max(res,dfs(matrix,i,j-1)+1);
        if(j<cols-1 && matrix[i][j]>matrix[i][j+1]) res=max(res,dfs(matrix,i,j+1)+1);
        dp[i][j]= res; // 只有四个方向遍历完后才会 作为该位置的
        return res; 
    }
};


