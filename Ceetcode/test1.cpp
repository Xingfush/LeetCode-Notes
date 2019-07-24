/* 二分查找：左开右闭，找到第一个大于等于 key 的元素 */

int BinarySearch(int* array, int left, int right, int key)
{
	while(left<right)
	{
		int mid = left + (right-left)/2;
		if(array[mid]<key)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

/* 无序数组的中位数：重点是 partition 函数 */

int partition(int* array, int start, int end)
{
	int left = start, right = end; // 左闭右闭
	int pivot = array[end];
	while(left<right)
	{
		while(left<right && array[left]<=pivot)
			left++;
		while(left<right && array[right]>pivot)
			right--;
		if(left<right)
			swap(array[left], array[right]);
	}
	swap(array[left],array[end]);
	return left; // 总是 left 撞向 right，因此最后肯定有 array[left]>=array[end]
}

int findMedian(int* array, int length)
{
	int k = (length-1)/2;
	int left = 0, right = length-1;
	int result = 0;
	while(true)
	{
		int q = partition(array, left, right);
		if(q==k){
			result = nums[q];
			break;
		}
		else if(q<k)
			left = q +1;
		else
			right = q-1;
	}
	return result;
}

double findMedianOfSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	// 首先判断 长短，保证 nums1 小于 nums2
	if(nums1.size() > nums2.size())
		return findMedianOfSortedArrays(nums2, nums1);

	int m = nums1.size(), n = nums2.size();
	int imin = 0, imax = m;
	int halfLen = (m+n+1)/2;
	int max_of_left = 0, min_of_right = 0;

	while(imin<=imax) // 只要还有划分点
	{
		int i = (imin +imax)/2;
		int j = halfLen - i;
		// 以下三种情况
		if(i>0 && nums1[i-1]>nums2[j])
			imax = i-1;
		else if(i<m && nums1[i]<nums2[j-1])
			imin = i+1;
		else{
			if(i==0)
				max_of_left = nums2[j-1];
			else if(j==0)
				max_of_left = nums1[i-1];
			else
				max_of_left = min(nums1[i-1],nums2[j-1]);

			if((m+n)%2 ==1)
				return max_of_left;

			if(i==m)
				min_of_right = nums2[j];
			else if(j==n)
				min_of_right = nums1[i];
			else
				min_of_right = min(nums1[i], nums2[j]);

			return (max_of_left + min_of_right)/2;
		}
	}
	return 0;
}

/* 找到两个有序数组中的第 k 个元素 */

typedef vector<int>::iterator iterator;

double findKthOfSortedArrays(iterator arr1, int len1, iterator arr2, int len2, int k)
{
	if(len1>len2)
		return findKthOfSortedArrays(arr2, len2, arr1, len1, k);
	if(len1==0)
		return arr2[k-1];
	if(k==1)
		return min(arr1[0],arr2[0]);

	int k1 = min(k/2, len1);
	int k2 = k-k1;

	if(arr1[len1-1]<arr2[len2-1])
		return findKthOfSortedArrays(arr1+k1, len1-k1, arr2, len2, k-k1);
	else if(arr1[len1-1]>arr2[len2-1])
		return findKthOfSortedArrays(arr1, len1, arr2+k2, len2-k2, k-k2);
	else
		return arr1[k1-1];
}

double findKthOfSortedArrays(vector<int>& nums1, vector<int>& nums2, int k)
{
	if(k<0 || nums1.size() + nums2.size()<k)
		throw "Parameter error: k must be valid.";

	iterator iter1 = nums1.begin(), iter2 = nums2.begin();
	int len1 = nums1.size(), len2 = nums2.size();
	return findKthOfSortedArrays(iter1, len1, iter2, len2, k);
}

// 事实证明迭代器可以使用中括号
int main()
{
	int arr[10] = {1, 2, 3, 4, 4, 5, 6, 6, 7, 8};
	int* arr1 = arr + 2;
	cout << "第4个元素为：" << arr1[1];

	vector<int> nums(arr,arr+10);
	auto iter = nums.begin() + 2;
	cout << "第4个元素为：" << iter[2];
	cout << endl;
	return 0;

}

int MinimalOfRotatedArray(int* array, int length)
{
	if(length==1)
		return array[0];
	int left = 0, right = length-1;
	int mid = 0; // 为了防止没有发生旋转的情况
	while(array[left]>=array[right])
	{
		if(right-left==1)
		{
			mid = left;
			break;
		}
		int mid = left +(right-left)/2;
		if(array[mid]==array[left] && array[left]==array[right])
			return MinimalInOrder(int* array, int left, int right);
		else if(array[mid]<=array[right])
			right = mid;
		else
			left = mid;
	}
	return array[mid];
}

int SearchRotatedArray(int* array, int length, int target)
{
	int left = 0, right = length -1;
	int mid = 0;

	while(left<=right) // 一直找到没有
	{
		int mid = left + (right-left)/2;
		if(arr[mid]==target)
			return true;
		if(arr[mid]<arr[right])
		{
			if(arr[mid]<target && arr[right]>=target)
				left = mid +1;
			else 
				right = mid -1;
		}
		else if(arr[mid]>arr[right])
		{
			if(arr[mid]>target && arr[left]>=target)
				right = mid-1;
			else
				left = mid +1;
		}
		else
			right--;
	}
	return false;
}

/* 二分查找：依图面试被拒，North remember! */
bool SearchSortedMatrix(vector<vector<int>>& matrix, int target)
{
	if(matrix.size()==0 || matrix[0].size()==0)
		return false;

	int m = matrix.size(), n = matrix[0].size();
	int i = 0, j = n-1;
	while(i<m && j>0)
	{
		if(matrix[i][j]==target)
			return true;
		else if(target>matrix[i][j])
			i++;
		else{
			int start = 0, end = j;
			while(start<end){
				int mid = start+(end-start)/2;
				if(matrix[i][mid]<=target)
					left = mid+1;
				else
					right = mid;
			}
			j = end-1;
		}
	}
	return false;
}

/* end = m*n, end/m, end%m 基本功 */
bool SearchMatrix(vector<vector<int>>& matrix, int target)
{
	if(matrix.size()==0 || matrix[0].size()==0)
		return false;

	int m = matrix.size(), n = matrix[0].size();
	int start = 0, end = m*n;
	while(start<end)
	{
		int mid = start + (end-start)/2;
		int value = matrix[mid/m][mid%m];
		if(value==target)
			return true;
		else if(value<target)
			left = mid + 1;
		else 
			right = mid;
	}
	return false;
}
// 二分查找中只要使用了 left,right 左开右闭，那么就符合 left = mid+1, right = mid
// 的搜索范式，至于具体是什么问题可以内部变动，但是搜索的范式不变

/* upper_bound 表示找到第一个大于 key 的元素，则 之前的元素都是小于等于 key 的
   lower_bound 表示找到第一个大于等于 key 的元素，则 之前的元素都是小于 key 的 */

int SearchKthSmallest(vector<vector<int>>& matrix, int k)
{
	int n = matrix.size();
	int left = matrix[0][0], right = matrix[n-1][n-1];
	while(left<right)
	{
		mid = left + (right-left)/2;
		int num = 0;
		for(int i=0;i<n;i++){
			int pos = upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix.begin();
			num += pos; // upper_bound
		}
		if(num<k)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

vector<vector<int>> ThreeSum(vector<int>& nums)
{
	vector<vector<int>> res;

	// 这里必须先进行排序
	sort(nums.begin(),nums.end()); // 排序用于去重，和两端相近法

	for(int i=0;i<nums.size()-2;i++) // 这里设定 i<nums.size()-2
	{
		int target = -nums[i];
		int left = i+1, right = nums.size()-1;
		while(left<right) // 这里设定 left<right只剩下一个元素
		{
			int sum = nums[left] + nums[right];
			if(sum<target)
				left ++;
			else if(sum>target)
				right --;
			else{
				vector<int> triplet(3,0);
				triplet[0] = nums[left];
				triplet[1] = nums[right];
				triplet[2] = nums[i];
				res.push_back(triplet);

				while(left<right && nums[left]==triplet[0])
					left++;
				while(left<right && nums[right]==triplet[1])
					right--;
			}
		}
		while(i+1<nums.size() && nums[i+1]==num[i])
			i++;
	}
	return res;
}

vector<int> TwoSum(vector<int>& nums, int target)
{
	unordered_map<int,int> map;

	for(int i=0;i<nums.size();i++)
	{
		int residual = target-nums[i];
		if(map.find(residual)!=map.end()){
			return {map[residual],i};
		}
		map[nums[i]] = i;
	}
	return {};	
}

/* 二叉树的三种遍历 */
void PreOrderTraverse(TreeNode* root)
{
	if(root==nullptr)
		return;
	TreeNode* pNode = root;
	stack<TreeNode*> st;
	while(!st.empty() || pNode)
	{
		if(pNode){
			cout<<pNode->val;
			st.push(pNode);
			pNode = pNode->left;
		}
		else{
			pNode = st.top();
			st.pop();
			pNode = pNode->right;
		}
	}
}

void InOrderTraverse(TreeNode* root)
{
	if(root==nullptr)
		return;
	TreeNode* pNode = root;
	stack<TreeNode*> st;
	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push(pNode);
			pNode = pNode->left;
		}
		else{
			pNode = st.top();
			st.pop();
			cout<<pNode->val;
			pNode = pNode->right;
		}
	}
}

void PostOrderTraverse(TreeNode* root)
{
	if(root==nullptr)
		return;
	TreeNode* pNode = root, * pLast = nullptr;
	stack<TreeNode*> st;
	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push(pNode);
			pNode = pNode->left;
		}
		else{
			TreeNode* temp = st.top();
			if(temp->right==nullptr || temp->right==pLast){
				cout<<temp->val;
				pLast = temp;
				st.pop();
			}
			else
			{
				pNode = pNode->right;				
			}
		}
	}
}

