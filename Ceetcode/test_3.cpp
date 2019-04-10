vector<vector<int> > combinationSum(vector<int> & candidates, int target){
	vector<int> combination;
	vector<vector<int> > result;
	sort(candidates.begin(),candidates.end());
	combinationSum(candidates, target, combination, result, index);
	return result;
}

void combinationSum(vector<int>& candidates, int target, vector<int> combination, vector<vector<int>>& result, int index){
	if(target==0){
		result.push_back(combination);
		return 0; // 非负数组，一次遍历只有一个可能
	}
	for(int i=index;i<candidates.size() && target>=candidates[i];i++){
		if(i==index || candidates[i]==candidates[i-1]){ // 后判别
			combination.push_back(candidates[i]);
			combinationSum(candidates, target-candidates[i], combination, result, i+1);
			combination.pop_back();
		}
	}
}

vector<vector<string>> partition(string s){
	vector<string> path;
	vector<vector<string>> result;
	dfs(s,path,result,0);
	return result;
}

void dfs(string& s, vector<string> path, vector<vector<string>> & result, int index){
	if(index == s.size()){
		result.push_back(path);
		return;
	}
	for(int i=index;i<s.size();i++){
		if(isPalindrome(s,index,i)){
			path.push_back(s.substr(index,i-index+1));
			dfs(s,path,result,i+1);
			path.pop_back();
		}
	}
}

bool isPalindrome(string &s, int start, int end){
	while(start<=end){
		if(s[start++]!=s[end--])
			return false;
	}
	return true;
}

int numDecodings(string s) {
	if(s.empty() ||s[0]=='0')
		return 0;
	int n = s.size();
	vector<int> dp(n+1,0);
	dp[0] = 1;
	for(int i=1;i<=s.size();i++){
		dp[i] = (s[i-1]=='0')?0:dp[i-1];
		if(i>1 && (s[i-2]=='1'||(s[i-2]=='2' && s[i-1]<='6')))
			dp[i] += dp[i-2];
	}
	return dp[n];

}

int numDistinct(string s, string t) {
	if(s.size()<t.size()) return 0;
	int n = s.size(), m= t.size();
	vector<long> dp(n+1,0);
	vector<long> dp2(n+1,1);
	for(int i=1;i<=m;i++){
		dp[0] = 0;
		for(int j=1;j<=n;j++){
			dp[j] = dp[j-1]+(s[j-1]==t[i-1])?0:dp2[j-1]; 
		}
		swap(dp,dp2);
	}
	return dp2[n];
}

int minDistance(string word1, string word2) {
	int m = word1.size(), n = word2.size();
	vector<int> dp(n+1,0);
	vector<int> dp2(n+1,0);
	for(int i=1;i<=n;i++)
		dp2[i]=i;
	for(int i=1;i<=m;i++){
		dp[0] = i;
		for(int j=1;j<=n;j++){
			if(word1[i-1]==word2[j-1])
				dp[j] = dp2[j-1];
			else
				dp[j] = min(dp2[j-1],min(dp2[j],dp[j-1]))+1;
		}
		swap(dp,dp2);
	}
	return dp2[n];

}

bool isInterleave(string s1, string s2, string s3){
	int m = s1.size(), n = s2.size(), len = s3.size();
	if(m+n!=len) return false;
	vector<bool> dp(n+1);
	vector<bool> dp2(n+1,true);
	for(int i=1;i<=n;i++){
		dp2[i] = (dp2[i-1] && s2[i-1]==s3[i-1]);
	}
	for(int i=1;i<=m;i++){
		dp[0] = dp2[0] && (s1[i-1]==s3[i-1]);
		for(int j=1;j<=n;j++){
			dp[j] = (dp2[j] && (s1[i-1]==s3[i+j-1])) ||
				(dp[j-1] && (s2[j-1]==s3[i+j-1]));
		}
		swap(dp,dp2);
	}
	return dp2[n];

}

