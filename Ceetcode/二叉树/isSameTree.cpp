/* 没什么难度，主要是代码的简介 */
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr || q==nullptr)
        return (p==q);
    return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

/* 衍生问题：判断子树 */
bool isSubtree(TreeNode* s, TreeNode* t) {
    if(!s) return false;
    if(isSameTree(s,t)) return true; // 相当于一个前序深度遍历
    return isSubtree(s->left,t) || isSubtree(s->right,t);
}

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p==nullptr && q==nullptr) return true;
    if(p==nullptr || q==nullptr) return false;
    return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}