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
			swap(array[left], array[right]);
	}
	swap(array[right], array[end]);
	return left;
}

int findMedian(int* array, int length)
{
	int k = (length-1)/ 2;
	int left = 0, right = length-1;
	int result = 0;
	while(true)
	{
		int q = partition(array, left, right);
		if(q==k){
			result = array[q];
			break;
		}
		else if(q<k)
			left = q+1;
		else
			right = q-1;
	}
	return result;
}

int getMiddle(int* array, int length)
{
	int half = (length-1)/2; 
	priority_queue<int, vector<int>, myCompare> q;

	for(int i=0;i<half;i++)
		q.push(array[i]);

	for(int i=half;i<length;i++){
		if(array[i]>q.top()){
			q.pop();
			q.push(array[i]);
		}
	}
	if(!q.empty())
		return q.top();
}

double findMedianOfSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size(), n = nums2.size();
	// 确保运行时间为 lg(min(m,n))
	if( m>n)
		return findMedianOfSortedArrays(nums2, nums1);

	int imin = 0, imax = m;
	int halfLen = (m+n+1)/2;
	int max_of_left = 0, min_of_right =0;

	while(imin<=imax) // 只要还有划分点，注意两端闭合
	{
		int i = (imin+imax)/2;
		int j = halfLen - i;
		// 以下讨论三种情况
		if(i>0 && nums1[i-1]>nums2[j])
			imax = i-1;
		else if(i<m && nums2[j-1]>nums1[i])
			imin = i+1;
		else{
			if(i==0)
				max_of_left = nums2[j-1];
			else if(j==0)
				max_of_left = nums1[i-1];
			else
				max_of_left = max(nums1[i-1], nums2[j-1]);

			if((m+n)%2==1)
				return max_of_left;

			if(i==m)
				min_of_right = nums2[j];
			else if(j==n)
				min_of_right = nums1[i];
			else
				min_of_right = min(nums1[i], nums2[j]);

			return (max_of_left+min_of_right)/2.0;

		}
	}
	return 0;
}

bool searchInRotatedArray2(int* array, int length, int target)
{
	int left = 0, right = length-1;

	while(left<right)
	{
		int mid = left + (right-left)/2;
		if(array[mid]==target)
			return true;
		if(array[mid]<array[right]){
			if(array[mid]<target && array[right]>=target)
				left = mid +1;
			else
				right = mid -1;
		}
		else if(array[mid]>array[right]){
			if(array[mid]>target && array[left]<=target)
				right = mid -1;
			else
				left = mid +1;
		}
		else
			right--;
	}
	return false;
}

void QuickSort(int* array, int start, int end)
{
	if(start<end){
		int k = partition(array, start, end);
		QuickSort(array, start, k-1);
		QuickSort(array, k+1, end);
	}
}

void Merge(int* array, int left, int mid, int right)
{
	int len1 = mid - left;
	int len2 = right - mid;

	int *arr1 = new int[len1];
	int *arr2 = new int[len2];

	for(int i=0;i<len1;i++)
		arr1[i] = array[left+i];
	for(int j=0;j<len2;j++)
		arr2[j] = array[mid+j];

	int i = 0, j =0, k = left;
	while(i<len1 && j<len2){
		if(arr1[i]<arr2[j])
			array[k++] = arr1[i++];
		else
			array[k++] = arr2[j++];
	}
	while(i<len1)
		array[k++] = arr1[i++];
	while(j<len2)
		array[k++] = arr2[j++];

	delete [] arr1;
	delete [] arr2;
}

void Heapify(int* array, int n, int i)
{
	int left = 2*i+1;
	int right = 2*i+2;
	int largest = i;

	if(left<n && array[left]>array[i])
		largest = left;
	if(right<n && array[right]>array[i])
		largest = right;
	if(largest!=i){
		swap(array[i],array[largest])
		Heapify(array, n, largest);
	}
}

