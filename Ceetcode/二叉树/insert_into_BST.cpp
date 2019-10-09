TreeNode* insertIntoBST(TreeNode* root, int val){
	if(!root) return new TreeNode(val);
	TreeNode* cur = root;
	while(true){
		if(cur->val>val){
			if(!cur->left){
				cur->left = new TreeNode(val);
				break;
			}
		} else {
			if(!cur->right){
				cur->right = new TreeNode(val);
				break;
			}
		}
	}

	return root;
}