/* 将二叉树转换为双向链表 */
TreeNode* Convert(TreeNode* root)
{
	TreeNode* pLastNode = nullptr;
	ConvertCore(root, pLastNode);
	TreeNode* pHead = pLast;
	while(pHead!=nullptr && pHead->left!=nullptr)
		pHead = pHead->left;

	return pHead;
}

void ConvertCore(TreeNode* pNode, TreeNode* & pLast)
{
	if(pNode==nullptr) // 如果已访问所有的结点，则返回
		return;
	if(pNode->left!=nullptr)
		ConvertCore(pNode->left, pLast);
	pNode->left = pLast;
	if(pLast!=nullptr)
		pLast->right = pNode;
	pLast = pNode;
	if(pNode->right!=nullptr)
		ConvertCore(pNode->right, pLast);
}

// 使用全局变量
int k;

TreeNode* getKthTreeNode(TreeNode* root, int k)
{
	if(root==nullptr)
		return nullptr;
	TreeNode* result = nullptr;

	result = getKthTreeNode(root->left, k);
	// 中序遍历，操作之前先检查 result 是否已经找到
	if(result == nullptr){
		if(k==1)
			result = root;
		k--;
	}
	if(result == nullptr)
		result = getKthTreeNode(root->right, k);

	return result;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}

