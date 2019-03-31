TreeNode* Convert(TreeNode* root)
{
	if(root==nullptr)
		return nullptr;
	TreeNode* LastNode = nullptr;
	ConvertCore(root, LastNode);

	if(LastNode->left!=nullptr)
		LastNode=LastNode->left;
	return LastNode;
}

void ConvertCore(TreeNode* root, TreeNode*& LastNode) // 因为仅仅改变树的结构，而不产生新的结点，所以就地操作
{
	if(root==nullptr)
		return;

	if(root->left!=nullptr)
		ConvertCore(root->left, LastNode);
	root->left=LastNode;
	if(LastNode!=nullptr)
		LastNode->right=root;
	LastNode = root;
	if(LastNode->right!=nullptr)
		ConvertCore(root->right, LastNode);
}

int medianInBST(TreeNode *pRoot)
{
	if(pRoot==nullptr)
		return 0;
	vector<int> result;
	InOrderTraverse(root, result);
	length = result.size()
	if(length & 1==1)
		return result[length/2];
	else
		return (result[(length-1)/2]+result[(length+1)/2])/2.0;
}

void InOrderTraverse(TreeNode *root, vector<int> & array)
{
	if(root==nullptr)
		return;
	InOrderTraverse(root->left,array);
	array.push_back(root->val);
	InOrderTraverse(root->right,array);
}

TreeNode* InOrderTraverse(TreeNode* root, int & k)
{
	TreeNode* result==nullptr;

	if(root->left!=nullptr)
		result=InOrderTraverse(root->left, k);
	if(result==nullptr)
	{
		if(k==1)
			result=root;
		k--;
	}
	if(result==nullptr && root->right!=nullptr)
		result = InOrderTraverse(root->left, k);
}

TreeNode* build(int* inorder, int i,int j, int* postorder, int ii, int jj)// 左闭右闭
{
	if(i>j || ii>jj)
		return nullptr;
	int rootVal = postorder[jj];
	int rootIndex = i;
	for(int k=i;k<=j;k++)
	{
		if(inoder[k]==rootVal)
			rootIndex = k;
	}
	int dist = rootIndex-i; // 左子树的元素个数

	TreeNode* root = new TreeNode(rootVal);
	root->left = build(inorder, i, i+dist-1, postorder, ii, ii+dist-1);
	root->right = build(inorder, i+dist+1, j, postorder, ii+dist, jj-1);
	return root;
}

TreeNode* constructFromPrePost(vector<int> pre, vector<int> post) 
{
	vector<TreeNode*> path;
	path.push_back(new TreeNode(pre[0]));
	for(int i=1,j=0;i<pre.size();i++) // 按照前序数列遍历
	{
		while(path.back()->val==post[j])
		{
			j++;
			path.pop_back();
		}
		TreeNode *pNode = new TreeNode(pre[i]);
		if(path.back()->left==nullptr)
			path.back()->left = pNode;
		else
			path.back()->right = pNode;
		path.push_back(pNode);
	}
	return path[0]; // 以最后一个结点的路径结束，返回第一个结点
}

void binaryTreePaths(vector<string>& result, TreeNode* root, string t)
{
	if(root->left==nullptr && root->right==nullptr)
	{
		result.push_back(t);
		return;
	}
	if(root->left!=nullptr)
		binaryTreePaths(result, root->left, t+"->"+to_string(root->left->val));
	if(root->right!=nullptr)
		binaryTreePaths(result, root->right, t+"->"+to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root)
{
	vector<string> result;
	if(root==nullptr)
		return result;

	binaryTreePaths(result, root, to_string(root->val));
	return result;
}

void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths)
{
	if(node==nullptr)
		return;
	path.push_back(node->val);
	if(node->left==nullptr && node->right==nullptr && node->val==sum)
	{
		paths.push_back(path);
		return;
	}
	path.push_back(node->val);
	findPaths(node->left, sum-node->val, path, paths);
	findPaths(node->right, sum-node->val, path, paths);
	path.pop_back(node->val)
}

