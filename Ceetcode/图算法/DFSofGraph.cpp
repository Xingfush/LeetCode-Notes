/* 邻接矩阵版本
	1.非递归 */
void dfs_iterative(int s, vector<vector<int>> G)
{
	int n = G.size();
	vector<bool> visited(n);
	stack<int> st;
	st.push(s);
	while (!st.empty()) {
		int temp = st.top();
		st.pop();
		cout << temp << " "; // 只有 没有访问过的才会入栈，所以访问后才设为已访问
		visited[temp] = true;
		for (int i = 0; i < n; i++) { // 将所有子节点入栈
			if (G[temp][i] != INT_MAX && !visited[i]) {
				st.push(i);
			}
		}
	}
	cout << endl;

}

/*  2.递归版本 */
void dfs_recursive(int s, vector<vector<int>> G, vector<bool>& visited)
{
	cout << s << " ";
	visited[s] = true;
	for (int i = 0; i < n; i++) {
		if (G[s][i] != INT_MAX && !visited[i]) {
			dfs_recursive(i, G, visited);
		}
	}
}