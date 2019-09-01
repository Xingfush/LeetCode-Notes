int lower_bound(vector<int>& nums, int key){
	int start = 0, end = nums.size();
	while(start<end){
		int mid = start+(end-start)/2;
		if(nums[mid]<key) left = mid+1;
		else right = mid;
	}
	return left;
}

int findMedian(vector<int>& nums){
	int start = 0, end = nums.size()-1;
	int k = (nums.size()-1)/2;
	while(true){
		int q = partition(nums,start,end);
		if(q==k){
			return nums[q];
		}
		else if(q<k)
			start = q+1;
		else
			end = q-1;
	}
	return 0;
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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size(), n = nums2.size();
	int imin = 0, imax = n;
	int halfLen = (m+n+1)/2;
	int max_of_left = 0, min_of_right = 0;
	while(imin<=imax){
		int i = (imin+imax)/2;
		int j = halfLen - i;
		if(i>0 && nums1[i-1]>nums2[j])
			imax = i-1;
		else if(i<m && nums2[j-1]>nums2[i])
			imin = i+1;
		else{
			if(i==0) max_of_left = nums2[j-1];
			else if(j==0) max_of_left = nums1[i-1];
			else max_of_left = max(nums1[i-1],nums2[j-1]);

			if((m+n) & 1) return max_of_left;

			if(i==m) min_of_right = nums2[j];
			else if(j==n) min_of_right = nums1[i];
			else min_of_right = min(nums1[i],nums2[j]);

			return (max_of_left+min_of_right)/2.0;
		}
	}
	return 0.0;
}

double findTopKofSortedArrays(int* array1, int len1, int* array2, int len2, int k){
	if(len1>len2) return findTopKofSortedArrays(array2,len2,array1,len1,k);
	if(len1==0) return array2[k-1];
	if(k==1) return min(array1[0],array2[0]);

	int k1 = min(k/2,len1);
	int k2 = k-k1;
	if(array1[k1-1]>array2[k2-1])
		return findTopKofSortedArrays(array1,len1,array2+k2,len2-k2,k-k2);
	else if(array1[k1-1]<array2[k2-1])
		return findTopKofSortedArrays(array1+k1,len1-k1,array2,len2,k-k1);
	else
		return array1[k1];

}

int MinOfRotateArray(int *arr, int length){
	int left = 0, right = length-1;
	int mid = 0;
	while(arr[left]>=arr[right]){
		if(right-left==1){
			mid = right;
			return mid;
		}
		int mid = (left+right)/2;
		if(arr[left]==arr[mid] && arr[mid]==arr[right]){
			return minOrder(int *arr, int left, int right);
		}
		if(arr[mid]<=arr[right])
			right = mid;
		else
			left = mid;
	}
	return arr[mid];
}

int kthSmallest(vector<vector<int>>& matrix, int k){
	int m = matrix.size(), n = matrix[0].size();
	int left = matrix[0][0], right = matrix[m-1][n-1];
	while(left<right){
		int mid = left + (right-left)/2;
		int sum = 0;
		for(int i=0;i<m;i++){
			int num = upper_bound(matrix[i].begin(),matrix.end(),mid);
			sum+= num;
		}
		if(sum<k)
			left = mid +1;
		else
			right = mid;
	}
	return left;
}

TreeNode* Convert(TreeNode* root){
	TreeNode* LastNode = nullptr;
	ConvertCore(root,LastNode);
	while(LastNode && LastNode->left){
		LastNode = LastNode->left;
	}
	return LastNode;
}

void ConvertCore(TreeNode* root, TreeNode*& LastNode){
	if(root ==nullptr) return;
	ConvertCore(root->left, LastNode);
	root->left = LastNode;
	if(LastNode)
		LastNode->right=root;
	LastNode = root;
	ConvertCore(root->right, LastNode);
}

int maxDiameter(TreeNode* root){
	int res = 0;
	helper(root, res);
	return res;
}

int helper(TreeNode* root, int& res){
	if(root==nullptr) return 0;
	int left = helper(root->left, res);
	int right = helper(root->right, res);
	res = max(res, left+right+1);
	return max(left+right)+1;
}

vector<int> ans;
map<TreeNode*, TreeNode*> parents;
set<TreeNode*> visited;

void findParents(TreeNode* root){
	if(root==nullptr) return;
	if(root->left)
		parents[root->left] = root;
	if(root->right)
		parents[root->right] = root;
	findParents(root->left);
	findParents(root->right);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K){
	findParents(root);
	dfs(target, K);
	return ans;	
}

void dfs(TreeNode* target, int K){
	if(visited[target]) return;
	visited.insert(target);
	if(K==0){
		ans.push_back(target);
		return;
	}
	if(target->left)
		dfs(target->left,K-1);
	if(target->right)
		dfs(target->right,K-1);
	if(parents[target])
		dfs(parents[target],K-1);
}

vector<string> binaryTreePaths(TreeNode* root) {
	if(root==nullptr) return {""};
	vector<string> res;
	dfs(TreeNode* root, res, to_string(root->val));
	return res;
}

