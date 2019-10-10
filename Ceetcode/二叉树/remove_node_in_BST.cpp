/* 这个题目的过程很清晰，一个trick就是当被删除子树存在右子树时，如何调整删除后的结构：
先找到右子树的最小值，也就是最左节点，然后这个最左节点是右子树的最小值，
但是大于所有左子树的值，因此，我们如果让右子树的根节点占据被删除节点的位置，
然后让左子树放在右子树最小值的左子树，就ok了
这种调整方法和我们最容易想到的那种把右子树最左节点放到被删除节点的位置不同，但是更简便。 */

TreeNode* DeleteTreeNode(TreeNode* root, int key){
	if(!root) return nullptr;
	TreeNode *cur = root, *pre = nullptr;

	// 找到要删除的节点，并保存其父节点
	while(cur){
		if(cur->val==key) break;
		pre = cur; //
		if(cur->val>key) cur = cur->left;
		else cur = cur->right;
	}

	// 删除根节点单独处理
	if(!pre) 
		return DeleteTreeNodeHelper(root);
	if(pre->left && pre->left==cur) 
		pre->left = DeleteTreeNodeHelper(root);
	else
		pre->right = DeleteTreeNodeHelper(root);

	return root;
}

TreeNode* DeleteTreeNodeHelper(TreeNode* root){
	if(!root) return nullptr;
	// 没有右子树，则直接返回左子树即可
	if(!root->right) return root->left;
	// 当含有右子树时，需要特殊处理
	TreeNode* temp = root->right;
	while(temp->left)
		temp = temp->left;
	temp->left = root->left;
	return root->right;
}