// 首先确认 [) 的表示方法，传索引，表示方便
TreeNode* build(vector<int> &inorder, int i, int j, vector<int> &postorder, int ii, int jj)
{
	if(j<=i || jj<=ii) // 确认边界，没有元素
		return nullptr;
	// 找到后序的第一个元素，用于通过中序数组进行划分
	int mid = postorder[jj-1]; // 右边是开的，注意
	TreeNode* root = new TreeNode(mid);
	auto split = find(inorder.begin() + i,inorder.end() + j, mid);
	int dist = split - inorder.begin() -i; // 是距离，不是中间个数
	root->left = build(inorder, i, i+dist, postorder, ii, ii+dist);
	root->right = build(inorder, i+dist+1, j, postorder, ii+dist, jj-1);

	return root;
}

// 要点：使用了左闭右开，从而 [i,i+dist) [i+dist+1,j), [ii,ii+dist) [ii+dist, jj-1)
// 使用迭代器 表示位置

/* 使用任意数组建立最大堆，不停地找最大值即可 */

TreeNode* buildHeap(vector<int>& nums, vector<int>::iterator left, vector<int::iterator> right)
{
	if(left>=right)
		return nullptr;
	auto maxIter = max_element(left, right);
	TreeNode* root = new TreeNode(*maxIter);
	root->left = buildHeap(nums, left, maxIter);
	root->right = buildHeap(nums, maxIter+1, right);
	return root;
}

