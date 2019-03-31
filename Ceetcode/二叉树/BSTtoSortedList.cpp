/* 同样利用中序遍历 */

// 这里的 count相当于SortListTo BST中的 ListNode* & head一样，必须引用
void InOrderBST(TreeNode* pRoot, vector<int> & list)
{
	if(pRoot==nullptr)
		return;
	InOrderBST(pRoot->left,count);
	list.push_back(pRoot->val);
	InOrderBST(pRoot->right,count);
}

int medianInBST(TreeNode *pRoot)
{
	if(pRoot==nullptr)
		return -1;
    vector<int> list;
	InOrderBST(pRoot,list);
    int length = list.size();

	if(length & 1==1) // 判断奇偶的方式
		return list[length/2];
	else
		return (list[(length-1)/2]+list[(length+1)/2]);
}


/* 很重要的例题！！！！！ */

/* 获得第K个结点，很简单，用K和count比较就行了 */

TreeNode* getKthTreeNode(TreeNode* root, int &k) {
    if(root==nullptr)
        return nullptr;
    TreeNode* result = nullptr;
    
    // if(root->left!=nullptr)
    result = getKthTreeNode(root->left,k);
    // 操作之前先检查是否需要操作，条件就是 result是否已经找到
    if(result==nullptr)
    {
        if(k==1) // 如果已经是 Kth 结点，那么就赋值 result
            result = root;
        k--; // 数目减一
    }
    // 操作之前先检查是否需要操作，条件就是 result是否已经找到
    if(result==nullptr)// && root->right!=nullptr) 
        result = getKthTreeNode(root->right,k);

    return result;
}

TreeNode* getKthTreeNode(TreeNode* root, int &k) {
    
    TreeNode* result = nullptr;
    
    if(root->left!=nullptr)
        result = getKthTreeNode(root->left,k);
    // 操作之前先检查是否需要操作，条件就是 result是否已经找到
    if(result==nullptr)
    {
        if(k==1) // 如果已经是 Kth 结点，那么就赋值 result
            return root;
        k--; // 数目减一
    }
    // 操作之前先检查是否需要操作，条件就是 result是否已经找到
    if(result==nullptr && root->right!=nullptr) 
        result = getKthTreeNode(root->right,k);

    return result;
}

