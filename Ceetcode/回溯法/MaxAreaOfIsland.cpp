int maxAreaOfIsland(vector<vector<int>>& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    int m=grid.size(),n=grid[0].size();
    int res = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                res = max(res,dfs(grid,i,j));
            }
        }
    }
    return res;
}

int dfs(vector<vector<int>>& grid, int i, int j){
    if(i<0||i>=grid.size()||j<0||j>=grid[0].size()) return 0;
    if(grid[i][j]==0) return 0;
    grid[i][j]=0;
    return 1+dfs(grid,i-1,j)+dfs(grid,i+1,j)+dfs(grid,i,j-1)+dfs(grid,i,j+1);
}