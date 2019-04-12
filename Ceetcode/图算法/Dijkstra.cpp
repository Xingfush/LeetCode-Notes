#include<iostream>
#include<queue>
using namespace std;

#define MAXN 100
#define INF 0xffffff

void Dijkstra(int n, int s, vector<vector<int>> G, vector<bool>& visited, vector<int>& d, vector<int>& pre)
{

	fill(d.begin(), d.end(), INT_MAX);                         //初始化最短距离矩阵，全部为INT_MAX

	for (int i = 0; i < n; ++i)                            //新添加
		pre[i] = i;

	d[s] = 0;                                              //起点s到达自身的距离为0
	for (int i = 0; i < n; ++i)
	{
		int u = -1;                                     //找到d[u]最小的u
		int MIN = INT_MAX;                                  //记录最小的d[u]
		for (int j = 0; j < n; ++j)                     //开始寻找最小的d[u]
		{
			if (visited[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		//找不到小于INT_MAX的d[u]，说明剩下的顶点和起点s不连通
		if (u == -1)
			return;
		visited[u] = true;                                  //标记u已被访问
		for (int v = 0; v < n; ++v)
		{
			//遍历所有顶点，如果v未被访问&&u能够到达v&&以u为中介点可以使d[v]更优
			if (visited[v] == false && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];             //更新d[v]
				pre[v] = u;                        //记录v的前驱顶点为u（新添加）
			}
		}
	}
}


void Dijkstra2(int n, int s, vector<vector<int>> G, vector<bool>& visited, vector<int>& d, vector<int>& pre)
{
	fill(d.begin(), d.end(), INT_MAX);
	for (int i = 0; i < n; i++)
		pre[i] = i;
	d[s] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(-d[s], s));

	while (!q.empty()) {
		pair<int, int> temp = q.top();
		q.pop();
		int u = temp.second;
		visited[u] = true;
		for (int v = 0; v < n; ++v) {
			if (visited[v] == false && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];
				pre[v] = u;
				q.push(make_pair(-d[v], v));
			}
		}
	}
	
}