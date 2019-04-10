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

/* 解法2：仿照 sortedListToBST的中序遍历解法，并不比上个解法更好 */
TreeNode* sortedArrayToBST(vector<int> & nums)
{
    if(nums.empty()) return nullptr;
    int count = 0;
    return buildBST(nums,count,nums.size());
}

TreeNode* buildBST(vector<int>& nums, int& ind, int n)
{
    if(n<=0) return nullptr;
    TreeNode* left = buildBST(nums,ind,n/2);
    TreeNode* root = new TreeNode(nums[ind++]);
    root->left = left;
    root->right = buildBST(nums,ind,n-n/2-1);
    return root;
}