void HeapSort(int* array, int length)
{
	if(array==nullptr || length<1)
		return;
	for(int i=length/2;i>=0;i--)
		Heapify(array, length, i);
	for(int n=length;n>0;n--){
		swap(array[n-1],array[0]);
		Heapify(array, n-1, 0);
	}
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	if(matrix.empty() || matrix[0].empty()) 
		return {};

	int m = matrix.size(), n = matrix[0].size();
	int l=0, r=n-1, u=0, d=m-1;

	vector<int> res(m*n,0);
	int p = 0;
	while(l<=r && u<=d)
	{
		for(int col=l;col<=r;col++){
			res[p++] = matrix[u][col];
		}
		if(++u>d) break;
		for(int row=u;row<=d;row++){
			res[p++] = matrix[row][r];
		}
		if(--r<l) break;
		for(int col=r;col>=l;col--){
			res[p++] = matrix[d][col];
		}
		if(--d<u) break;
		for(int row=d;row>=u;row--){
			res[p++] = matrix[row][l];
		}
		if(++l>r) break;
	}
	return res;
}

void rotateMatrix(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i;j++){
			swap(matrix[i][j],matrix[n-j-1][n-i-1]);
		}
	}
	for (int i = 0; i <n/2; ++i){
		for(int j=0;j<n;j++){
			swap(matrix[i][j],matrix[n-i-1][j]);
		}
	}
}

/* 组合问题 */
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> res;
	vector<int> out;
	dfs(n, k, 1, out, res);
	return res;
}

void dfs(int n, int k, int ind, vector<int>& out, vector<vector<int>>& res)
{
	if(out.size()==k){
		res.push_back(out);
		return;
	} // 收敛条件
	for(int i=ind;i<=n;++i){
		out.push_back(i);
		dfs(n, k, i+1, out, res);
		out.pop_back();
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
	vector<vector<int>> res;
	vector<int> path;
	vector<bool> visited(nums.size(), false);
	dfs(nums,0,res,path,visited);
	return res;
}

void dfs(vector<int>& nums, int len, vector<vector<int>>& res,
			vector<int>& path, vector<bool>& visited)
{
	if(len==nums.size()){
		res.push_back(path);
		return;
	}
	for(int i=0;i<nums.size();i++){
		if(visited[i]) continue; // 剪枝操作，避免重复操作
		if(i>0 && !visited[i-1] && nums[i]==nums[i-1]) continue;
		path.push_back(nums[i]); // 状态改变
		visited[i] = true;
		dfs(nums, len+1, res, path, visited);
		path.pop_back();
		visited[i] = false;
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> result;
	vector<int> combination;
	dfs(candidates, target, result, combination, 0);
	return result;
}

void dfs(vector<int>& candidates, int target, vector<vector<int>>& result,
			vector<int>& combination, int ind)
{
	if(target==0){ // 收敛条件， target 由 sum 不断减小
		result.push_back(combination);
		return;
	}
	for(int i=ind;i<candidates.size()&& target>=candidates[i];i++){
		if(i==ind || candidates[i]!=candidates[i-1]){
			combination.push_back(candidates[i]);
			combinationSum(candidates, target-candidates[i], result, combination,
								ind+1);
			combination.pop_back();
		}
	}
}

bool hasPathSum(TreeNode* root, int sum)
{
	if(root==nullptr)
		return false;
	if(root->val==sum && root->left==nullptr && root->right==nullptr)
		return true;
	return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, 
									sum-root>val);
}

vector<vector<int>> findPathSum(TreeNode* root, int sum)
{
	vector<vector<int>> paths;
	vector<int> path;
	dfs(root, sum, path, paths);
	return paths;
}

void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths)
{
	if(root==nullptr) return;
	path.push_back(root->val);
	if(root->val==sum && root->left==nullptr && root->right==nullptr){
		paths.push_back(path);
		return;
	}
	dfs(root->left, sum-root->val, path, paths);
	dfs(root->right, sum-root->val, path, paths);
	path.pop_back();
}

/* Reverse words in sentence */
void Reverse(char* begin, char* end)
{
	if(begin==nullptr || end==nullptr)
		return;
	while(begin<end){
		swap(*begin++,*end--);
	}
}

char* ReverseSentence(char* string)
{
	if(string==nullptr)
		return nullptr;
	char* start = string, *end=string;
	while(*end!='\0')
		end++;
	end--;
	Reverse(start, end);
	end = string;
	while(*start!='\0')
	{
		if(*start==' ')
			start++, end++;
		else if(*end==' ' || *end=='\0'){
			Reverse(start, --end);
			start = ++end;
		}
		else
			end++;
	}
	return string;
}

/* 将二叉树转换为 doubly linked list */

