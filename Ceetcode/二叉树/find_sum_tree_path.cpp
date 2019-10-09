/* ------------------------------------------------------------------ */
/* 找出所有和为 sum 的路径，标准路径 */
/* 典型的回溯法 */

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int> > paths;
    vector<int> path;
    findPaths(root, sum, path, paths);
    return paths;  
}

void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
    if (!node) return; // 一个终止条件就够了
    path.push_back(node -> val);
    if (!(node -> left) && !(node -> right) && sum == node -> val)
        paths.push_back(path); // 后面不能加 return，因为 path.pop_back()
    findPaths(node -> left, sum - node -> val, path, paths);
    findPaths(node -> right, sum - node -> val, path, paths);
    path.pop_back(); // 退出前一定要弹出该节点的元素
}

/* 做个简单的变形，求最大的路径的 sum */
void findMaxPaths(TreeNode* node, int & curSum, int & maxSum){
	if(!node) return;
	curSum += node->val;
	if(!(node->left) && !(node->right) && curSum>maxSum)
		maxSum = curSum;
	findPaths(node->left, curSum, maxSum);
	findPaths(node->right, curSum, maxSum);
	curSum -= node->val;
}

/* ------------------------------------------------------------------ */
/* 双重递归，这个很牛逼，极具启发性 */
// 找出所有结点和为sum的路径，这个路径不需要是根结点开始，叶子结点结束
int pathSum(TreeNode* root, int sum){
	if(root==nullptr)
		return 0;
	return pathSumFromRoot(root,sum)+pathSum(root->left,sum)
		+pathSum(root->right,sum);

}

int pathSumFromRoot(TreeNode* root, int sum){
	if(root==nullptr) //这个地方判断不能少
		return 0;
	int res = (root->val==sum?1:0); // 这个形式非常简洁，
	// 注意这个不是终止条件，因为后面还可能出现新的答案
	return res + pathSumFromRoot(root->left,sum-root->val)
		+ pathSumFromRoot(root->right,sum-root->val);
}

// pathSumFromRoot 是主体，注意这里pathSum的循环

/* ------------------------------------------------------------------ */
// 找出和最大的路径，完全任意路径，从结点到结点
int MaxToRoot(TreeNode* root, int & re){
    if(root==nullptr)
        return 0;
    int left=max(MaxToRoot(root->left,re),0);
    int right=max(MaxToRoot(root->right,re),0);
    if(left+right+root->val>re)
        re=left+right+root->val;
    return root->val+max(left,right);
}
 
int maxPathSum(TreeNode* root) {
    int result=numeric_limits<int>::min();
    MaxToRoot(root,result);
    return result;
}
// 这里使用的是后序遍历，从左右子节点向上，re 必定是不断增加的，起码不会减小
// 所以可以放心大胆地使用 引用传递 re
// 这是最关键的地方
