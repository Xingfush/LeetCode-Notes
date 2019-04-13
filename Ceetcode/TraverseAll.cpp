void bfs(int s, vector<vector<int>> G)
{
	int n = G.size();
	queue<int> q;
	vector<bool> visited(n,false);
	q.push(s);
	visited[s] = true;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for(int i = 0;i<n;i++){
			if(G[temp][i]!=INF && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}

}

void dfs_iterative(int s, vector<vector<int>> G)
{
	int n = G.size();
	stack<int> st;
	st.push(s);
	while(!st.empty())
	{
		int temp = st.top();
		st.pop();
		cout<<temp<<" "; // 访问
		visited[temp] = true;
		for(int i=0;i<n;i++){
			if(G[temp][i]!=INF && !visited[i]){
				st.push(i);
			}
		}
	}
}

void dfs_recursive(int s, vector<vector<int>> G, vector<bool>& visited)
{
	cout<< s<<" "; // 访问
	visited[s] = true;
	for(int i=0;i<n;i++){
		if(G[s][i] !=INF && !visited[i]){
			dfs(i,G,visited);
		}
	}


void Dijkstra2(int n, int s, vector<vector<int>> G, vector<bool>& visited, vector<int>& d, vector<int>& pre)
{
	fill(d.begin(),d.end(),INF);
	for(int i = 0;i<n;i++)
		pre[i] = i;
	d[s] = 0;
	priority_queue<pair<int,int>> q;
	q.push(make_pair<int,int>(-d[s],s));
	while(!q.empty())
	{
		int temp = q.top().second;
		q.pop();
		visited[temp] = true;
		for(int i =0;i<n;i++){
			if(!visited[temp] && G[temp][i]!=INF && d[temp]+G[temp][i]<d[i]){
				d[i] = d[temp] +G[temp][i];
				q.push(make_pair<int,int>(-d[i],i));
			}
		}
	}
}

void preOrderTraverse(TreeNode* root)
{
	if(root==nullptr) return;
	stack<TreeNode*> st;
	TreeNode* pNode = root;
	while(!st.empty() || pNode)
	{
		if(pNode){
			cout<<pNode->val<<" ";
			st.push(pNode);
			pNode = pNode->left;
		}
		else{
			TreeNode temp = st.top();
			st.pop();
			pNode = temp->right;
		}
	}
}

void inOrderTraverse(TreeNode* root)
{
	if(root==nullptr) return;
	stack<TreeNode*> st;
	TreeNode* pNode = root;
	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push(pNode);
			pNode = pNode->left;
		}
		else{
			TreeNode* temp = st.top();
			st.pop();
			cout<<temp->val<< " ";
			pNode = temp->right;
		}
	}
}

void postOrderTraverse(TreeNode* root)
{
	if(root==nullptr) return;
	stack<TreeNode*> st;
	TreeNode* pNode=root, pLast = nullptr;
	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push(pNode);
			pNode = pNode->left;
		}
		else{
			TreeNode* temp = st.top();
			if(temp->right==nullptr || temp->right==pLast){
				cout<<temp->val<<" ";
				st.pop();
				pLast = temp;
			}
			else{
				pNode = temp->right;
			}
		}
	} 
}

void layerOrderTraverse(TreeNode* root)
{
	if(root==nullptr) return;
	queue<TreeNode*> q;
	TreeNode* pNode = root;
	q.push(root);
	while(!q.empty())
	{
		pNode = q.front();
		q.pop();
		cout<<pNode->val<<" ";
		if(pNode->left) q.push(pNode->left);
		if(pNode->right) q.push(pNode->right);
	}
}

void postOrderTraverse(TreeNode* root)
{
	if(root==nullptr) return;
	stack<TreeNode*> st;
	TreeNode* pNode = root, *pLast = nullptr;
	while(pNode)
	{
		st.push(pNode);
		pNode = pNode->left;
	}
	while(!st.empty())
	{
		pNode = st.top();
		st.pop();
		if(pNode->right==nullptr || pNode->right = pLast){
			cout<<pNode->val<<" ";
			pLast = pNode;
		}
		else{
			st.push(pNode);
			pNode = pNode->right;
			while(pNode){
				st.push(pNode);
				pNode = pNode->left;
			}
		}
	}
}

