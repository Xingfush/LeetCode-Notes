/* 后序遍历的特点注定了，后序遍历是最适合找结点路径的 */

TreeNode* LowestCommonAncestor(TreeNode* root, 
                               TreeNode* p, 
                               TreeNode* q){
    TreeNode *cur = root, *last = nullptr;
    vector<TreeNode*> path_p, path_q, path;

    // 标准的后序遍历过程
    while(path_p.empty() || path_q.empty()){
        if(cur){
            path.push_back(cur);
            if(cur==p) path_p = path;
            if(cur==q) path_q = path;
            cur = cur->left;
        } else {
            if(!path.back()->right || path.back()->right==last){
                last = temp.back();
                temp.pop_back();
            } else {
                cur = temp.back()->right;
            }
        }
    }

    int n = min(path_p.size(),path_q.size());
    for(int i=1;i<n;i++){
        if(path_p[i]!=path_q[i]) return path_p[i-1];
    }

    return path_p[n-1];  // 说明路径是包含关系，则返回最短路径的最后一个
}


/* 在二叉搜索树中寻找最小祖先 
 要求：二叉树中没有重复的元素，一旦有重复元素，方向就无法判别，该方法失效*/

TreeNode* LowestCommonAncestor(TreeNode* root, 
                               TreeNode* p, 
                               TreeNode* q) {
    if(root==nullptr || p==nullptr ||q ==nullptr)
        return nullptr;
    if(p->val>q->val) // 保证左右关系
        return LowestCommonAncestor(root,q,p);
    
    TreeNode* pNode = root;
    while(pNode!=nullptr){
        if(pNode->val>=p->val && pNode->val<=q->val)
            break;
        else if(pNode->val<p->val)
            pNode = pNode->right;
        else
            pNode = pNode->left;
    }
    
    return pNode;
}