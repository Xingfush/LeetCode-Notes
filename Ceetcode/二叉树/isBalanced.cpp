bool result = true;

bool isBalanced(TreeNode* root){
    if(root==nullptr) return true;
    dfs(root);
    return result;
}

int dfs(TreeNode* root){
    if(root==nullptr) return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    if(abs(left-right)>1)
        result = false;
    return max(left,right)+1; // 后序遍历
}