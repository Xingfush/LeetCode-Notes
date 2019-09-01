/* 检验一颗二叉树是否是完全二叉树 */
bool isCompleteTree(TreeNode* root)
{
	vector<TreeNode*> vec;
	vec.push_back(root);
	int i = 0;
	// 这种访问方式遇到第一个nullptr为止
	while(i<vec.size() && vec[i])
	{
		vec.push_back(vec[i]->left);
		vec.push_back(vec[i]->right);
		i++;
	}
	// 判断nullptr后面有没有nullptr的结点	
	while(i<vec.size() && !vec[i])
		i++;
	// 后面只要有nullptr结点，那么肯定i<=vec.size()-1	
	return i==vec.size();
}


