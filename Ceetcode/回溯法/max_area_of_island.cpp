int dfs(vector<vector<int>>& m, int i, int j){
    if(i<0 || i>=m.size() || j<0 || j>=m[0].size()) return 0;
    if(m[i][j]==0) return 0;
    m[i][j] = 0;
    return 1+dfs(m,i-1,j)+dfs(m,i+1,j)+dfs(m,i,j-1)+dfs(m,i,j+1);
}

int MaxAreaOfIsland(vector<vector<int>> m){
    if(m.empty() || m[0].empty()) return 0;
    int res = 0;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            if(m[i][j])
                res = max(res, dfs(m,i,j));
        }
    }
}