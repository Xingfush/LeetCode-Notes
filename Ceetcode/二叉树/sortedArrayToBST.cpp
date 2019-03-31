// 操作STL数据类型的时候最好使用迭代器

/* 解法：使用迭代器，不要在递归里复制子数组 */
using iter=vector<int>::const_iterator;
TreeNode* sortedArrayToBST(vector<int> & nums)
{
	if(nums.empty())
		return nullptr;
	return buildBST(nums.begin(),nums.end());
}

TreeNode* buildBST(iter b,iter e)
{
	if(b>=e) // 左开又闭的边界条件
		return nullptr;

	//寻找中点
	iter m = b+(e-b)/2; // 防溢出的标准写法

	TreeNode* node =new TreeNode(*m);
	node->left = buildBST(b,m);
	node->right = buildBST(m+1,e);

	return node;
}



