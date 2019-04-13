/* 一个很常规的题目 */
TreeNode* getInorderSuccessor(TreeNode* pNode)
{
	if(pNode==nullptr)
		return nullptr;
	TreeNode* pNext = nullptr; // 结果初始化

	if(pNode->right!=nullptr)
	{
		pNode = pNode->right;
		while(pNode->left!=nullptr)
			pNode = pNode->left;
		pNext = pNode;
	}
	else{
		// TreeNode* pParent = pNode; // 这里应该是
		TreeNode* pParent = pNode->parent;
		while(pParent!=nullptr && pParent->left!=pNode)
		{
			pNode = pParent;
			pParent = pParent->parent;
		}
		pNext= pParent;
	}
	return pNext;
}






