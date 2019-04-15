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
        if(dp[i][j]>0) return dp[i][j];
        int res = 1;
        if(i>0 && matrix[i][j]>matrix[i-1][j]) res=max(res,dfs(matrix,i-1,j)+1);
        if(i<rows-1 && matrix[i][j]>matrix[i+1][j]) res=max(res,dfs(matrix,i+1,j)+1);
        if(j>0 && matrix[i][j]>matrix[i][j-1]) res=max(res,dfs(matrix,i,j-1)+1);
        if(j<cols-1 && matrix[i][j]>matrix[i][j+1]) res=max(res,dfs(matrix,i,j+1)+1);
        dp[i][j]= res;
        return res; 
    }
};