int longestCommonSequence(string &A, string &B){
	int m = A.size(), n = B.size();
	vector<int> dp(n+1,0);
	vector<int> dp2(n+1,0);
	for(int i=1;i<=m;i++){
		for(int j =1;j<=n;j++){
			dp[j] = (A[i-1]==B[j-1])?dp2[j-1]+1:max(dp[j-1],dp2[j]);
		}
		swap(dp,dp2);
	}
	return dp2[n];
}

int lengthOfLIS(vector<int>& nums){
	vector<int> tails;
	tails.push_back(nums[0]);
	for(int num:nums){
		auto pos = upper_bound(tails.begin(),tails.end(),num);// 找到第一个大于的元素-1
		if(pos!=tails.end())
			*pos = num;
		else
			tails.push_back(num);
	}
	return tails.size();

}

int lengthOfLIS(vector<int>& nums){
	vector<int> tails;
	tails.push_back(nums[0]);
	for(int num:nums){
		int start = 0, end = tails.size();
		while(start<end){
			int mid = start+(end-start)/2;
			if(tails[mid]<num) start = mid+1;
			else end = mid;
		}
		if(end!=tails.size())
			tails[end] = num;
		else
			tails.push_back(num);
	}
	return tails.size();
}

int findLength(vector<int>& A, vector<int>& B) {
	int m=A.size(), n=B.size();
	vector<int> dp(n+1,0);
	vector<int> dp2(n+1,0);
	int res =0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[j]=(A[i-1]==B[j-1])?dp2[j-1]+1:0;
			res = max(res,dp[j]);
		}
		swap(dp,dp2);
	}
	return res;

}

int largestRectangleArea(vector<int>& heights) {
	int res = 0;
	int n = heights.size();
	for(int i=0;i<n;i++){
		if(i+1<n && heights[i]<=heights[i+1]) continue;
		int minH = heights[i];
		for(int j =i;j>=0;j--){
			minH = min(minH, heights[j]);
			res = max(res, minH*(j-i+1));
		}
	}
	return res;

}

int maximalRectangle(vector<std::vector<char>> &matrix){
	int m = matrix.size(),n=matrix[0].size();
	vector<int> heights(n,0);
	int res =0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]=='0')
				heights[j] = 0;
			else
				heights[j] +=1;
		}
		res = max(res, largestRectangleArea(heights));
	}
	return res;

}

vector<int> maxSubArray(vector<int>& nums){
	int max_end_here = nums[0];
	int max_so_far = nums[0];
	int start = 0, end = 0;
	int j = 0;
	for(int i =1;i<nums.size();i++){
		if(max_end_here<0){
			max_end_here = 0;
			j = i;
		}
		max_end_here += nums[i];
		if(max_end_here>max_so_far){
			max_so_far = max_end_here;
			start = j;
			end = i;
		}
	}
	return {start,end};
}

string longestPalindrome(string s) {
	string result;
	if(s.empty()) return result;
	int start = 0, maxLen =0;
	for(int i=0;i<s.size();i++){
		for(int j=0;i+j<s.size() && i-j>=0 && s[i+j]==s[i-j];j++){
			if(2*j+1>maxLen){
				start = i-j;
				maxLen = 2*j+1;
			}
		}
		for(int j=0;i+j<s.size() && i-j-1>=0 && s[i+j]==s[i-j-1];j++){
			if(2*j+2>maxLen){
				start =i-j-1;
				maxLen = 2*j+2;
			}
		}
	}
	return s.substr(start,maxLen);
}

int longestPalindromeSubseq(string s) {
	int n=s.size();
	vector<int> dp(n,0);
	vector<int> dp2(n,0);
	for(int i=n-1;i>=0;i--){
		dp[i]=1;
		for(int j=i+1;i<n;i++){
			dp[j] = (s[i]==s[j])?dp2[j-1]+2:max(dp2[j],dp[j-1]);
		}
		swap(dp,dp2);
	}
	return dp2[n-1];

}

