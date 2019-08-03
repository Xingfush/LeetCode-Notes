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


/* 后序遍历的特点注定了，后序遍历是最适合找结点路径的 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *cur=root,*last=nullptr;
    vector<TreeNode*> pathp,pathq,temp;
     
    while (pathp.empty() || pathq.empty()) {// 全部找到了
        
        // 标准的后序遍历过程
        if (cur) {
            temp.push_back(cur);
            if (temp.back()==p) pathp=temp; // check and set path for p
            if (temp.back()==q) pathq=temp; // check and set path for q
            cur=cur->left;
        } else {
            if (temp.back()->right && temp.back()->right != last) {
                cur=temp.back()->right;
            } else {
                last=temp.back();
                temp.pop_back();
            }
        }
    }
    
    // compare paths and get lowest common ancestor
    int n=min(pathp.size(),pathq.size());
    for (int i=1; i<n; i++) {
        if (pathp[i]!=pathq[i]) return pathp[i-1];
    }
    return pathp[n-1]; // 说明路径是包含关系，则返回最短路径的最后一个
}

/* 在二叉搜索树中寻找最小祖先 
 要求：二叉树中没有重复的元素，一旦有重复元素，方向就无法判别，该方法失效*/


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==nullptr || p==nullptr ||q ==nullptr)
        return nullptr;
    if(p->val>q->val)
        return lowestCommonAncestor(root,q,p);
    
    TreeNode* pNode = root;
    while(pNode!=nullptr)
    {
        if(pNode->val>=p->val && pNode->val<=q->val)
            break;
        else if(pNode->val<p->val)
            pNode = pNode->right;
        else
            pNode = pNode->left;
    }
    return pNode;
}