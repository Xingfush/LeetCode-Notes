/* 编程大忌：想好思路之后，在纸上仔细模拟每个过程，确定边界条件 */
TreeNode* buildTree(std::vector<int> &inorder,std::vector<int> &postorder)
{
    return build(inorder,0,inorder.size(),postorder,0,postorder.size());
}

// 首先确认使用 [) 的表示方法，传索引，操作方便，占内存少
TreeNode* build(vector<int> &inorder, int i,int j,vector<int> &postorder,int ii,int jj)
{
    // 确认边界条件，即没有元素
    if(j<=i || jj<=ii)
        return nullptr;
    // 找到后序的最后一个元素，注意是在本区间内操作
    int mid = postorder[jj-1]; // 右边是开的，需要减一
    TreeNode* root = new TreeNode(mid);
    // 找到在中序中的位置，用于划分，注意find的使用，左闭右开迭代器
    auto split = find(inorder.begin()+i,inorder.begin()+j,mid);
    // 使用dist来确认位置
    int dist = split-inorder.begin()-i;

    root->left=build(inorder,i,i+dist,postorder,ii,ii+dist);
    root->right=build(inorder,i+dist+1,j,postorder,ii+dist,jj-1);

    return root;
}

// 使用 dist 确定位置是很简洁的trick。

/* 另一道简单的：使用数组建立最大堆（树） */
TreeNode* constructTree(vector<int>& nums,vector<int>::iterator left,vector<int>::iterator right)
{
    if(left>=right)
        return nullptr;
    auto maxIter = std::max_element(left,right);
    TreeNode* root = new TreeNode(*maxIter);
    root->left = constructTree(nums,left,maxIter);
    root->right = constructTree(nums,maxIter+1,right);
    return root;
}