int minCut(string & s){
	if(s.empty()) return 0;
	int n = s.size();
	vector<int> dp(n,0);
	vector<vector<bool>> p(n,vector<bool>(n,false));
	for(int i=0;i<n;i++){
		dp[i]=i;
		for(int j=0;j<=i;j++){
			if(s[i]==s[j] ||(i-j<2 && p[j+1][i-1])){
				p[j][i] = true;
				dp[i] = (j==0)?0:min(dp[i],dp[j-1]+1);
			}
		}
	}
	return dp[n-1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m =obstacleGrid.size(),n=obstacleGrid[0].size();
	vector<int> dp(n,0);
	dp[0]=1;
	for(int i=0;i<m;i++){
		dp[0] = (obstacleGrid[i][0]==1)?0:dp[0];
		for(int j=1;j<n;j++){
			dp[j] = (obstacleGrid[i][0]==1)?0:dp[j-1]+dp[j];
		}
	}
	return dp[n-1];

}

int minPathSum(vector<vector<int>>& grid) {
	int m =gird.size(),n=grid[0].size();
	vector<int> dp(n,INT_MAX);
	dp[0]=0;
	for(int i=0;i<m;i++){
		dp[0] += grid[i][0];
		for(int j=1;j<n;j++){
			dp[j] = min(dp[j],dp[j-1])+grid[i][j];
		}
	}
	return dp[n-1];
}

bool wordBreak(string s, vector<string>& wordDict) {
	int n=s.size();
	unordered_set<string> map(wordDict.begin(),wordDict.end());
	vector<bool> dp(n+1,false);
	dp[0] = true;
	for(int i=1;i<=s.size();i++){
		for(int j=0;j<i;j++){
			if(dp[i] && map.count(s.substr(j,i-j))){
				dp[i] = true;
				break;
			}
		}
	}
	return dp[n];

}


vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int,int> map;
	for(int i=0;i<nums.size();i++){
		int res = target - nums[i];
		if(map.find(res)!=map.end()){
			return {map[res],i};
		}
		map[nums[i]] = i;
	}
	return {};

}

vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int>> result;
	sort(num.begin(),num.end());
	for(int i=0;i<num.size();i++){
		int target = -num[i];
		int start = i, end = num.size()-1;
		int sum = num[start]+num[end];
		while(start<end){
			if(sum==target){
				vector<int> triplet(3,0);
				triplet[0]=num[i];
				triplet[1]=num[start];
				triplet[2]=num[end];
				result.push_back(triplet);
			}
			else if(sum<target)
				start++;
			else
				end--;
			while(start<end && num[start]==triplet[1])
				start++;
			while(start<end && num[end]==triplet[2])
				end--;
		}
		if(i+1<num.size() && num[i]==num[i+1])
			i++;
	}
	return result;
}

int partition(vector<int>& nums, int start, int end){
	int left = start, right = end;
	int pivot = nums[right];
	while(left<right){
		while(left<right && nums[left]<pivot)
			left++;
		while(left<right && nums[right]>=pivot)
			right--;
		if(left<right)
			swap(nums[left],nums[right]);
	}
	swap(nums[left],nums[end]);
	return left;
}

int findMedian(vector<int>& nums){
	int k = (nums.size() - 1) >> 1;
	int left =0,right =nums.size()-1;
	while(split!=k){
		int split = partition(nums,left,right);
		if(split==k){
			int result=nums[k];
			break;
		}
		else if(split<k)
			left = split+1;
		else
			right = split-1;
	}
	return result;
}

int MinOfRotateArray(int *arr, int length){
	int start = 0, end = length-1;
	int mid = start; 
	while(arr[start]>=arr[end]){
		if(end-start==1){
			int result = arr[end];
			return result;
		}
		int mid = start+(end-start)/2;
		if(arr[mid]==arr[end] && arr[start]==arr[end])
			return MinOfArray(arr,start,end);
		if(arr[mid]<=arr[end])
			end=mid;
		else
			start=mid;
	}
	return arr[mid];
}