TreeNode* BSTtoDoublyLinkList(TreeNode* root)
{
	TreeNode* pLast = nullptr;
	dfs(root, pLast);

}

void dfs(TreeNode* root, TreeNode* &pLast)
{
	if(root==nullptr)
		return;
	dfs(root->left, pLast);
	root->left = pLast;
	if(pLast)
		pLast->right = root;
	pLast = root;
	dfs(root->right, pLast);
}

vector<int> BSTtoSortedArray(TreeNode* root)
{
	if(root==nullptr) return{};
	vector<int> res;
	TreeNode* pNode = root;
	stack<TreeNode*> st;
	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push(pNode);
			pNode=pNode->left;
		}
		else{
			res.push_back(st.top()->val);
			pNode = st.top()->right;
			st.pop();
		}
	}
	return res;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	return dfs(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}

TreeNode* dfs(iter i, iter j, iter ii, iter jj)
{
	if(i>=j || ii>=jj)
		return nullptr;
	int mid = *(jj-1);
	TreeNode* root = new TreeNode(mid);
	auto dist = find(i,j,mid) - i;

	root->left = dfs(i, i+dist, i+dist+1, j);
	root->right = dfs(ii, ii+dist, ii+dist, jj-1);
}

TreeNode* buildTree(iter begin, iter end)
{
	if(begin>=end)
		return nullptr;
	auto maxIter = max_element(begin, end);
	TreeNode* root = new TreeNode(*maxIter);
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
	if(root==nullptr)
		return 0;
	int leftLen = dfs(root->left, res);
	int rightLen = dfs(root->right, res);
	if(leftLen+rightLen+1>res)
		res = leftLen+rightLen+1;
	return max(leftLen,rightLen)+1;
}

void dfs(TreeNode*root, string t, vector<string>& result)
{
	if(root->left==nullptr || root->right==nullptr){
		result.push_back(t);
		return;
	}
	if(root->left)
		dfs(root->left, t+"->"+to_string(root->left->val),result);
	if(root->right)
		dfs(root->right, t+"->"+to_string(root->right->val),result);
}

/* 找到二叉树所有和为 sum 的路径 */

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
	vector<int> path;
	vector<vector<int>> results;
	dfs(root, sum, path, results);
	return results;
}

void dfs(TreeNode* root, int sum, vector<int> path, 
	vector<vector<int>>& results)
{
	if(root==nullptr)
		return;
	path.push_back()
	if(root->val==sum && root->left==nullptr && root->right==nullptr){
		results.push_back(path);
	}
	dfs(root->left, sum-root->val, path, results);
	dfs(root->right, sum-root->val, path, results);
	path.pop_back();
}

void dfs(TreeNode* root, int cur, int& maximal)
{
	if(root==nullptr)
		return;
	cur += root->val;
	if(root->left==nullptr && root->right==nullptr && cur>maximal)
		maximal = cur;
	dfs(root->left, cur, maximal);
	dfs(root->right, cur, maximal);
	cur -= root->val;
}

int maximalPath(TreeNode* root, int& maximal)
{
	if(root==nullptr)
		return 0;
	int left = max(maximalPath(root->left, maximal),0);
	int right = max(maximalPath(root->right, maximal),0);
	if(left+right+root->val>maximal)
		maximal = left+right+root->val;
	return max(left,right)+root->val;
}

int maxPathSum(TreeNode* root)
{
	int result = numeric_limits<int>::min();
	return maximalPath(root,result);
}

void flattenTree(TreeNode* root)
{
	if(root==nullptr)
		return;
	flattenTree(root->left);
	flattenTree(root->right);
	TreeNode* temp = root->right;
	root->right = root->left;
	root->left = nullptr;
	while(root->right)
		root = root->right;
	root->right->temp;
}

vector<int> postOrderTraverse(TreeNode* root)
{
	vector<int> res;
	TreeNode* pNode = root, *pLast = nullptr;
	stack<TreeNode*> st;
	while(!st.empty() || pNode)
	{
		if(pNode){
			st.push(pNode);
			pNode = pNode->left;
		}
		else
		{
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
	return res;
}

vector<vector<int>> zigzagLevelTraverse(TreeNode* root)
{
	vector<vector<int>> res;
	if(root==nullptr)
		return res;
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	s1.push(root);
	vector<int> out;

	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			TreeNode* pNode = s1.top();
			s1.pop();
			out.push_back(pNode->val);
			if(cur->left) s2.push(cur->left);
			if(cur->right) s2.push(cur->right);
		}
		if(!out.empty())
			res.push_back(out);
		out.clear();
		while(!s2.empty())
		{
			TreeNode* pNode = s2.top();
			s2.pop();
			out.push_back(pNode->val);
			if(cur->right) s1.push(cur->right);
			if(cur->left) s2.push(cur->left);
		}
		if(!out.empty())
			res.push_back(out);
		out.clear();
	}
	return res;
}