vector<vector<int> > findPathToSum(TreeNode* root, int sum)
{
	vector<int> path;
	vector<vector<int> > result;
	findPaths(root, sum, path, result);
	return result;
}

void findMaxPaths(TreeNode* node, int & curSum, int & maxSum)
{
	if(node==nullptr)
		return;
	curSum += node->val;
	if(node->left==nullptr && node->right==nullptr && curSum>maxSum)
	{
		maxSum = curSum;
		return;
	}
	findMaxPaths(node->left, curSum, maxSum);
	findMaxPaths(node->right, curSum, maxSum);
	curSum -= node->val;
}

int pathSum(TreeNode* root, int sum)
{
	if(root==nullptr)
		return 0;
	return pathSumFromRoot(root, sum)+pathSumFromRoot(root->left, sum)+pathSumFromRoot(root->right, sum);
}

int pathSumFromRoot(TreeNode* root, int sum)
{
	if(root==nullptr)
		return 0;
	int res=(sum==root->val?1:0);
	return res+pathSumFromRoot(root->left, sum-node->val)+pathSumFromRoot(root->right, sum-node->val);
}

TreeNode* getInorderSuccessor(TreeNode* pNode)
{
	if(pNode==nullptr)
		return nullptr;
	TreeNode* result =nullptr;

	if(pNode->right!=nullptr)
	{
		while(pNode->left!=nullptr)
			pNode=pNode->left;
		result = pNode;
	}
	else
	{
		TreeNode* pParent = pNode;
		while(pParent!=nullptr && pParent->right==pNode)
		{
			pNode=pParent;
			pParent=pParent->parent;// pParent会调节为nullptr
		}
		result = pParent;
	}
	return ;
}

bool isSymmetric(TreeNode* root)
{
	if(root==nullptr)
		return true;

	queue<TreeNode*> qleft, qright;
	qleft.push(root->left);
	qright.push(root->right);
	while(!qleft.empty() && !q.right.empty())
	{
		TreeNode* l = qleft.front();
		qleft.pop();
		TreeNode* r = qright.front();
		qright.pop();
		if(l==nullptr && r==nullptr)
			continue;
		if(l==nullptr || r==nullptr)
			return false;
		if(l->val!=r->val)
			return true;
		qleft.push_back(l->left);
		qleft.push_back(l->right);
		qright.push_back(r->right);
		qright.push_back(r->left);
	}
	return true;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if(root==nullptr || p==nullptr || q==nullptr)
		return nullptr
	
	vector<TreeNode *> pathp, pathq, temp;
	TreeNode* pNode, pLast;
	pNode = root;
	while(pathp.empty() || pathq.empty())
	{
		if(pNode!=nullptr)
		{
			temp.push_back(pNode);
			pNode = pNode->left;
		}
		else
		{
			if(temp.back()->right==nullptr || temp.back()->right == pLast)
			{
				if(temp.back()==p) pathp=temp;
				if(temp.back()==q) pathq=temp;
				pLast = temp.back();
				temp.pop_back();
			}
			else
			{
				pNode=temp.back()->right;
			}
		}
	}
	int imin = min(pathp.size(),pathq.size());
	for(int i=0;i<imin;i++)
	{
		if(pathp[i]==pathq[i])
			pNode = pathq[i];
	}
	return pNode;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
	if(matrix.size()==0||matrix[0].size()==0)
		return false;
	int m=matrix.size(), n = matrix[0].size();
	int i=0,j=n-1;
	while(i<m && j>=0)
	{
		if(matrix[i][j]==target)
			return true;
		if(matrix[i][j]>target)
		{
			int start = 0, end =j;// 找到第一个小于等于target的元素
			while(start<end)
			{
				int mid = start+(end-start)/2;
				if(matrix[i][mid]<=target)
					left = mid+1;
				else
					right = mid;
			}
			j = end-1;
		}
		else
			i++;
	}
	return false;
}

bool 


