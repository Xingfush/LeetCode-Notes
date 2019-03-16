void MirroPreBFS(TreeNode* root)
{
	if(root==nullptr)
		return;

	stack<TreeNode *> nstack;
	nstack.push(root);

	TreeNode *node =root;
	while(!nstack.empty())
	{
		node = nstack.top();
		nstack.pop();

		if(node->left!=nullptr || node->right!=nullptr)
			std::swap(node->left,node->right);

		if(node->left!=nullptr)
			nstack.push(node->left);

		if(node->right!=nullptr)
			nstack.push(node->right);
	}
}