vector<int> ans;
map<TreeNode*, TreeNode*> parent; // son->parent
set<TreeNode*> visited; // 记录访问后的结点

void findParent(TreeNode* pNode){
	if(pNode==nullptr) return;
	if(pNode->left){
		parent[pNode->left] = pNode;
		findParent(pNode->left);
	}
	if(pNode->right){
		parent[pNode->right] = pNode;
		findParent(pNode->right);
	}
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K){
	if(root==nullptr) return {};

	findParent(root);
	dfs(target,K);
	return ans;
}

void dfs(TreeNode* pNode, int K){
	if(visited.count(pNode)) return;
	// 如果 pNode先被访问了，说明 pNode距离那个结点距离更近，按照那个距离算，
	// 这里的 K 代表的是最短距离，而不是能够到达的距离
	visited.insert(pNode);
	if(K==0){
		ans.push_back(pNode->val);
		return;
	}
	if(pNode->left)
		dfs(pNode->left,K-1);
	if(pNode->right)
		dfs(pNode->right,K-1);
	if(parent[pNode])
		dfs(parent[pNode],K-1);
}

/* 所谓终止条件：就是防止越界进入新的 dfs，这里没有在开头设置 if(pNode==nullptr)
    而是在 进入新的 dfs 时候，设置了 if(pNode->left)，其实是效果是一样的 */
