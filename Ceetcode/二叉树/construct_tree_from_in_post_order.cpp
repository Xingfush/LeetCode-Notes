/* 编程大忌：想好思路之后，在纸上仔细模拟每个过程，确定边界条件 */

typedef vector<int>::const_iterator iter;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return dfs(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}

TreeNode* dfs(iter i, iter j, iter ii, iter jj){
    if(i>=j || ii>=jj)
        return nullptr;
    int mid = *(jj-1);
    TreeNode* root = new TreeNode(mid);
    auto dist = find(i,j,mid) - i;

    root->left = dfs(i, i+dist, ii, ii+dist);
    root->right = dfs(i+dist+1, j, ii+dist, jj-1);
    return root;
}

// 使用 dist 确定位置是很简洁的trick。

/* 另一道简单的：使用数组建立最大堆（树） */
TreeNode* buildTree(iter begin, iter end){
    if(begin>=end)
        return nullptr;
    auto maxIter = max_element(begin, end);
    TreeNode* root = new TreeNode(*maxIter);
    root->left = buildTree(begin, maxIter);
    root->right = buildTree(maxIter+1, end);
    return root;
}
