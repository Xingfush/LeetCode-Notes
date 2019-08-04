/* 目标和的组合，使用回溯法 */

vector<vector<int>> combinationSum(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	vector<int> path;
	dfs();
	return res;
}

void dfs(vector<int>& nums, int target, vector<vector<int>>& res, 
										vector<int> path, int ind)
{
	if(target==0){
		res.push_back(path);
		return;
	}
	for(int i=ind;i<nums.size() && target<=nums[i];i++)
	{
		if(i==ind || nums[i]!=nums[i-1]){
			path.push_back(nums[i]);
			dfs(nums, target-nums[i], res, path, ind+1);
			path.pop_back();
		}
	}
}

/* 组合的框架 */

vector<vector<int>> combine(vector<int>& nums, int k)
{
	sort(nums.begin(),nums.end());
	vector<vector<int>> res;
	vectro<int> path;
	dfs(nums)
	return res;
}

void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path,
								int k, int ind)
{
	if(path.size()==k){
		res.push_back(path);
		return;
	}
	for(int i=ind;i<nums.size();i++){
		if(i==ind || nums[i]==nums[i-1]){
			path.push_back(nums[i]);
			dfs(nums, res, path, k, ind+1);
			path.pop_back();
		}
	}
}

vector<vector<int>> permution(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	vector<int> path;
	vector<bool> visited(nums.size(), false);
	dfs();
	return res;
}

void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int> path,
											vector<bool>& visited)
{
	if(path.size()==nums.size()){
		res.push_back(path);
		return;
	}
	for(int i=0;i<nums.size();i++){
		if(visited[i]) continue;
		if(i>0 && !visited[i-1] && nums[i]==nums[i-1]) continue;
		path.push_back(nums[i]);
		visited[i] = true;
		dfs(nums, res, path, visited);
		path.pop_back();
		visited[i] = false;
	}
}									

void dfs_iterative(int s, vector<vector<int>>& G)
{
	int n = G.size();
	vector<bool> visited(n);
	stack<int> st;
	st.push(s);
	while(!st.empty())
	{
		int temp = st.top();
		st.pop();
		cout<<temp<<" ";
		visited[temp]=true;
		for(int i=0;i<n;i++){ // 将所有的子结点入栈
			if(G[temp][i]!=INT_MAX && !visited[i])
				st.push(i);
		}
	}
	cout<<endl;
}

/* 字符串数组深度遍历 */

bool flag = false;

void dfs(vector<string>& strs, vector<bool>& visited, vector<char>& path,
											int len)
{
	if(len==strs.size() && path.size()==2){
		if(path[0]==path[1]){
			flag = true;
			return;
		}
	}
	for(int i=0=;i<strs.size();i++)
	{
		if(!visited[i] && strs[i].front()==path.back()){
			visited[i] = true;
			path.pop_back();
			path.push_back(strs[i].front());
			dfs(strs, visited, path, len+1);
			path.pop_back();
			path.push_back(strs[i].front());
			visited[i] = false;
		}
	}
}											
									
/* 拼多多，星檐，加油！！！ */

/* 找到第一个大于等于key的值 */
int BinarySearch(int* array, int left, int right, int key)
{
	while(left<right)
	{
		int mid = left+(right-left)/2;
		if(array[mid]<left)
			left = mid +1;
		else
			right = mid;
	}
	return right;
}

int BinarySearchFirst(int* array, int left, int right, int key)
{
	int res= -1;
	while(left<right)
	{
		int mid = left + (right-left)/2;
		if(array[mid]==key){
			res = mid;
			right = mid;
		}
		if(array[mid]<key)
			left = mid +1;
		else
			right = mid;
	}
	return res;
}


/* 经典的partition函数 */
int partition(int* array, int start, int end)
{
	int left = start, right = end;
	int pivot = array[end];
	while(left<right)
	{
		while(left<right && array[left]<pivot)
			left++;
		while(left<right && array[right]>=pivot)
			right--;
		if(left<right)
			swap(array[left],array[right]);
	}
	swap(array[right],array[end]);
	return right;
}

int findKthElement(int* array, int length, int k)
{
	if(k>length)
		throw "wrong parameters!";
	int left = 0, right = length-1;
	int res = 0;
	while(true)
	{
		int q = partition(array, left, right);
		if(q==k){
			res = array[q];
			break;
		}		
		else if(q<k)
			left = q+1;
		else
			right = q-1;
	}
	return res;
}

