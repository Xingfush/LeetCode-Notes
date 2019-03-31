
/* 使用栈完成中序遍历 */

void MirroInBFS(TreeNode* root)
{
	if(root==nullptr)
		return;

	stack<TreeNode *> nstack;
	TreeNode *node = root;

	while(node!=nullptr ||!nstack.empty())
	{
		while(node!=nullptr)
		{
			nstack.push(node);
			node=node->left;
		}

		if(!nstack.empty())
		{
			node = nstack.top();

			if(node->left!=nullptr || node->right!=nullptr)
				std::swap(node->left,node->right);

			nstack.pop();
			node=node->left; // 本来是 right，但是发生了交换
		}
	}
}

/* 使用队列完成层序遍历 */
void MirroLayerBFS(TreeNode* root)
{
	if(root==nullptr)
		return;

	queue<TreeNode *> nqueue;
	nqueue.push(root);

	TreeNode *node =root;
	while(!nqueue.empty())
	{
		node = nqueue.front();
		nqueue.pop();

		if(node->left!=nullptr || node->right!=nullptr)
			std::swap(node->left,node->right);

		if(node->left!=nullptr)
			nqueue.push(node->left);

		if(node->right!=nullptr)
			nqueue.push(node->right);
	}
}