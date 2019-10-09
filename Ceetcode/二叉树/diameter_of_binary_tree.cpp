/* 后序遍历是关键 */

int DiameterOfBinaryTree(TreeNode* root){
	int res = 0;
	dfs(root, res);
	return res;
}

int dfs(TreeNode* root, int& res){
	if(!root) return 0;
	int left = dfs(root->left, res);
	int right = dfs(root->right, res);
	res = max(left+right, res);
	return max(left,right)+1 ;
}