/* 两个有序数组的中位数 */
double findMedianOfSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size(), n = nums2.size();
	if(m>n)
		return findMedianOfSortedArrays(nums2, nums1);

	int imin = 0, imax = m;
	int halfLen = (m+n+1)/2;
	int max_of_left = 0, min_of_right = 0;
	while(imin<imax)
	{
		int i = (imin+imax)/2;
		int j = halfLen - i;

		if(i>0 && nums1[i-1]>nums2[j])
			imax = i - 1;
		else if(i<m && nums2[j-1]>nums1[i])
			imin = i + 1;
		else{
			if(i==0)
				max_of_left = nums2[j-1];
			else if(j==0)
				max_of_left = nums1[i-1];
			else
				max_of_left = max(nums1[i-1],nums2[j-1]);

			if((m+n)%2==1)
				return max_of_left;

			if(i==m)
				min_of_right = nums2[j];
			else if(j==n)
				min_of_right = nums1[i];
			else
				min_of_right = min(nums1[i],nums2[j]);

			return (min_of_right+max_of_left)/2.0;
		}
	}
	return 0;
}

double findTopKthOfSortedArrays(int* array1, int len1, 
										int* array2, int len2, int k)
{
	if(len1>len2)
		return findTopKthOfSortedArrays(array2, len2, array1, len1);
	if(len1==0)
		return array2 + k -1;
	if(k==1)
		return min(array2[0],array1[0]);

	int k1 = min(k/2, len1);
	int k2 = k-k1;

	if(array1[k1-1]>array2[k2-1])
		return findTopKthOfSortedArrays(array1, len1, array2+k2, len2-k2, k-k2);
	else if(array1[k1-1]<array2[k2-1])
		return findTopKthOfSortedArrays(array1+k1, len1-k1, array2, len2, k-k1);
	else
		return array1[k1-1];
}

int minOrderArray(int* array, int left, int right)
{
	int res = array[right];
	for(int i=left;i<right;i++){
		if(array[i]<res)
			res = array[i];
	}
	return res;
}

int MinOfRatateArray(int* array, int length)
{
	if(array==nullptr || length==0)
		throw "wrong parameters!";
	if(length<=1)
		return array[0];
	int left = 0, right = length-1;
	int mid = left;
	while(array[left]>=array[right])
	{
		if(right-left==1){
			mid = right;
			break;
		}
		int mid = left + (right-left)/2;
		if(array[mid]==array[right] && array[left]==array[right])
			return minOrderArray(array, left, right);
		else if(array[mid]<=array[right])
			right = mid;
		else
			left = mid;
	}
	return array[mid];
}

bool searchInRotatedArray(int* array, int length, int key)
{
	int left = 0, right = length-1;

	while(left<=right)
	{
		int mid = left + (right-left)/2;
		if(array[mid]==key)
			return true;
		if(array[mid]<array[right]){
			if(array[mid]<key && array[right]>=key)
				left = mid +1;
			else 
				right = mid -1;
		}
		else if(array[mid]>array[right]){
			if(array[mid]>key && array[left]<=key)
				right = mid -1;
			else
				left = mid +1;
		}
		else
			right--;
	}
	return false;
}

int kthSmallest(vector<vector<int>>& matrix, int k)
{
	int n = matrix.size();
	int left = matrix[0][0], right = matrix[n-1][n-1];
	while(left<right)
	{
		int mid = left + (right-left)/2;
		int num = 0;
		for(int i=0;i<n;i++){
			num += upper_bound(matrix[i].begin(),matrix[i].end(),mid)
							-matrix[i].begin();
		}
		if(num<k)
			left = mid +1;
		else
			right = mid;
	}
	return left;
}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if(matrix.empty() || matrix[0].empty())
		return false;
	int m = matrix.size(), n = matrix[0].size();
	int i = 0, j=n-1;
	while(i<m && j>=0)
	{
		if(matrix[i][j]==target)
			return true;
		if(matrix[i][j]<target){
			int top = i, bottom = m;
			while(top<bottom){
				int mid = top + (bottom-top)/2;
				if(matrix[mid][j]<target)
					top = mid +1;
				else
					bottom = mid;
			}
			i = bottom;
		}
		else{
			int left = 0, right = j;
			while(left<right){
				int mid = left + (right-left)/2;
				if(matrix[i][mid]<=target)
					left = mid +1;
				else
					right = mid;
			}
			j = left -1;
		}
	}
	return false;
}

int Sqrt(int x)
{
	if(x<2) return x;
	int left =0, right = x;
	while(left<right)
	{
		int mid = left + (right-left)/2;
		if(x/mid>=mid)
			left = mid +1;
		else 
			right = mid;
	}
	return left-1;
}