ListNode* sortList(ListNode* head)
{
	if(!head || !head->next)
		return head;
	ListNode* fast=head, *slow=head;
	ListNode* pre = nullptr;
	while(fast && fast->next)
	{
		pre = slow;
		fast = fast->next->next;
		slow = slow->next;
	}
	pre->next = nullptr;
	return mergeTwoLists(sortList(head),sortList(slow));
}

ListNode* swapPairs(ListNode* head)
{
	ListNode* front = new ListNode(0);
	front->next = head;
	ListNode* pre = front;
	while(head && head->next)
	{
		pre->next = head->next;
		head->next = pre->next->next;
		pre->next->next = head;
		pre = head;
		head = head->next;		
	}
	head = front->next;
	delete front;
	return head;
}

ListNode* partitionList(ListNode* head, int x)
{
	ListNode* left = new ListNode(0);
	ListNode* right = new ListNode(0);
	ListNode* l = left, *r = right;
	while(head)
	{
		if(head->val<x){
			l->next = head;
			l = l->next;
		}
		else{
			r->next = head;
			r = r->next;
		}
		head = head->next;
	}
	l->next = right->next;
	head = left->next;
	r->next = nullptr;
	delete left;
	delete right;
	return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* front = new ListNode(0);
	ListNode* d = front;
	int sum= 0;
	while(l1 || l2)
	{
		sum /= 10; // 取余数
		if(l1){
			sum += l1->val;
			l1 = l1->next;
		}
		if(l2){
			sum += l2->val;
			l2 = l2->next;
		}
		d->next = new ListNode(sum%10); // sum%10 新建结点
		d = d->next;
	}
	if(sum/10){
		d->next = new ListNode(sum/10); // 最后的sum还没来得及 /10
		d = d->next;
	}
	d = front->next;
	delete front;
	return d;
}

ListNode* oddEvenList(ListNode* head)
{
	if(head==nullptr) return nullptr;
	ListNode* odd = head, *even = head->next;
	ListNode* even_head = even;
	while(even && even->next)
	{
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = even_head;
	return head;
}

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> res;
	vector<int> out;
	dfs(n, k, out, res);
	return res;
}

void dfs(int n, int k, vector<int>& out, vector<vector<int>>& res, int ind)
{
	if(out.size()==k){
		res.push_back(out);
		return;
	}
	for(int i=ind;i<=n;i++)
	{
		out.push_back(ind);
		dfs(n,k,out,res,ind+1);
		out.pop_back();
	}
}

vector<vector<int>> combine(vector<int>& nums, int k)
{
	sort(nums.begin(),nums.end())
	vector<vector<int>> res;
	vector<int> out;
	dfs(nums, k, out, res, ind);
	return res;
}

void dfs(vector<int>& nums, int k, vector<int>& out, 
				vector<vector<int>>& res, int ind)
{
	if(out.size()==k){
		res.push_back(out);
		return;
	}
	for(int i=ind;i<nums.size();i++)
	{
		if(i!=ind || nums[i]!=nums[i-1]){
			out.push_back(nums[i]);
			dfs(nums,k,out,res,ind+1);
			out.pop_back()
		}
	}
}

void dfs(vector<int>& nums, int target, vector<vector<int>>& result,
				vector<int>& combination, int ind)
{
	if(target==0){
		result.push_back(combination);
	}

	for(int i=ind;i<nums.size() && target>nums[i];i++)
	{
		if(i!=ind || nums[i]!=nums[i-1]){
			combination.push_back(nums[i]);
			dfs(nums,target-nums[i],result,combination,ind+1);
			combination.pop_back();
		}
	}
}

vector<vector<int>> permution(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> out;
	vector<bool> visited(nums.size(), false);
	dfs(nums, out, res, visited);
	return res;
}

