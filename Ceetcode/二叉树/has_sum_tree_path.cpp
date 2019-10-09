/* 题目1：判断有没有和为 sum 的路径 */
/* 本质就是个前序遍历 */

bool HasPathSum(TreeNode* root, int sum) {
    if(root==nullptr) 
        return false;
    if(root->val==sum && root->left==nullptr && root->right==nullptr) 
        return true;
    return HasPathSum(root->left,sum-root->val) || HasPathSum(root->right,sum-root->val);
}