/* 统计素数的个数 */
int CountPrimes(int n)
{
	int res =0;
	vector<bool> prime(n, true);
	for(int i=2;i<n;i++){ // 从2开始
		if(prime(i)){
			res++;
			for(int j=2;i*j<n;j++)
				prime[i*j]=false;
		}
	}
	return res;
}

int InversePairsHelper(int* data, int* copy, int start, int end)
{
	if(end-start<2){
		copy[0]=data[0];
		return 0; // 只有一个元素时候没有逆序对
	}
	int mid = start + (end-start)/2;
	int leftPairs = InversePairsHelper(copy, data, start, mid);
	int rightPairs = InversePairsHelper(copy, data, mid, end);

	int i= start, j = mid;
	int copyInd = start;
	int count = 0;
	while(i<mid && j<end)
	{
		if(data[i]<=data[j])
			copy[copyInd++] = data[i++];
		else{
			count += mid -i;
			copy[copyInd++] = data[j++];
		}
	}
	while(i<mid)
		copy[copyInd++] = data[i++];
	while(j<end)
		copy[copyInd++] = data[j++];
	return count + leftPairs + rightPairs;
}

int InversePairs(int* data, int length)
{
	if(data==nullptr || length<=0)
		return 0;
	int* copy = new int[length];
	for(int i=0;i<length;i++)
		copy[i] == data[i];
	int count = InversePairsHelper(data, copy, 0, length);
	delete [] copy;

	return count;
}

int majorityElement(vector<int>& nums)
{
	int counter = 1;
	int majorInd = 0;
	for(int i=1;i<nums.size();i++){
		nums[i] ==nums[majorInd]?counter++:counter--;
		if(counter==0){
			majorInd = i;
			counter=1;
		}
	}
	return nums[majorInd];
}

/* 回溯法，状态，扩展，终止条件，收敛条件 */
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> res;
	vector<int> out;
	dfs(n, k, 1, out, res);
	return res;
}

void dfs(int n, int k, int ind, vector<int>& out, 
								vector<vector<int>>& res)
{
	if(out.size==k){
		res.push_back(out);
		return;
	}
	for(int i=ind;i<n;i++){
		out.push_back(i);
		dfs(n, k, ind+1, out, res);
		out.pop_back();
	}
}

/* 经典问题，和的组合 */
vector<vector<int>> combinationSum(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	vector<int> path;
	dfs(nums)
	return res;
}

void dfs(vector<int>& nums, int target, vector<vector<int>>& res,
						vector<int>& path, int ind)
{
	if(target==0){
		res.push_back(path);
		return;
	}
	for(int i=ind;i<nums.size() && nums[i]<target;i++)
	{
		if(i==ind || nums[i]!=nums[i-1])
		{
			path.push_back(nums[i]);
			dfs(nums, target-nums[i], res, path, ind+1);
			path.pop_back();
		}
	}
}

vector<vector<int>> permution(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
	vector<vector<int>> res;
	vector<int> path;
	vector<bool> visited(nums.size(),false);
	dfs();
	return res;
}

void dfs(vector<int>& nums, int len, vector<vector<int>>& res
							vector<int>& path, vector<bool>& visited)
{
	if(len==nums.size()){
		res.push_back(path);
		return;
	}
	for(int i=0;i<nums.size();i++)
	{
		if(visited[i]) continue;
		if(i>0 && !visited[i-1] && nums[i]==nums[i-1]) continue;
		path.push_back(nums[i]);
		visited[i] = true;
		dfs(nums, len+1, res, path, visited);
		visited[i] = false;
		path.pop_back();
	}
}

/* 二叉树是最经典的回溯法应用场景 */
bool hasPathSum(TreeNode* root, int sum)
{
	if(root==nullptr)
		return false; // 终止条件
	if(root->left==nullptr && root->right==nullptr && root->val==sum)
		return true;
	return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right,
							sum-root->val);
}

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> res;
	vector<int> path;

}

void dfs(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& path)
{
	if(root==nullptr)
		return;
	path.push_back(root->val);
	if(root->left==nullptr && root->right==nullptr && root->val==sum)
		res.push_back(path);
	dfs(root->left, sum-root->val, res, path);
	dfs(root->right, sum-root->right, res, path);
	path.pop_back();
}

void dfs(TreeNode* root, int& curSum, int& maxSum)
{
	if(root==nullptr)
		return;
	curSum += root->val;
	if(root->left==nullptr && root->right==nullptr && curSum>maxSum)
		curSum = maxSum;
	dfs(root->left, curSum, maxSum);
	dfs(root->right, curSum, maxSum);
	curSum -= root->val;
}

