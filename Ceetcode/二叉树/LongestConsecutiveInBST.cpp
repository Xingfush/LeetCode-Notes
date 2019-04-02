/* 找出二叉树所有路径中最长的连续子序列，路径必须是从父节点到子节点，不能反过来 */
/* 使用前序遍历的方法，如果先处理当前节点，更新值后再处理子树，这个过程要求 必须是前序遍历 */

// 需要记录上一个父节点的值，判断当前值是否和父节点是连续的，同时保持当前长度out 和最好长度res
int LongestConsecutiveTreeNode(TreeNode* root)
{
	if(root==nullptr)
		return 0;
	int res = 0;
	preOrderTraverse(root, 0, 0, res); // 初始根节点 root->val !=0+1，自然地 out就会重置为1
	return res;
}

void preOrderTraverse(TreeNode* root, int v, int out, int & res)
{
	if(root==nullptr)
		return;
	if(root->val == v+1)
		out++;
	else
		out=1; // 不连续则重置为1
	res = max(res, out) // 更新最好结果
	preOrderTraverse(root->left, root->val, out, res);
	preOrderTraverse(root->right, root-val, out, res);
}

