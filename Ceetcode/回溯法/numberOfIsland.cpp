int numIslands(vector<vector<char>>& grid) {
    if(grid.size()==0 || grid[0].size()==0) return 0;
    int m=grid.size(),n=grid[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    int res = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && grid[i][j]=='1'){
                dfs(grid,visited,i,j);
                res++;
            }
        }
    }
    return res;
}

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
    if(grid[i][j]=='0' || visited[i][j]==true) return;
    visited[i][j]=true;
    dfs(grid,visited,i-1,j);
    dfs(grid,visited,i+1,j);
    dfs(grid,visited,i,j-1);
    dfs(grid,visited,i,j+1);
}

/* 上述方法设置一个 visited 数组来防止重复访问，其实如果题目要求使用常数空间复杂度，而且原数组
    grid 可以改变时，我们可以将访问后的 元素 '1' 改为 '0'，从而避免重复访问。 */