/* 任意路径最大值 */
int MaxToRoot(TreeNode* root, int& re)
{
	if(root==nullptr)
		return 0;
	int left = max(MaxToRoot(root->left, re),0);
	int right = max(MaxToRoot(root->right, re),0);
	if(left+right+root->val>re)
		re = left+right+root->val;
	return max(left,right)+root->val;
}

/* 非循环遍历走一遍 */
vector<int> preOrderTraverse(TreeNode* root)
{
	vector<int> res;
	TreeNode* pNode = root;
	stack<TreeNode*> st;
	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push_back(pNode);
			res.push_back(pNode->val);
			pNode = pNode->left;
		}
		else{
			pNode = st.top();
			st.pop();
			pNode = pNode->right;
		}
	}
}

vector<int> inOrderTraverse(TreeNode* root)
{
	vector<int> res;
	TreeNode* pNode = root;
	stack<TreeNode*> st;
	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push_back(pNode);
			pNode = pNode->left;
		}
		else{
			pNode = st.top();
			res.push_back(pNode->val);
			pNode = pNode->right;
		}
	}
}

vector<int> postOrderTraverse(TreeNode* root)
{
	vector<int> res;
	TreeNode* pNode = root, pLast =nullptr;
	stack<TreeNode*> st;
	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push_back(pNode);
			pNode = pNode->left;
		}
		else{
			if(st.top()->right==nullptr || st.top()->right==pLast){
				res.push_back(st.top()->val);
				pLast = st.top();
				st.pop();
			}
			else{
				pNode = st.top()->right;
			}
		}
	}
}

void layerOrderTraverse(TreeNode* root)
{
	if(root==nullptr)
		return;
	TreeNode* pNode = root;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		pNode = q.front();
		q.pop();
		res.push_back(pNode->val);
		if(pNode->left) q.push_back(pNode->left);
		if(pNode->right) q.push_back(pNode->right);
	}
}

