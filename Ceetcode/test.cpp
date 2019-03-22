int getMedian(TreeNode* root)
{
	if(root==nullptr)
		return -1;
	vector<int> res;
	inOrderTraverse(root, res);
	int length = res.size();
	if(length & 1 =1)
		return res[length/2];
	else
		return (res[(length+1)/2]+res[(length-1)/2])/2;
}

void inOrderTraverse(TreeNode *root, vector<int>& result)
{
	if(root==nullptr)
		return;
	inOrderTraverse(root->left, result);
	result.push_back(root->val);
	inOrderTraverse(root->right, result);
}

TreeNode* getKthNode(TreeNode* root, int & k)
{
	if(root==nullptr)
		return nullptr;
	TreeNode * result =nullptr;
	result = getKthNode(root->left,k);
	if(result==nullptr)
	{
		if(k==1)
			result = root;
		k--;
	}
	if(result==nullptr)
		result=getKthNode(root->right,k);
	return result;
}

TreeNode* build(vector<int> &inorder, int i,int j,vector<int> &postorder,int ii,int jj)
{
	if(i>=j || ii>=jj)
		return nullptr;

	int mid = postorder[jj-1];
	TreeNode* root = new TreeNode(mid);
	auto midIter = std::find(inorder.begin()+i,inorder.begin()+j,mid);
	int dist = midIter-inorder.begin()-i;

	root->left = build(inorder,i,i+dist,postorder,ii,ii+dist);
	root->right = build(inorder,i+dist+1,j,postorder,ii+dist,jj-1);
}

bool hasPathSum(TreeNode* root, int sum)
{
	if(root==nullptr)
		return false;
	if(root->left==nullptr && root->right==nullptr && sum==root->val)
		return true;
	return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right,sum-root->val);

}

void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths)
{
	if(node==nullptr)
		return;
	path.push_back(node->val);
	if(node->left==nullptr && node->right ==nullptr && node->val==sum)
		paths.push_back(path);
	findPaths(node->left,sum-root->val,path,paths);
	findPaths(node->right,sum-root->val,path,paths);
	path.pop_back();
}

void binaryTreePaths(vector<string>& result, TreeNode* root, string t) 
{	// 职务为空之前检查，而且t已加入
	if(root->left==nullptr&&root->right==nullptr){
		result.push_back(t);
		return;
	}
	if(root->left!=nullptr)
		binaryTreePaths(result, root->left, t+"->"+to_string(root->val));
	if(root->right!=nullptr)
		binaryTreePaths(result, root->right, t+"->"+to_string(root->val));
}

int pathSum(TreeNode* root, int sum)
{
	if(root==nullptr)
		return 0;
	return pathSumFromRoot(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
}

int pathSumFromRoot(TreeNode* root, int sum)
{
	if(root==nullptr)
		return 0;
	int res = (root->val==sum?1:0);
	return res+pathSumFromRoot(root->left,sum-root->val)+pathSumFromRoot(root->right,sum-root->val);
}

int MaxToRoot(TreeNode* root, int & re) 
{
	if(root==nullptr)
		return 0;
	int left = max(MaxToRoot(root->left,re),0);
	int right = max(MaxToRoot(root->right,re),0);
	if(left+right+root->val>re)
		re=left+right+root->val;
	return max(left,right)+root->val;
}

int InversePairsCore(int* data, int* copy, int start, int end)
{
	if(start>=end)
	{
		copy[start]=copy[end];
		return 0;
	}

	int mid = start+(end-start)/2;

	int leftPairs = InversePairsCore(copy,data,start,mid);
	int rightPairs = InversePairsCore(copy,data,mid,end);

	int i = start, j= mid;
	int copyIndex = start;

	int count = 0;

	while(i<mid && j<end)
	{
		if(data[i]>data[j])
		{
			count += mid-i;
			copy[copyIndex++] = data[j++];
		}
		else
			copy[copyIndex++] = data[i++];
	}
	while(i<mid)
		copy[copyIndex++] = data[i++];
	while(j<mid)
		copy[copyIndex++] = data[j++];

	return leftPairs+rightPairs+count;
}

int InversePairs(int * data, int *size)
{
	if(data==nullptr || size<=0)
		return -1;

	int* copy = new int[size];
	for(int i=0;i<length;i++)
		copy[i]=data[i];
	int count = InversePairs(data,copy,0,size);
	return count;
}

ListNode* MergeTwoLists(ListNode* a, ListNode* b)
{
	// 首先判断特殊情况
	if(a==nullptr)
		return b;
	if(b==nullptr)
		return a;

	// 核心是调整一个结点的指向
	ListNode* pNode = nullptr;

	if(a->val<b->val)
	{
		result = a;
		result->next = MergeTwoLists(a->next,b);
	}
	else{
		result = b;
		result->next = MergeTwoLists(a,b->next);
	}
	return result;
}

int getMedianOfTwoSortedArray(int *list1, int *list2, int length1, int length2)
{
	int m = length1, n = length2;
	int *A = list1, *B = list2;
	// 保证 m<n
	if(length1 > length2)
	{
		m = length2;
		n = length1;
		A = list2;
		B = list1;
	}
	// 没有左闭右开，只有划分[0,i),[i,end),划分点i取值[0,end]=[imin,imax]
	int imin = 0, imax = m;
	int halflen = (m+n+1)/2;
	int max_of_left = 0, max_of_right =0;

	while(imin<=imax)// 只要还有划分点，注意是两端闭合
	{
		int i = (imin+imax)/2;
		int j = halflen-i; // 按照定义求j
		// 情况1，增大i
		if(i<m && j>0 && B[j-1]>A[i]) // 非临界情况检查: i<m and j>0
			imin = i+1;
		else if(i>0 && j<n && A[i-1]>B[j]) 
			imax = i-1;
		else
		{ // 上面的条件不满足，有6种情况，注意原命题和逆否命题
			if(i==0)
				max_of_left=B[j-1];
			else if(j==0)
				max_of_left=A[i-1];
			else
				max_of_left=max(A[i-1],B[j-1]);

			if((m+n) & 1==1)
				return max_of_left;
			if(i==m)
				min_of_right=B[j];
			if(j==n)
				min_of_right=A[i]
			else
				min_of_right=min(A[i],B[j])

			return (max_of_left+min_of_right)/2.0;
		}
	}

}

