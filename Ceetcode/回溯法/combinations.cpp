/* 组合：相对于排列要简单一点，因为这里不用考虑顺序，所以，只用长度作为终止条件即可 */
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> out;
    dfs(n, k, 1, out, res);
    return res;
}

void dfs(int n, int k, int ind, vector<int>& out, vector<vector<int>>& res) {
    if (out.size() == k) {
    	res.push_back(out);
    	return;
    }
    for (int i = ind; i <= n; ++i) {
        out.push_back(i);
        dfs(n, k, i + 1, out, res);
        out.pop_back();
    }
}

