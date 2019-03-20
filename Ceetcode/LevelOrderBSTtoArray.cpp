/* 层级遍历：输出[[1],[0,2],[-1,2,1,3]...] */
/* 这里的trick非常好，用来标记每一层最后一个元素 */

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> >  result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    vector<int> cur_vec;
    while(!q.empty()) {
        TreeNode* t = q.front();
        q.pop();
        if (t==NULL) { 
        // 上一层的最后一个结点访问完之后代表本层的最后一个结点已经入队，
        // 可以加入新的 nullptr标志点了。
            result.push_back(cur_vec);
            cur_vec.resize(0);
            if (q.size() > 0) { //队列为空之后不能再加nullptr了，因为q.empty判断
                q.push(NULL);
            }
        } else {
            cur_vec.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
    }
    return result;
}