/* longest path of two nodes in a tree */
int LongestPathOfNodes(TreeNode* root)
{
	int res  =0;
	helper(root, res);
	return res;
}

int helper(TreeNode* root, int& res)
{
	if(root==nullptr)
		return 0;
	int leftLen = 0, rightLen = 0;
	int leftLen = helper(root->left, res);
	int rightLen = helper(root->right, res);
	res = max(res, leftLen+rightLen+1);
	return max(leftLen, rightLen) + 1;
}

/* 毫无疑问，这里需要后序遍历，res 作用是保存当前最长的路径，因为不需要经过 根节点，
   另外 返回当前最长的分支，双线操作，略复杂 */

void BinaryTreePaths(vector<string>& result, TreeNode* root, string t)
{
	// 先判定是否为根节点，是则返回
	if(root->left==nullptr || root->right==nullptr){
		result.push_back(t);
		return;
	}
	if(result->left) // 事先对传入的节点进行判空
		BinaryTreePaths(result, root->left, t+"->"+to_string(root->left->val));
	if(result->right)
		BinaryTreePaths(result, root->right, t+"->"+to_string(root->right->val));
}

vector<string> BinaryTreePaths(TreeNode* root)
{
	vector<string> result;
	if(root==nullptr)
		return result;
	BinaryTreePaths(result,roo, to_string(root->val));
	return result;
}

bool hasPathSum(TreeNode* root, int sum)
{
	if(root==nullptr)
		return false;
	if(root->val == sum && root->left == nullptr && root->right ==nullptr)
		return true;
	return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

vector<vector<int>> PathSum(TreeNode* root, int sum)
{
	vector<vector<int>> paths;
	vector<int> path;
	findPath(root, sum, path, paths);
	return paths;
}

void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& paths)
{
	if(node==nullptr) // 终止条件
		return;
	path.push_back(node->val); // 状态表示，使用 path 记录路径中的节点，必须使用 前向遍历
	if(node->val==sum && node->left==nullptr && node->right==nullptr){ // 收敛条件
		paths.push_back(path);
	}
	findPaths(node->left, sum-node->val, path, paths); // 扩展状态
	findPaths(node->right, sum-node->val, path, paths);
	path.pop_back();
}

void findMaximalPath(TreeNode* node, int & curSum, int & maxSum)
{
	if(node==nullptr) return;
	curSum += node->val;
	if(node->left==nullptr && node->right==nullptr && curSum>maxSum)
		maxSum = curSum;
	findMaximalPath(node->left, curSum, maxSum);
	findMaximalPath(node->right, curSum, maxSum);
	curSum -= node->val;
}

// 深搜时，状态使用全局变量进行表示，节省函数堆栈占用的内存
int result = numeric_limits<int>::min();

/* 找出和 最大的路径， 从任意节点到任意节点 */
int MaxToRoot(TreeNode* root)
{
	if(root==nullptr)
		return 0;
	int left = MaxToRoot(root->left);
	int right = MaxToRoot(root->right);
	if(left+right+root>result)
		result = left+right+root->val;
	return root->val + max(lef, right);
}

int maxPathSum(TreeNode* root)
{
	MaxToRoot(root, result);
	return result;
}

