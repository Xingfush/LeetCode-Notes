/* 同样利用中序遍历 */

int List[100]; //将数组定义为全局变量

// 这里的 count相当于SortListTo BST中的 ListNode* & head一样，必须引用
void InOrderBST(TreeNode* pRoot, int & count)
{
	if(pRoot==nullptr)
		return;
	InOrderBST(pRoot->left,count);
	List[count] = pRoot->val;
	count++;
	InOrderBST(pRoot->right,count);
}

int medianInBST(TreeNode *pRoot)
{
	if(pRoot==nullptr)
		return -1;
	int count=0;
	InOrderBST(pRoot,count);

	if(count & 1==1) // 判断奇偶的方式
		return List[count/2];
	else
		return (List[(count-1)/2]+List[(count+1)/2]);
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


