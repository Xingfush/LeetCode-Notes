/* 将二叉树按照中序遍历转换为 双向链表：左右子树分别转换为前后指向 */
TreeNode* Convert(TreeNode* root){
	TreeNode* pLastNode = nullptr;
	ConvertCore(root, pLastNode);
	// 步骤、原理和 sortedListToBST 是一样的
	TreeNode* pHead = pLastNode;
	while(pHead!=nullptr && pHead->left!=nullptr)
		pHead = pHead->left;
                       
	return pHead;

}

void ConvertCore(TreeNode* pNode, TreeNode* & pLastNode) // pLastNode 的移动是关键，和SortedListToBST相似
{
	if(pNode==nullptr)
		return; // 直接返回为空

	if(pNode->left!=nullptr) // 转换左子树
		ConvertCore(pNode->left, pLastNode);
	pNode->left = pLastNode; // 左子树和根节点的对接

	if(pLastNode!=nullptr)
		pLastNode->right = pNode; // 左子树和根节点的对接
	pLastNode = pNode; // pLastNode 按中序遍历 每次前进一个点

	if(pNode->right!=nullptr)
		ConvertCore(pNode->right, pLastNode);
}



