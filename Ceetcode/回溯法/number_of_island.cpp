void dfs(vector<vector<int>>& m, int i, int j){
    if(i<0 || i>=m.size() || j<0 || j>=m[0].size()) return;
    if(m[i][j]==0) return;
    m[i][j] = 0;
    dfs(m,i-1,j);
    dfs(m,i+1,j);
    dfs(m,i,j-1);
    dfs(m,i,j+1);
}

int MaxAreaOfIsland(vector<vector<int>> m){
    if(m.empty() || m[0].empty()) return 0;
    int res = 0;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            if(m[i][j]){
                dfs(m,i,j);
                res++;
            }
        }
    }
    
    return res;
}

/* 上述方法设置一个 visited 数组来防止重复访问，其实如果题目要求使用常数空间复杂度，而且原数组
    grid 可以改变时，我们可以将访问后的 元素 '1' 改为 '0'，从而避免重复访问。 */