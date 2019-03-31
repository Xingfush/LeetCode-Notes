
/* 广度优先遍历 BFS ：使用队列 */

int minDepth(TreeNode* root) {
    if(root==nullptr)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    int l=0;
    while(!q.empty()){
        l++;
        int k = q.size(); // 这两句的写法简直是伟大的发明
        for(int i=0;i<k;i++) // 
        {
            TreeNode *pNode=q.front(); // 每次使用新建的 TreeNode，亲测速度快很多
            if(pNode->left!=nullptr)
                q.push(pNode->left);
            if(pNode->right!=nullptr)
                q.push(pNode->right);
            q.pop();
            
            if(pNode->left==nullptr && pNode->right==nullptr)
                return l;
        }
    }
    return 0;
}

int minDepth(TreeNode* root){
    if(root==nullptr)
        return 0;
    if(root->left==nullptr && root->right==nullptr)
        return 1;
    if(root->left==nullptr)
        return minDepth(root->right)+1;
    if(root->right==nullptr)
        return minDepth(root->left)+1;
    return 1+min(minDepth(root->left)+minDepth(root->right));
}