TreeNode* InorderSuccessorInBST(TreeNode* pNode)
{
	if(pNode==nullptr)
		return nullptr;
	TreeNode* pNext = nullptr;
	// 第一种情况：如果 pNode 有右子树，则返回右子树的最小值
	if(pNode->right)
	{
		pNode = pNode->right;
		while(pNode!=nullptr && pNode->left!=nullptr)
			pNode = pNode->left;
		pNext = pNode;
	}
	else{
		TreeNode* pParent = pNode->parent;
		while(pParent!=nullptr && pParent->left!=pNode){
			pNode = pParent;
			pParent = pParent;
		}
		pNext = pParent;
	}
	return pNext;
}

/* 判断平衡二叉树 */
 bool result = true;

 bool isBalanced(TreeNode* root){
 	if(root==nullptr) return true;
 	dfs(root);
 	return result;
 }

 int dfs(TreeNode* root)
 {
 	if(root==nullptr)
 		return 0;
 	int left = dfs(root->left);
 	int right = dfs(root->right);
 	if(abs(left-right)>1)
 		result = false;
 	return max(left, right) +1;
 }

bool isSameTree(TreeNode* p, TreeNode* q)
{
	if(p==nullptr || q==nullptr)
		return(p==q) // 妙哉，终止条件
	return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
}

bool isSubTree(TreeNode* s, TreeNode* t)
{
	if(s==nullptr) return false;
	if(isSameTree(s,t)) return true;
	return isSameTree(s->left, t) || isSameTree(s->right,t);
}

bool isSymmetric(TreeNode* root)
{
	if(root==nullptr)
		return true;
	return isSymmetric(root->left, root->right);
}

// 输入判空以成管理，使用指针必须判空
bool isSymmetric(TreeNode* root1, TreeNode* root2)
{
	if(root1==nullptr || root2==nullptr)
		return (root1==root2);
	return (root1->val==root2->val) && isSymmetric(root1->left,root2->right)
	&& isSymmetric(root1->right, root2->left);
}

/* 二叉排序树，左节点小于根节点，右节点大于根结点 */
bool isValidBST(TreeNode* root)
{
	if(root==nullptr)
		return true;
	TreeNode* pNode = root, *pLast = nullptr;
	stack<TreeNode*> st;
	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push(pNode);
			pNode = pNode->left;
		}
		else{
			if(pLast!=nullptr && pLast->val>=s.top()->val) // 使用前必须判空，指针的危险性
				return false;
			pNode = s.top()->right;
			pLast = s.top();
			s.pop();
		}
	}
	return true;
}

/* 方法2：为每个节点更新上下界限，逐个检查是否在这个界限里面，上面根节点的值就是下一层叶子节点的界限 */
bool isValidBST(TreeNode* root)
{
	int mn = numeric_limits<int>::min();
	int mx = numeric_limits<int>::max();
	return isValidBST(TreeNode* root, mn, mx);
}

bool isValidBST(TreeNode* root, int mn, int mx)
{
	if(root==nullptr) return true;
	if(root->val <= mn || root->val >= mx) return false;
	return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
}

/* layer-order traverse */
void LayerOrderTraverse(TreeNode* root)
{
	if(root==nullptr)
		return;
	queue<TreeNode*> q;
	q.push(root);

	TreeNode *pNode = nullptr;
	while(!q.empty())
	{
		pNode = q.front();
		q.pop();

		cout<<pNode->val;
		if(pNode->left) // 队列里面都是非空的元素
			q.push(pNode->left);
		if(pNode->right)
			q.push(pNode->right);
	}
}

/* 寻找最小公共祖先：二叉搜索树和非二叉搜索树 */
// 要求没有重复元素
TreeNode* LowerestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if(root==nullptr || p==nullptr || q==nullptr)
		return nullptr;

	// 首先保证 q, p 的顺序
	if(p->val>q->val) 
		return LowerestCommonAncestor(root, q, p);

	TreeNode* pNode = root;
	while(pNode){
		if(pNode->val>=p->val && pNode->val<=q->val) 
		// 这里的等于号是因为会出现 q时 p 的祖先节点的情况，而不是 因为 重复元素
			break;
		else if(pNode->val<p->val)
			pNode = pNode->right;
		else
			pNode = pNode->left;
	}
	return pNode;
}

