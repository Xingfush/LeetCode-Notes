/* 非递归版本，队列的经典用法，绝妙 */

bool isSymmetric(TreeNode* root)
{
	if(root=nullptr)
		return true;

	queue<TreeNode*> qLeft,qRight;
	qLeft.push(root->left);
	qRight.push(root->right);

	while(!qLeft.empty() && !qRight.empty())
	{
		left=qLeft.front();
		qLeft.pop();
		right=qRight.front();
		qRight.pop();

		if(left==nullptr && right==nullptr)
			continue; // 队列的元素两两出，兄弟节点依次判别
		if(left==nullptr || right==nullptr)
			return false;
		if(left->val!=right->val)
			return false;

		// 这个比较的顺序至关重要，左左VS右右，队列优势
		qLeft.push(left->left);
		qLeft.push(left->right);
		qRight.push(right->right);
		qRight.push(right->left);

	}
	return true;

}

/* 仔细体会这里队列的应用，逐层处理，先进先出 */

/* 递归版本更有意思，见识下什么是广义的前序遍历 */

bool isSymmetric(TreeNode* root)
{
	if(root==nullptr)
		return true;
	return isSymmetric(root->left, root->right);
}

bool isSymmetric(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if(pRoot1==nullptr && pRoot2==nullptr)
		return true;
	if(pRoot1==nullptr || pRoot2==nullptr)
		return false;

	if(pRoot1->val!=pRoot2->val)
		return false;

	return isSymmetric(pRoot1->left,pRoot2->right)&&
				isSymmetric(pRoot1->right,pRoot2->left);
}