void dfs(vector<int>& nums, vector<int>& out, vector<vector<int>>& res,
												vector<bool>& visited)
{
	if(out.size()==nums.size()){
		res.push_back(out);
		return;
	}
	for(int i=0;i<nums.size();i++)
	{
		if(visited[i])
			continue;
		if(i>0 && !visited[i-1] && nums[i]==nums[i-1])
			continue;
		out.push_back(nums[i]);
		visited[i] = true;
		dfs(nums,out,res,visited);
		visited[i] = false;
		out.pop_back();
	}
}

int maxProduct(vector<int>& nums)
{
	int mx = nums[0], mn = nums[0], res = nums[0];
	for(int i=1;i<nums.size();i++)
	{
		int temp_mx = mx, temp_mn = mn;
		mx = max(max(temp_mx*nums[i], nums[i]), temp_mn*nums[i]);
		mn = max(max(temp_mn*nums[i], nums[i]), temp_mx*nums[i]);
		res = max(res, mx);
	}
	return res;
}

int minDistance(string& word1, string& word2)
{
	int m = word1.size(), n=word2.size();
	vector<int> dp(n+1,0);
	vector<int> dp2(n+1,0);
	for(int i=0;i<=n;i++)
		dp2[i] = i;
	for(int i=1;i<=m;i++){
		dp[0] = i;
		for(int j=1;j<=n;j++){
			dp[j] = (word1[i-1]==word2[j-1])?dp2[j-1]:min(dp2[j-1],
											min(dp2[j],dp[j-1]))+1;
		}
		swap(dp,dp2);
	}
	return dp2[n];
}

int longestCommonSequence(string& A, string& B)
{
	int m = A.size(), n = B.size();

	vector<int> dp(n+1,0);
	vector<int> dp2(n+1,0);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[j] = (A[i-1]==B[j-1])?dp2[j-1]+1:max(dp2[j],dp[j-1]);
		}
		swap(dp,dp2);
	}
	return dp2[n];
}

int LongestIncreasingSequence(vector<int>& nums)
{
	if(nums.empty()) 
		return 0;
	vector<int> tailTable;
	vector<vector<int>> records;
	tailTable.push_back(nums[0]);
	records.push_back(tailTable);

	for(int num:nums)
	{
		int start = 0, end = tailTable.size();
		while(start<end){
			int mid = start+(end-start)/2;
			if(tailTable[mid]<num)
				start = mid+1;
			else
				end = mid;
		}
		if(start==tailTable.size()){
			tailTable.push_back(num);			
			records.push_back(tailTable.back().push_back(num));
		}
		else{
			tailTable[start] = num;
			records[start].pop_back();
			records[start].push_back(num);
		}
	}
	return records.back();
}

string longestPalidrome(string& s)
{
	string result;
	if(s.empty()) return;
	int n = s.size();
	int start = 0, maxLen = 0;
	vector<vector<bool>> isPalidrome(n, vector<bool>(n, false));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(s[i]==s[j] && (i-j<2 || isPalidrome[j+1][i-1]))
			{
				isPalidrome[j][i] = true;
				if(i-j+1>maxLen)
				{
					maxLen = i-j+1;
					start = i;
				}
			}
		}
	}
	return s.substr(start, maxLen);
}

int longestPalidromeSubsequence(string& s)
{
	int n = size();
	vector<int> dp(n,0);
	vector<int> dp2(n,0);
	for(int i=n-1;i>=0;i--)
	{
		dp[i] = 1;
		for(int j=i+1;j<n-1;j++)
		{
			dp[j] = (s[j]==s[i])?dp2[j-1]+2:max(dp2[j],dp[j-1]);
		}
		swap(dp,dp2);
	}
	return dp2[n-1];
}

int maxProfit(vector<int>& nums, int k)
{
	if(nums.size()<2) return -1;
	if(nums.size()<=k) return maxProfit(nums);

	int n = nums.size();
	vector<int> dp(n, 0);
	for(int i=1;i<=k;i++)
	{
		temp = dp[0] - nums[0];
		for(int j=1;j<n;j++)
		{
			dp_temp = dp[j]; // 保存这个时刻，留着下时刻用
			dp[j] = max(dp[j-1], temp+nums[j]);
			temp = max(temp, dp_temp-prices[j]);
		}
	}
	return dp[n-1];
}


