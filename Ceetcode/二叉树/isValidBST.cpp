/* 两个思路：
	思路1：使用深度搜索
	思路2：使用中序遍历判断，是否为有序序列 */

// 要点1：使用 long 来包括 int 的边界条件
bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
}
bool isValidBST(TreeNode* root, long mn, long mx) {
    if (!root) return true;
    if (root->val <= mn || root->val >= mx) return false;
    return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
}

// 要点2：使用 pLast 来记录上一个结点。
bool isValidBST(TreeNode* root) {
    if(root==nullptr) return true;
    TreeNode* pNode=root,*pLast=nullptr;
    stack<TreeNode*> s;
    while(pNode || !s.empty()){
        if(pNode){
            s.push(pNode);
            pNode = pNode->left;
        }
        else{
            if(pLast && pLast->val>=s.top()->val) return false;
            pNode=s.top()->right;
            pLast = s.top();
            s.pop();
        }
    }
    return true;  
}

/* 使用指针之前一定要进行有效性检查，同理，指针一定要进行初始化，这都是非常重要的编程习惯。
	1. if(pLast && pLast->val) 存在性检查
	2. pLast = nullptr 初始化赋值 */
