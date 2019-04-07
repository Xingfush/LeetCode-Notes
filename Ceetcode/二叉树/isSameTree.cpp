/* 没什么难度，主要是代码的简介 */
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr || q==nullptr)
        return (p==q);
    return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}