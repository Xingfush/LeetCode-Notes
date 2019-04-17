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
