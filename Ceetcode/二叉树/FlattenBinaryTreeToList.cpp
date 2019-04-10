/* 这题看似是前序遍历，实际上应该按照后序遍历的顺序处理，先处理子树，然后在处理根节点，右子树赋值左子树，左子树为空
	细节：左子树最右结点的右节点为右子树的第一个结点，这里的最右结点的求法
	while(root->right) root = root->right; */

/* 解法1：左右顺序变换后的后序遍历，先访问右节点，再访问左节点，结点的下一个结点就是上次访问的结点，很巧妙 */
TreeNode* pre=nullptr;

void flatten(TreeNode* root) {
    if(root==nullptr) return;
    flatten(root->right);
    flatten(root->left);
    root->right=pre;
    root->left=nullptr;
    pre=root;
}

/* 常规解法1：后序遍历处理 */
void flatten(TreeNode* root) {
    if(root==nullptr) return;
    flatten(root->left);
    flatten(root->right);
    TreeNode* temp = root->right;
    root->right = root->left;
    root->left=nullptr;
    while(root->right)
        root=root->right;
    root->right=temp;
}