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

TreeNode* build(int *inorder, int i, int j, int *postorder, int ii, int jj)
{
	if(i>j || ii>jj)
		return nullptr;

	int rootVal = postorder[jj];
	TreeNode* root = new TreeNode(rootVal);
	int split = 0;
	for(int k=i;k<=j;k++)
	{
		if(inorder[k]==rootVal)
			split = k;
	}
	dist = split-i;
	build(inorder,i,i+dist-1,postorder,ii,ii+dist-1);
	build(inorder,i+dist+1,j,postorder,ii+dist,jj-1);
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
	// 保证 list1 是较短的那个数组
	if(length1>length2)
		return getMedianOfTwoSortedArray(list2,list1,length2,length1);

	// 设定较小数组的二分端点
	int imin = 0, imax = length1;
	int halflen = length1+length2+1;
	int max_of_left = 0;
	int min_of_right = 0;

	// 开始二分遍历
	while(imin<=imax)
	{
		int i = imin+(imax-imin)/2;
		int j = halflen - i;
		// 第一种情况
		if(i>0 && list1[i-1]>list2[j])
			imax = i-1;
		else if(i<m && list1[i]<list2[j-1])
			imin = i+1;
		else
		{
			if(i==0)
				max_of_left = list2[j-1];
			else if(j==0)
				max_of_left = list1[i-1];
			else
				max_of_left = max(list1[i-1],list2[j-1]);

			if((length1+length2) & 1==1)
				return max_of_left;

			if(i==m)
				min_of_right = list2[j];
			else if(j==n)
				min_of_right = list1[i];
			else
				min_of_right = min(list1[i],list2[j]);
			return (max_of_left+min_of_right)/2.0;
		}
	}
	return 0;
}

int getTopKofTwoSortedArrays(int * list1, int length1, int* list2, int length2, int k)
{
	// 保证list1 是较短的
	if(length1>length2)
		return getTopKofTwoSortedArrays(list2, length2, list1, length1, k);

	if(length1==0)
		return list2[k-1];
	if(k==1)
		return min(list1[0],list2[0]);

	// 开始划分
	int k1 = min(k/2,length1);
	int k2 = k-k1;
	// 分治法
	if(list1[k1-1]<list2[k2-1])
		return getTopKofTwoSortedArrays(list1+k1,length1-k1, list2, length2, k-k1);
	else if(list1[k1-1]>list2[k2-1])
		return getTopKofTwoSortedArrays(list1,length1, list2+k2, length2-k2, k-k2);
	else
		return list1[k1-1];
}

int partition(int *arr, int left, int right)
{
	int pivot = arr[right];
	int start = left;
	int end = right; // 内部是左闭右开
	while(start<end)
	{
		while(start<end && arr[start]<pivot)
			start--;
		while(start<end && arr[end]>=pivot)
			end--;
		if(start<end)
			swap(arr[start],arr[end]);
	}
	swap(arr[end],arr[right]);
	return end;
}


int GetMiddle(int *arr, int size)
{
	if(arr==nullptr||size==0)
		return -1;

	int start = 0;
	int end = size-1;
	int mid = size/2;
	int div = partition(arr, start, end);

	while(div!=mid)
	{
		if(div<mid)
			div = partition(arr, div+1, end);
		else
			div = partition(arr, start, div-1);
	}
	return div;
}

struct mycompare
{
	bool operator()(int left, int right){
		return left>right;
	}
};

int getMedian(int *arr, int size)
{
	if(arr==nullptr ||size==0)
		return -1;

	priority_queue<int, vector<int>, mycompare> queue;
	int halflen = size/2;
	for(int i =0;i<halflen;i++)
	{
		queue.push(arr[i]);
	}
	for(int i=halflen;i<size;i++)
	{
		if(arr[i]>queue.top())
		{
			queue.pop();
			queue.push(arr[i]);
		}
	}
	if(!queue.empty())
		return queue.top();
}

ListNode* MergeTwoLists(ListNode* a, ListNode* b)
{
	if(a==nullptr)
		return b;
	if(b==nullptr)
		return a;

	ListNode* pNode=nullptr;
	if(a->val<b->val)
	{
		pNode = a;
		pNode->next=MergeTwoLists(a->next,b);
	}
	else
	{
		pNode = b;
		pNode->next =MergeTwoLists(a,b->next);
	}
	return pNode;
}

ListNode* MergeKLists(vector<ListNode*> lists)
{
	int nums = lists.size();
	int last = nums-1;

	while(last!=0)
	{
		int i =0,j=last;
		while(i<j)
		{
			lists[i]=MergeTwoLists(lists[i],list[j]);
			i++;
			j--;
			if(i<=j)
				last=j;
		}
	}
	return lists[0];

}

struct mycompare{
	bool opeartor()(const ListNode* l1, const ListNode* l2){
		return l1->val>l2->val;
	}
}

ListNode* MergeKLists(vector<ListNode*> lists)
{
	if(lists==nullptr||lists.size()==0)
		return nullptr;

	priority_queue<ListNode*,vector<ListNode*>,mycompare> q;
	for (auto l:lists)
	{
		if(l!=nullptr)
			q.push(l);
	}
	if(q.empty())
		return nullptr;
	ListNode* result = q.top();
	ListNode* tail = result;

	while(!q.empty())
	{
		tail->next = q.top();
		q.pop();
		tail=tail->next;
		if(tail->next!=nullptr)
			q.push(tail->next);
	}
	return result;
}


TreeNode* SortedListToBST(ListNode* & head, int n)
{
	if(n==0)
		return nullptr;

	TreeNode* left = SortedListToBST(head->left, n/2);
	TreeNode* root = new TreeNode(head->val);
	root->left = left;
	head = head->next;
	root->right = SortedListToBST(head->right, n-n/2-1);
	return root;
}

int count(ListNode* head){
	return (head)?1+count(head->next):0;
}

TreeNode* SortedListToBST(ListNode* head, ListNode* end)
{
	if(head==end)
		return nullptr;

	ListNode* slow=head,* fast=head;
	while(fast!=end && fast->next!=end)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	TreeNode* root=new TreeNode(slow->val);
	root->left = SortedListToBST(head,slow);
	root->right = SortedListToBST(slow->next,end);
	return root;
}