void dfs(TreeNode* root, vector<string>& res, string & path){
	if(!root->left && !root->right){
		res.push_back(path);
		return;
	}
	if(root->left)
		dfs(root->left, res, path+"->"+to_string(root->val));
	if(root->right)
		dfs(root->right, res, path+"->"+to_string(root->val));
}

bool isValidBST(TreeNode* root) {
	long mn = LONG_MIN, mx = LONG_MAX;
	return dfs(root, mn, mx);
}

bool dfs(TreeNode* root, int mn, int mx){
	if(root==nullptr) return true;
	if(root>=mx || root<=mn) return false;
	return dfs(root->left, mn, root->val) && dfs(root->right, root->val, mx);
}

bool isValidBST(TreeNode* root){
	TreeNode* node = root, pLast = nullptr;
	stack<TreeNode*> s;
	while(node || !s.empty()){
		if(node){
			s.push(node);
			node = node->left;
		}
		else{
			if(pLast && pLast->val>=s.top()->val) return false;
			node = s.top()->right;
			pLast = s.top();
			s.pop();
		}
	}
	return true;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode* pNode = root, *pLast = nullptr;
	vector<TreeNode*> temp, pathp, pathq;
	while(pathq.empty() || pathp.empty()){
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
	int n = min(pathp.size(),pathq.size());
	for(int i=0;i<n;i++){
		if(pathp[i]==pathq[i])
			pNode = pathp[i];
	}
	return pNode;
}

int LongestConsecutiveTreeNode(TreeNode* root){
	if(root==nullptr) return 0;
	int res = 0;
	dfs(root, res, 0, 0);
	return res;
}

void dfs(TreeNode* root, int& res, int v, int out){
	if(root==nullptr) return;
	if(root->val == v+1) out++;
	else out =1;
	res = max(res, out);
	dfs(root->left, res, root->val, out);
	dfs(root->right, res, root->val, out);
}

int minDepth(TreeNode* root) {
	if(root==nullptr) return 0;
	queue<TreeNode*> q;
	q.push(root);
	int l=0;
	while(!q.empty()){
		int k = q.size();
		l++;
		for(int i=0;i<k;i++){
			TreeNode* pNode = q.front();
			q.pop();
			if(!pNode->left && !pNode->right) return l;
			if(pNode->left) q.push(pNode->left);
			if(pNode->right) q.push(pNode->right);
		}
	}
	return l;
}

bool isPostOrder(vector<int>& nums) {
	return dfs(nums, 0, nums.size()-1);
}

bool dfs(vector<int>& nums, int start, int end){// 左闭右闭
	if(start>=end) return true;
	int k = nums[end];
	int i= start;
	for(;i<end;i++){
		if(nums[i]>k) break;
	}
	for(int j=i;j<end;j++){
		if(nums[j]<=k) return false;
	}
	return dfs(nums,start,i-1) && dfs(nums, i, end-1);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
	vector<vector<int>> res;
	vector<int> path;
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	s1.push(root);
	while(!s1.empty() && !s2.empty()){
		while(!s1.empty()){
			TreeNode* pNode = s1.top();
			s1.pop();
			path.push_back(pNode->val);
			if(pNode->left) s2.push(pNode->left);
			if(pNode->right) s2.push(pNode->right);
		}
		if(!path.empty()) res.push(path);
		path.clear();
		while(!s2.empty()){
			TreeNode* pNode = s2.top();
			s2.pop();
			path.push_back(pNode->val);
			if(pNode->right) s1.push(pNode->right);
			if(pNode->left) s1.push(pNode->left);
		}
		if(!path.empty()) res.push(path);
		path.clear();
	}
	return res;
}

void bfs(int s, vector<vector<int>> G){
	int n = G.size();
	queue<int> q;
	q.push(s);
	vector<bool> visited(n,false);
	visited[s] = true;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		cout<<temp<<" ";
		for(int i=0;i<n;i++){
			if(!visited[i] && G[temp][i]!=INF){
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void Dijkstra2(int s, vector<vector<int>> G){
	int n = G.size();
	vector<int> dist(n,INT_MAX);
	vector<bool> visited(n,false);
	priority_queue<int,int> q;
	dist[s] = 0;
	q.push(make_pair<int,int>(-dist[s],s));
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		visited[u] =true;
		for(int i=0;i<n;i++){
			if(!visited[i] && G[u][i]+d[u]<d[i]){
				d[i] = G[u][i] +d[u];
				q.push(make_pair<int,int>(-d[i],i));
			}
		}
	}
}

vector<int> getIndegrees(graph& g){
	int n = g.size();
	vector<int> indegrees(n,0);
	for(auto adj:g){
		for(int v:adj){
			indegrees[v]++;
		}
	}
	return indegrees;
}

bool topologicalSort(graph& g){
	int n = g.size();
	vector<int> indegrees = getIndegrees(g);
	queue<int> q;
	int count =0;
	for(int i=0;i<n;i++){
		if(indegrees[i]==0) q.push(i);
	}
	while(q.empty()){
		int temp = q.top();
		q.pop();
		cout<<temp<<" ";
		count++;
		for(int i=0;i<n;i++){
			if((--indegrees[i])==0)
				q.push(i);
		}
	}
	return (count==n)?true:false;
}