bool SearchInRotateArray2(int* arr, int length, int target){
	if(length<1) return false;
	int start = 0, end = length-1;
	while(start<=end){
		int mid = start+(end-start)/2;
		if(arr[mid]==target) return true;
		if(arr[mid]<arr[end]){
			if(arr[mid]<target && arr[end]>=target)
				left = mid+1;
			else
				right = mid-1;
		}
		else if(arr[mid]>arr[end]){
			if(arr[mid]>target && arr[start]<=target)
				right =mid-1;
			else
				left =mid+1;		
		}
		else
			right--;
	}
	return false;

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size(), n=nums2.size();
	if(m>n) return findMedianSortedArrays(nums2,nums1);

	int imin=0, imax = m;
	int halfLen =(m+n+1)/2;
	int max_of_left =0, min_of_right =0;
	while(imin<=imax){
		int i = (imin+imax)/2;
		int j = halfLen - i;
		if(i>0 && nums1[i-1]>nums2[j])
			imax = i-1;
		else if(i<m && nums1[i]<nums2[j-1])
			imin = i+1;
		else{
			if(i==0) max_of_left = nums2[j-1];
			else if(j==0) max_of_left = nums1[i-1];
			else max_of_left = max(nums1[i-1],nums2[j-1]);
			if((m+n)&1==1) return max_of_left;

			if(i==m) min_of_right = nums2[j];
			else if(j==n) min_of_right = nums1[i];
			else min_of_right = min(nums1[i],nums2[j]);
			return (min_of_right+max_of_left)/2.0;
		}
	}
	return 0;

}

double findTopKofSortedArrays(int* array1, int len1, int* array2, int len2, int k){
	if(len1>len2)
		return findTopKofSortedArrays(array2,len2,array1,len1,k);
	if(len1==0)
		return array2[k-1];
	if(k==1)
		return min(array1[0],array2[0]);
	int k1=min(k/2,len1);
	int k2=k-k1;
	if(array1[k1-1]<array2[k2-1])
		return findTopKofSortedArrays(array1+k1,len1-k1,array2,len2,k-k1);
	else if(array1[k1-1]>array2[k2-1])
		return findTopKofSortedArrays(array1,len1,array2+k2,len2-k2,k-k2);
	else
		return array1[k1-1];
}

int mySqrt(int x) {
	if(x<2) return x;
	int start =0, end =x;
	while(start<end){
		int mid = start+(end-start)/2;
		if(x/mid>=mid)
			left = mid+1;
		else
			right = mid;
	}
	return left -1;

}

ListNode* MergeTwoLists(ListNode* a, ListNode* b){
	if(a==nullptr) return b;
	if(b==nullptr) return a;

	ListNode* result = nullptr;
	if(a->val<b->val){
		result=a;
		result->next=MergeTwoLists(a->next,b);
	}
	else{
		result = b;
		result->next=MergeTwoLists(a,b->next);
	}
	return result;
}

Node* mergeKLists(Node* arr[], int last){

	while(last!=0){
		int i=0,j=last;
		while(i<j){
			arr[i] = mergeKLists(arr[i],arr[j-1]);
			i++,j--;
			if(i>=j)
				last=i;
		}

	}
	return arr[0];

}

ListNode* ReverseList(ListNode* head){
	ListNode* cur = head, *pre = nullptr, *post = nullptr;
	if(cur){
		post = cur->next;
		cur->next = pre;
		pre = cur;
		cur = cur->next;
	}
	return cur;

}

ListNode* detectCircle(ListNode* head){
	if(head==nullptr || head->next==nullptr)
		return nullptr;

	ListNode* fast =head, *slow = head;
	while(fast!=nullptr || fast->next!=nullptr){
		fast=fast->next->next;
		slow =slow->next;
		if(fast==slow){
			ListNode* pNode = head;
			while(pNode!=slow){
				pNode=pNode->next;
				slow=slow->next;
			}
			return pNode;
		}
	}
	return nullptr;
}

