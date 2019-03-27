/* 找到两个节点最近的公共祖先
   思路： 先找到两个节点的路径（从根节点），这是核心，方法是 回溯法 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==nullptr||p==nullptr||q==nullptr)
        return nullptr;
    vector<TreeNode*> path1;
    getNodePath(root,p,path1);
    vector<TreeNode*> path2;
    getNodePath(root,q,path2);
    TreeNode* pLast=nullptr;
    auto iter1=path1.begin();
    auto iter2=path2.begin();
    while(iter1!=path1.end() && iter2!=path2.end())
    {
        if(*iter1==*iter2)
            pLast=*iter1;
        iter1++,iter2++;
    }
    return pLast;
}

/* 回溯法的根本就是有进有出 */
bool getNodePath(TreeNode* root, TreeNode* pNode,vector<TreeNode*> &path){
    path.push_back(root); // 把本身的结点加上去
    if(root==pNode)
        return true;
    bool found= false;
    if(root->left!=nullptr)
        found = getNodePath(root->left,pNode,path);
    if(found==false && root->right!=nullptr)
        found = getNodePath(root->right,pNode,path);
    if(found==false)
        path.pop_back();
    return found;
}