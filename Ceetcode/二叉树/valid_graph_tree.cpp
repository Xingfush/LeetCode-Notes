/* 标准的图的深度遍历：当dfs到某个节点，先看当前节点是否被访问过，如果已经访问过，
说明肯定有环，直接返回false，如果没有被访问过，那么我们将其标为 已访问，
然后到邻接表中进行深度遍历，这里需要一个变量 pre来记录上一个节点，
以免回到上一个节点，遍历结束，检查是否有未访问的节点，判断全连通 */

bool validTree(const vector<pair<int,int>>& edges, int n){
	vector<vector<int>> g(n, vector<int>());
	vector<bool> v(n,false); // 节点是否被访问过
	// 建立临接连表
	for(auto a:edges){
		g[a.first].push_back(a.second);
		g[a.second].push_back(a.first);
	}
	if(!dfs(g,v,0,-1)) return false;
	for(auto a:v){
		if(!a) return false;
	}
	return true;
}

// 就是一个图的深度遍历
bool dfs(vector<vector<int>>& g, vector<int>& v,
		 int cur, int pre){
	if(v[cur]) return false; // 如果被重复访问，必是忧患有环
	v[cur] = true;
	for(auto a:g[cur]){
		if(a!=pre){ // 因为是无向图，所以用 pre 标记，防止重复访问
			if(!dfs(g,v,a,cur)) return false;
		}
	}

	return true;
}
