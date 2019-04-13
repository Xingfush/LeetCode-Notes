int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    helper(root, res);
    return res;
}
int helper(TreeNode* root, int& res){
    if(root==nullptr) return 0;
    int leftLen = 0, rightLen = 0;
    leftLen = helper(root->left,res);
    rightLen = helper(root->right,res);
    res = max(res,leftLen+rightLen);
    return max(leftLen,rightLen)+1;
}

