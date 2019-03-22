/* 主体是字符串的操作，不要弄错了 */

void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
    // 这一步已经知道root有值不为空，那么path已经把它加了进去
    if(root->left==nullptr && root->right==nullptr) { 
        result.push_back(t);
        return;
    }

    if(root->left!=nullptr) 
        binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right!=nullptr) 
        binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(root==nullptr) 
        return result;
    
    binaryTreePaths(result, root, to_string(root->val));
    return result;
}