/* 后序遍历的特点注定了后序遍历是最适合寻找路径的，对比一下， sum path 那一题 */
TreeNode* LowerestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	TreeNode* pNode = root, *pLast = nullptr;
	vector<TreeNode*> pathq, pathq, temp;

	while(pathp.empty() || pathq.empty())
	{
		// 进行标注的后序遍历流程
		if(pNode){
			temp.push_back(pNode); 
			if(pNode==p) pathp = temp;
			if(pNode==q) pathq = temp;
			pNode = pNode->left;
		}
		else{
			if(temp.back()->right==nullptr || temp.back()->right==pLast){
				pLast = temp.back();
				temp.pop_back();
			}
			else{
				pNode = temp.back()->right;
			}
		}
	}
	// compare paths and get lowest common ancestor
	int n = min(pathp.size(), pathq.size());
	for(int i=1;i<n;i++){  // 这里有个小心机，找到第一个不相等的，返回它的前一个
		if(pathp[i]!=pathq[i])
			return pathq[i-1];
	}
	return pathp[n-1];
}

/* layer-order traverse to array */
vector<vector<int>> LevelOrderToArray(TreeNode* root)
{
	vector<vector<int>> result;
	if(root==nullptr)
		return result;
	// 使用 nullptr 作为层结束的标记
	queue<TreeNode*> q;
	q.push(root);
	q.push(nullptr);
	vector<int> vec;

	while(!q.empty())
	{
		TreeNode* pNode = q.front();
		q.pop();
		if(pNode==nullptr){
			result.push_back(vec);
			vec.resize(0); // resize() 的用法，后面可重写
			if(q.size()>0){ // 检测此时队列是否为空，若为空，后面不用再加楔子
				q.push(nullptr);
			}
		}
		else{
			vec.push_back(pNode->val);
			if(pNode->left) q.push(pNode->left);
			if(pNode->right) q.push(pNode->right);
		}
	}
	return result;
}

int MaxDepth(TreeNode* root){
	return (root==nullptr)?0:max(MaxDepth(root->left),MaxDepth(root->right))+1;
}

int MinDepth(TreeNode* root)
{
	if(root==nullptr)
		return 0;
	if(root->left ==nullptr && root->right==nullptr)
		return 1;
	if(root->left ==nullptr)
		return MinDepth(root->right) +1;
	if(root->right ==nullptr)
		return MinDepth(root->left) +1;
	return min(MinDepth(root->left), MinDepth(root->right))+1;
}

void MirrorInBST(TreeNode* root)
{
	if(root==nullptr)
		return;
	stack<TreeNode*> st;
	TreeNode* pNode = root;

	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push(pNode);
			pNode = pNode->left;
		}
		else{
			pNode = st.top();
			st.pop();
			if(pNode->left!=nullptr || pNode->right!=nullptr)//
				swap(pNode->left, pNode->right);
			pNode = pNode->left; // 这一句是关键，一定要使用 right
		}
	}
}

/* 有序数组转化为 二叉树 */
typedef vector<int>::const_iterator iterator;
TreeNode* sortedArrayToBST(vector<int>& nums)
{
	if(nums.empty())
		return nullptr;
	return buildBST(nums.begin(), nums.end());
}

TreeNode* buildBST(iterator b, iterator e)
{
	if(b>=e)
		return nullptr;
	iterator m = b + (e-b)/2;
	TreeNode* root = new TreeNode(*m);
	root->left = buildBST(b,m);
	root->right = buildBST(m+1,e);

	return root;
}

/* 有序链表转化为 二叉树 */
TreeNode* build(ListNode* & head, int n)
{
	if(n<=0)
		return nullptr; // 链表长度为 0 时，返回空节点
	TreeNode* left = build(head, n/2);
	TreeNode* root = new TreeNode(head->val);
	root->left = left;
	head = head->next; // 中序遍历每建一个就往后移动一个
	root->right = build(head, n-n/2-1);
	return root;
}

int count(ListNode* head)
{
	return head?1+count(head->next):0;
}

TreeNode* SortedListToBST(ListNode* head)
{
	return build(head, count(head));
}





