/* 问题的本质是拓扑排序：拓扑排序必须满足以下两个条件：
	1.每个顶点出现且只出现一次；
	2.若存在一条从顶点 A 到顶点 B 的路径，那么在序列中A 出现在 B 的前面。
如何得到拓扑排序：
	1.从DAG 图中选择一个没有前驱顶点（即入度为0）的顶点并输出；
	2.从图中删除该顶点和所有以他为起点的有向边；
	3.重复1,2直到当前的DAG图为空或当前图中不存在 无前驱的顶点 为止，后一种情况说明 图中必定有环。
如何判断图中是否有环：
	本题的思路和上面是一样的，有一点需要注意，为了实现方便，只对入度进行操作，因为我们关心的只有
	入度是否为 0 ，可能有的边已经不存在了，但是仍然按照 g邻接链表把它末端结点入度降低了，因为没有
	没有删除之前操作过的边，也就是会出现入度为 负 的情况，这里是不影响的！！！ */

bool canFinish(int numCourses, vector<pair<int,int>>& prerequisites){
	graph g = buildGraph(numCourses, prerequisites);
	vector<int> degrees = computeIndegrees(g);// 计算每个顶底的入度

	for(int i=0;i<numCourses;i++){
		int j =0; // 这里的 j 必须在 for循环外声明，因为作用域问题
		for(;j<numCourses;j++){
			if(!degrees[j]){
				break;
			}
		} // 找到一个入度为 0 的顶点
		if(j==numCourses){ // 如果找不到入度为 0 的顶点，即找到了头，那么一定存在环
			return false;
		}
		degrees[j]--;
		for(int v:g[j]) 
			degrees[v]--;
	}
	return true;
}

typedef vector<vector<int>> graph;

graph buildGraph(int numCourses, vector<pair<int,int>>& prerequisites){
	graph g(numCourses);
	for(auto p:prerequisites){
		g[p.second].push_back(p.first);
	}
	return g;
}

vector<int> computeIndegrees(graph& g){
	vector<int> degrees(g.size(),0);
	for(auto adj:g){
		for(int v:adj){
			degrees[v]++;
		}
	}
	return degrees;
}

/* 附：拓扑排序的实现，这里的实现和第一个答案一样，都是不改变邻接表，
	这个答案可以直接作为上一题的答案 */
bool topologicalSort(graph& g){
	int n = g.size();
	vector<int> indegrees = computeIndegrees(g);
	queue<int> q;
	for(int i=0;i<n;i++){  // 先找到一个入度为 0 的顶点，作为开始
		if(indegrees[i]==0)
			q.push(i);
	}

	int count = 0; // 记录当前已经输出的顶点数
	while(!q.empty()){
		int v = q.front();
		q.pop();

		cout<<v<<" "; // 输出顶点
		++ count;
		// 将所有 v 指向的定点的入度减 1，并将入度减为 0 的顶点
		for(int w:g[v]){
			if(!(--indegrees[w]))
				q.push(w); // 只有入度为 0 才会入栈，入度小于0 自动忽略
		}
	}
	if(count<n)
		return false;
	else
		return true;
}

/* 由拓扑排序得到的解法2 */
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    graph g = buildGraphs(numCourses, prerequisites);
    vector<int> indegrees = computeIndegrees(g);
    queue<int> q;
    for(int i=0;i<numCourses;i++){
        if(indegrees[i]==0) q.push(i);
    }
    int count =0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        count++;
        for(int u:g[v]){
            if(!(--indegrees[u])) q.push(u);
        }
    }
    if(count>=numCourses) return true;
    else return false;
}