/* 邻接矩阵版本
	广度遍历有两个定义：
	1.已访问：visited，相当于树层次遍历的首次接触如队一样
	2.已探索：从队首提取，真正的访问，然后将其子节点入队 */
#define INT_MAX 100000 // 不应该使用 climits中的 INT_MAX

void bfs(int s, vector<vector<int>> G)
{
	int n = G.size();
	queue<int> q;
	vector<bool> visited(n);
	fill(visited.begin(), visited.end(), false);
	q.push(s);
	visited[s] = true; // 防止后面重复入队
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		for (int i = 0; i < n; i++) {
			if (G[temp][i] != INT_MAX && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	cout << endl;
}

// 顺序很重要：一定是先访问 visited，然后入队之后，提取队首才能探索