/* 最小公共祖先 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	TreeNode *pNode = root, *pLast = nullptr;
	vector<TreeNode*> temp, pathp, pathq;

	while(pathp.empty() || pathq.empty())
	{
		if(pNode){
			temp.push_back(pNode);
			if(pNode==p) pathp=temp;
			if(pNode==q) pathq=temp;
			pNode = pNode->left;
		}
		else{
			if(temp.back()->right==nullptr || temp.back()->right==pLast){
				pLast = temp.back();
				temp.pop_back();
			}
			else
				pNode = temp.back()->right;
		}
	}

	int n = min(pathp.size(),pathq.size());
	for(int i=0;i<n;i++){
		if(pathp[i]!=pathq[i])
			return pathp[i-1];
	}
	return pathp[n-1]; 
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if(root==nullptr || p==nullptr || q==nullptr)
		return nullptr;
	if(p->val>q->val)
		return lowestCommonAncestor(root, p, q);

	TreeNode* pNode = root;
	while(pNode)
	{
		if(pNode->val>q->val)
			pNode = pNode->left;
		else if(pNode->val<p-val)
			pNode = pNode->right;
		else
			break;
	}
	return pNode;
}

TreeNode* Covert(TreeNode* root)
{
	TreeNode* pLast = nullptr;
	dfs(root, pLast);
	TreeNode* pHead = pLast;
	while(pHead && pHead->left)
		pHead = pHead->left;
	return pHead;
}

void dfs(TreeNode* root, TreeNode*& pLast)
{
	if(root==nullptr)
		return;
	dfs(root->left, pLast);
	root->left=pLast;
	if(pLast)
		pLast->right=root;
	pLast = root;
	dfs(root->right, pLast);
}

TreeNode* getKthTreeNode(TreeNode* root, int & k)
{
	TreeNode* result = nullptr;
	if(root->left)
		result = getKthTreeNode(root, k);
	if(result==nullptr){
		if(k==1)
			return root;
		k--;
	}
	if(result==nullptr && root->right)
		result = getKthTreeNode(root->right, k);
}

typedef vector<int>::const_iterator iter;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	return dfs(inorder.begin(), inorder.end(), postorder.begin(),
												postorder.end());
}

TreeNode* dfs(iter i, iter j, iter ii, iter jj)
{
	if(i>=j || ii>=jj)
		return nullptr; // 返回空结点
	int mid = *(jj-1);
	TreeNode* root = new TreeNode(mid);
	auto dist = find(i,j,mid) -i;
	root->left = dfs(i, i+dist, ii, ii+dist);
	root->right = dfs(i+dist+1, j, ii+dist, jj-1);
	return root;
}

TreeNode* buildTree(iter begin, iter end)
{
	if(begin>=end)
		return nullptr;
	auto maxIter = max_element(begin, end);
	TreeNode* root = TreeNode(*maxIter);
	root->left = buildTree(begin, maxIter);
	root->right = buildTree(maxIter+1, end);
	return root;
}

int diameterOfBinaryTree(TreeNode* root)
{
	int res = 0;
	dfs(root, res);
	return res;
}

int dfs(TreeNode* root, int& res)
{
	if(root==nullptr) return 0;
	int lefeLen = dfs(root->left, res);
	int rightLen = dfs(root->right, res);
	res = max(lefeLen+rightLen+1,res);
	return max(lefeLen, rightLen) +1;
}

vector<int> ans;
map<TreeNode*, TreeNode*> parent;
set<TreeNode*> visited;

void findParent(TreeNode* root)
{
	if(root==nullptr) return;
	if(root->left){
		parent[root->left] = root;
		findParent(root->left);
	}
	if(root->right){
		parent[root->right] = root;
		findParent(root->right);
	}
}

void dfs(TreeNode* root, int K)
{
	if(visited.count(root))
		return; // 剪枝条件
	visited.insert(root);
	if(K==0){
		ans.push_back(root->val);
		return; // 收敛条件
	}
	if(root->left) // 相当于终止条件
		dfs(root->left, K-1);
	if(root->right)
		dfs(root->right, K-1);
	if(parent[root])
		dfs(parent[root], K-1);
}

void flatten(TreeNode* root)
{
	if(root==nullptr)
		return;
	flatten(root->left);
	flatten(root->right);
	TreeNode* temp = root->right;
	root->right = root->left;
	root->left = nullptr;
	while(root->right)
		root=root->right;
	root->right = temp;
}

TreeNode* InorderSuccessor(TreeNode* pNode)
{
	if(pNode==nullptr)
		return nullptr;
	TreeNode* pNext = nullptr;
	if(pNode->right!=nullptr){
		pNode = pNode->right;
		while(pNode){
			pNode = pNode->left;
		}
		pNext = pNode;
	}
	else{
		TreeNode* pParent = pNode->parent;
		while(pParent!=nullptr && pParent->left!=pNode){
			pNode = pParent;
			pParent = pParent->parent;
		}
		pNext = pParent;
	}
	return pNext;
}

bool isBalanced(TreeNode* root)
{
	if(root==nullptr)
		return true;
	bool flag = false;
	dfs(TreeNode* root, bool& flag);
	return flag;
}

int dfs(TreeNode* root, bool& flag)
{
	if(root==nullptr) return 0;
	int left = dfs(root->left);
	int right = dfs(root->right);
	if(abs(left-right)>1)
		flag = false;
	return max(left, right) +1;
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
	if(p==nullptr || q==nullptr)
		return true;
	return (p==q) && isSameTree(p->left, q->left) && 
							isSameTree(p->right, q->right);
}

bool isSubtree(TreeNode* s, TreeNode* t)
{
	if(s==nullptr) return false;
	if(isSameTree(s,t)) return true;
	return isSubtree(s->left, t) && isSubtree(s->right, t);
}

bool isSymmetric(TreeNode* root)
{
	if(root==nullptr)
		return true;
	return isSymmetric(root->left, root->right);
}

bool isSymmetric(TreeNode* left, TreeNode* right)
{
	if(left==nullptr && right==nullptr)
		return true;
	if(left==nullptr || right==nullptr)
		return false;
	return (left->val==right->val) && isSymmetric(left->left, right->right)
								&& isSymmetric(left->right, right->left);
}

bool dfs(TreeNode* root, long mn, long mx)
{
	if(root==nullptr)
		return true;
	if(root->val <= mn || root->val>= mx)
		return false;
	return dfs(root->left, mn, root->val) && dfs(root->right, root->val, mx);	
}

bool isValidBST(TreeNode* root){
	long mx = numeric_limits<long>::max();
	long mn = numeric_limits<long>::min();
	return dfs(root, mn, mx);
}

void dfs(TreeNode* pNode, int K)
{
	if(visited.count(pNode)) return; // 剪枝条件
	if(K==0){
		ans.push_back(pNode->val);
		return;
	}
	if(pNode->left)
		dfs(pNode->left, K-1);
	if(pNode->right)
		dfs(pNode->right, K-1);
	if(parent[pNode])
		dfs(parent[pNode], K-1);
	// 把终止条件放在这里，
}