TreeNode* ConverBSTtoDoublyLinkList(TreeNode* root){
	if(!root) return nullptr;
	TreeNode* pLast = nullptr
	ConvertCore(root, pLast);

	while(pLast->left!=nullptr)
		pLast= pLast->left;
	return pLast;
}

void ConvertCore(TreeNode* pNode, TreeNode* & pLastNode){
	if(pNode==nullptr) return;

	if(pNode->left!=nullptr)
		ConvertCore(pNode->left,pLastNode);
	if(pLastNode!=nullptr)
		pLastNode->right = pNode;
	pNode->left = pLastNode;
	pLastNode = pNode;
	if(pNode->right!=nullptr)
		ConvertCore(pNode->right,pLastNode);
}

TreeNode* build(vector<int> &inorder, int i,int j,vector<int> &postorder,int ii,int jj){

	if(i>=j || ii>=jj) return nullptr;

	int rootVal = postorder[jj-1];
	auto split = find(inorder.begin()+i,inorder.begin()+j,rootVal);
	int dist = split - inorder.begin();
	TreeNode* root = new TreeNode(rootVal);

	root->left=build(inorder, i,i+dist,postorder,ii,ii+dist);
	root->right =build(inorder,i+dist+1, j,postorder,ii+dist,jj-1);
	return root;

}

TreeNode* build(ListNode*& head,int n){
	if(n<=0) return nullptr;
	TreeNode* left=build(head,n/2);
	TreeNode* root = new TreeNode(head->val);
	root->left = left;
	head=head->next;
	root->right =build(head,n-n/2-1);
	return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode* pNode = root, *pLast = nullptr;
	vector<TreeNode*> pathp,pathq,temp;
	while(pathp.empty() || pathq.empty()){
		if(pNode){
			temp.push_back(pNode);
			if(pNode==p) pathp = temp;
			if(pNode==q) pathq = temp;
			pNode = pNode->left;
		}
		else{
			if(temp.back()->right==nullptr || temp.back()->right==pLast){
				pLast = temp.back();
				temp.pop_back()
			}
			else{
				pNode = temp.back()->right;
			}
		}
	}

}

bool hasPathSum(TreeNode* root, int sum) {
	if(root==nullptr) return false;
	if(root->val == sum && root->left ==nullptr && root->right ==nullptr)
		return true;
	return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right, sum-root->val);

}

void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
	if(node==nullptr) return;
	path.push_back(node);
	if(sum==node->val && !node->left && !node->right){
		paths.push_back(path);
	}
	if(node->left)
		findPaths(node->left,sum-node->val,path,paths);

}

int minDepth(TreeNode* root) {
	if(root==nullptr) return 0;
	if(!root->left && !root->right) return 1;
	if(!root->left) return minDepth(root->right)+1;
	if(!root->right) return minDepth(root->left)+1;
	return min(minDepth(root->left),minDepth(root->right))+1;
}

int minDepth(TreeNode* root){
	if(root=nullptr) return 0;
	queue<TreeNode*> q;
	q.push(root);
	int l =1;
	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			TreeNode* pNode = q.front();
			q.pop();
			if(q->left==nullptr && q->right==nullptr) return l;
			if(q->left) q.push(q->left);
			if(q->right) q.push(q->right);
		}
		l++;
	}
	return 0;

}

void reverseString(string& s, int left, int right){
	while(left<right){
		swap(s[left++],s[right--]);
	}
}

string reverseWordsInString(string s){
	if(s.size()<2) return s;
	int start =0,end =s.size()-1;
	reverseString(s,start,end);
	end = start;

	while(start<s.size()){
		if(s[start]==" ")
			start++,end++;
		else if(end==s.size() || s[end]==" "){
			reverseString(s,start,--end);
			start = ++end;
		}
		else
			end++;
	}
	return s;
}

