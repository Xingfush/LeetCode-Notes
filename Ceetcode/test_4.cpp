#include<set>
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
	vector<double> res;
	multiset<double> ms(nums.begin(),nums.begin()+k);
	auto mid = next(ms.begin(),k/2);
	for(int i=0;;i++){
		res.push_back((*mid+*pre(mid,1-k%2))/2);
		if(i==nums.size()) return res;
		if(nums[i]<*mid) --mid;
		if(nums[i-k]<=*mid) ++mid;
		ms.erase(ms.lower_bound(nums[i-k]));
	}
	return res;

}

#include<queue>
vector<int> maxSlidingWindow(vector<int> & nums, int k){
	vector<int> res;
	deque<int> q;
	for(int i=0;i<nums.size();i++){
		if(!q.empty() && q.front()==i-k) q.pop_front();
		while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
		q.push(nums[i]);
		if(i>=k-1)
			res.push_back(nums[q.front()]);
	}
	return res;

}

int findPeakElement(vector<int>& nums) {
	int left = 0, right = nums.size()-1;
	while(left<right){
		int mid = left+(right-left)/2;
		if(nums[mid]<nums[mid+1]) left = mid+1;
		else right= mid;
	}
	return left;

}

int findPeakElement(vector<int>& nums){
	for(int i=1;i<nums.size();i++){
		if(nums[i]<nums[i-1])
			return nums[i-1];
	}
	return nums[nums.size()-1];
}

vector<int> findPeak2D(vector<vector<int>> & matrix){
	int n = matrix.size();
	int top = 1, bottom = n-2;
	vector<int> result;
	while(top<=bottom){
		int mid = (top+bottom)/2;
		int col = findPeakElement(matrix[mid]);
		if(matrix[mid][col]<matrix[mid+1][col]) top = mid+1;
		else if(matrix[mid][col]<matrix[mid-1][col]) bottom = mid-1;
		else{
			result.push_back(mid);
			result.push_back(col);
			return result;
		}
	}
}

int majorityElement(vector<int>& nums) {
	int count = 1, candidate = nums[0];
	for(int i=1;i<nums.size();i++){
		nums[i]==candidate?count++:count--;
		if(count==0){
			candidate = nums[i];
			count = 1;
		}
	}
	count = 0;
	for(int i=0;i<nums.size();i++){
		if(candidate==nums[i]) count++;
	}
	if(count>nums.size()/2) return candidate;
}

int majorityElement(vector<int>& nums){
	int count_a = 0, count_b = 0;
	int a =0, b=0;
	for(auto num:nums){
		if(num==a) count_a++;
		else if(num==b) count_b++;
		else{
			if(count_a==0){
				count_a=1;
				a = num;
			}
			else if(count_b==0){
				count_b=1;
				a = num;
			}
			else{
				count_a--,count_b--;
			}
		}
	}
	count_a = 0,count_b=0;
	for(auto num:nums){
		if(num==a) count_a++;
		else if(num==b) count_b++;
	}
	vector<int> result;
	if(count_a>n/3) result.push_back(a);
	if(count_b>n/3) result.push_back(b);
	return result;
}

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i;j++){
			swap(matrix[i][j],matrix[n-1-i][n-1-j]);
		}
	}
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n;j++){
			swap(matrix[i][j],matrix[n-1-i][j]);
		}
	}
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if(matrix.size()==0||matrix[0].size()==0) return false;
	int m = matrix.size(),n=matrix[0].size();
	int i=0,j=n-1;
	while(i<m && j>=0){
		if(matrix[i][j]==target) return true;
		else if(matrix[i][j]<target) i++;
		else{
			int start = 0, end = j;
			while(start<end){
				int mid = start+(end-start)/2;
				if(matrix[i][mid]<=target) start = mid+1;
				else end = mid;
			}
			j = end-1;
		}
	}
	return false;

}

bool searchMatrix(vector<vector<int> > &matrix, int target){
	if(matrix.size()==0||matrix[0].size()==0) return false;
	int m = matrix.size(),n=matrix[0].size();
	int start=0 , end = m*n;
	while(start<end){
		int mid = start+(end-start)/2;
		int value = matrix([mid/n][mid%n]);
		if(value==target) return true;
		else if(value<target) left = mid+1;
		else right = mid;
	}
	return false;
}

int kthSmallest(vector<vector<int>>& matrix, int k)
{
	int n = matrix[0].size;
	int start = matrix[0][0], end = matrix[n-1][n-1]
	while(start<end){
		int mid = start+(end-start)/2;
		int count=0;
		for(int i=0;i<n;i++){
			int pos = upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
			count += pos;
		}
		if(count<k) left = mid+1;
		else right = mid; 
	}
	return start;
}

bool hasPathSum(TreeNode* root, int sum) {
	if(root==nullptr) return false;
	if(!root->left && !root->right && root->val = sum) return true;
	return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<int> path;
	vector<vector<int>> res;
	pathSumCore(root,sum,path,res);
	return res;
}

void pathSumCore(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res){
	if(root==nullptr) return;
	path.push_back(root->val);
	if(!root->left && !root->right && root->val ==sum){
		res.push_back(path);
		return;
	}
	pathSumCore(root->left,sum-root->val,path,res);
	pathSumCore(root->right,sum-root->val,path,res);
	path.pop_back();
}

void pathSumCore(TreeNode* root, int sum, int & res){
	if(root==nullptr) return;
	sum += root->val;
	if(!root->left && !root->right && sum>res){
		res = sum;
		return;
	}
	pathSumCore(root->left,sum,res);
	pathSumCore(root->right,sum,res);
	sum -= root->val;
}

int pathSum(TreeNode* root, int sum){
	if(root==nullptr) return 0;
	return pathSum(root->left,sum)+pathSum(root->right,sum)+pathSumFromRoot(root,sum);
}

int pathSumFromRoot(TreeNode* root,int sum){
	if(root==nullptr) return 0;
	int res = (root->val==sum)?1:0;
	return res+pathSumFromRoot(root->left,sum-root->val)+pathSumFromRoot(root->right,sum-root->val);
}

TreeNode* Convert(TreeNode* root){
	if(root==nullptr) return nullptr;
	TreeNode* pLast = nullptr;
	ConvertCore(root, pLast);
	while(pLast && pLast->left){
		pLast = pLast->left;
	}
	return pLast;
}

void ConvertCore(TreeNode* root, TreeNode*& pLast){
	if(root==nullptr) return;
	ConvertCore(root->left,pLast);
	root->left = pLast;
	if(pLast)
		pLast->right = root;
	pLast = root;
	ConvertCore(root->right,pLast);
}

TreeNode* getKthTreeNode(TreeNode* root, int &k) {
	if(root==nullptr) return nullptr;
	TreeNode* result = getKthTreeNode(root->left,k);
	if(!result){
		if(k==1)
			return result=root;
		k--;
	}
	if(!result)
		result = getKthTreeNode(root->right,k);
}

TreeNode* getMedian(TreeNode* root){
	if(root==nullptr) return;
	stack<TreeNode*> st;
	vector<int> nodes;
	TreeNode* pNode= root;
	while(!st.empty() || pNode){
		if(pNode){
			st.push(pNode);
			pNode = pNode->left;
		}
		else{
			TreeNode* temp = st.top();
			st.pop();
			nodes.push_back(temp->val);
			pNode = temp->right;
		}
	}
	int n = node.size();
	if(n & 1==1)
		return nodes[n/2];

}

void flatten(TreeNode* root) {
	if(root==nullptr) return;
	flatten(root->left);
	flatten(root->right);
	TreeNode* temp = root->right;
	root->right = root->left;
	root->left =nullptr;
	while(root->right)
		root = root->right;
	root->right = temp;
}

TreeNode* getInorderSuccessor(TreeNode* pNode){
	if(pNode->right){
		TreeNode* temp = pNode->right;
		while(temp->left)
			temp = temp->left;
		return temp;
	}
	TreeNode* pParent = pNode->parent;
	while(pParent && pParent->left!=pNode){
		pNode = pParent;
		pParent = pParent->parent;
	}
	return pParent;
}

bool result = true;
bool isBalanced(TreeNode* root){
	dfs(root);
	return result;
}

int dfs(TreeNode* root){
	if(root==nullptr) return 0;
	int leftLen = dfs(root->left);
	int rightLen = dfs(root->right);
	if(abs(leftLen-rightLen)>1) return false;
	return max(leftLen,rightLen)+1;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
	if(!p && !q) return true;
	if(!p || !q) return false;
	return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

}

bool isSubtree(TreeNode* s, TreeNode* t) {
	if(!s) return false;
	if(isSameTree(s,t)) return true;
	return isSubtree(s->left,t) || isSubtree(s->right,t);

}

bool isSymmetric(TreeNode* root)
{
	if(root==nullptr) return true;
	return isSymmetric(root->left,root->right)
}

bool isSymmetric(TreeNode* root)
{
	if(root==nullptr) return true;
	queue<TreeNode*> l,r;
	l.push(root->left);
	r.push(root->right);
	while(!l.empty() && !r.empty()){
		TreeNode* lNode = l.back();
		TreeNode* rNode = r.back();
		l.pop();
		r.pop();
		if(!l && !r) continue;
		if(!l || !r) return false;
		if(!l->val != !r->val) return false;
		l.push(l->left);
		l.push(l->right);
		r.push(r->right);
		r.push(r->left);
	}
	return true;
}

bool isValidBST(TreeNode* root) {
	if(root==nullptr) return true;
	stack<TreeNode*> s;
	TreeNode* pNode=root,pLast = nullptr;
	while(!s.empty()||pNode){
		if(pNode){
			s.push(pNode);
			pNode=pNode->left;
		}
		else{
			TreeNode* temp = s.top();
			s.pop();
			if(pLast && pLast->val>temp->val)
				return false;
			pLast = temp;
			pNode = temp->right;
		}
	}
	return true;

}

bool isValidBST(TreeNode* root, long mn, long mx) {
	if(!root) return true;
	if(root->val<mn || root->val>mx) return false;
	return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(!root || !p ||!q) return nullptr;
	if(p->val>q->val)
		return lowestCommonAncestor(root,q,p);
	TreeNode* pNode = root;
	while(pNode){
		if(pNode->val>q->val)
			pNode = pNode->left;
		else if(pNode->val<p->val)
			pNode = pNode->right;
		else
			return 
	}

}

void getNodePath(TreeNode* root, TreeNode* pNode,vector<TreeNode*> &path, bool &found){
	if(root==nullptr) return;
	path.push_back(root);
	if(root==pNode) found = true;
	if(!found)
		getNodePath(root->left,pNode,path,found);
	if(!found)
		getNodePath(root->right,pNode,path,found);
	if(!found)
		path.pop_back(root);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(!root || !p ||!q) return nullptr;
	vector<TreeNode*> pathp,pathq;
	bool found = false;
	getNodePath(root,p,pathp,found);
	found = false;
	getNodePath(root,q,pathq,found);
	TreeNode* pLast = nullptr;
	for(auto iter1=pathp.begin(),iter2=pathq.begin();iter1!=pathp.end()&&iter2!=pathq.end();iter1++,iter2++)
	{
		if(*iter1==*iter2)
			pLast = *iter1;
	}
	return pLast;
}

void preOrderTraverse(TreeNode* root, int v, int out, int & res){
	if(root==nullptr) return;
	if(root->val == v+1) 
		out++;
	else
		out=1;
	res = max(res,out);
	preOrderTraverse(root->left,root->val,out,res);
	preOrderTraverse(root->right,root->val,out,res);
}

int LongestConsecutiveTreeNode(TreeNode* root)
{
	if(root==nullptr) return 0;
	int res =0;
	preOrderTraverse(root,0,0,res);
	return res;
}

int maxDepth(TreeNode *root){
	return (root==nullptr)?0:max(maxDepth(root->left),maxDepth(root->right))+1;
}

int minDepth(TreeNode *root){
	if(root==nullptr) return 0;
	if(!root->left && !root->right) return 1;
	if(!root->left) return 1+minDepth(root->right);
	if(!root->right) return 1+minDepth(root->left);
	return min(minDepth(root->left),minDepth(root->right))+1;
}

TreeNode* buildBST(iter b,iter e){
	if(b>=e) return nullptr;
	auto mid = b +(e-b)/2;
	TreeNode* root = new TreeNode(*mid);
	root->left = buildBST(b,mid);
	root->right = buildBST(mid+1,e);
	return root;
}

TreeNode* buildBSTbuild(ListNode*& head,int n){
	if(n<=0) return nullptr;
	TreeNode* left = buildBSTbuild(head,n/2);
	TreeNode* root = new TreeNode(head->val);
	root->left = root;
	head = head->next;
	root->right = buildBSTbuild(head,n-n/2-1);
	return root;
}

ListNode* detectCircle(ListNode* head){
	if(head==nullptr && head->next==nullptr) return nullptr;
	ListNode* fast=head, *slow=head;
	ListNode* temp=head;
	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow){
			while(temp!=slow){
				temp=temp->next;
				slow=slow->next;
			}
			return slow;
		}
	}
	return nullptr;
}

ListNode* FindKthToTail(ListNode* head, unsigned int k){
	ListNode* slow = head, *fast = head;
	for(;k>1;k--){
		if(fast->next)
			fast = fast->next;
		else
			return nullptr;
	}
	while(fast->next){
		fast=fast->next;
		slow=slow->next;
	}
	return slow;
}

int count(ListNode* head){
	return head?1+count(head->next):0;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if(headA==nullptr || headB==nullptr) return nullptr;
	int lenA = count(headA);
	int lenB = count(headB);
	if(lenA<lenB)
		return getIntersectionNode(headB,headA);
	int diff = lenA - lenB;
	for(int i=0;i<diff;i++)
		headA = headA->next;
	
	while(headA && headB){
		if(headA==headB)
			return headA;
	}
	return nullptr;

}

ListNode* SortedMerge(ListNode* a, ListNode* b){
	if(a==nullptr) return b;
	if(b==nullptr) return a;

	ListNode* pNode=nullptr;
	if(a->val<b->val){
		pNode=a;
		pNode->next = SortedMerge(a->next,b);
	}
	else{
		pNode = b;
		pNode->next = SortedMerge(a,b->next);
	}
	return pNode;
}

ListNode* mergeKLists(vector<ListNode*> &lists){
	priority_queue<ListNode*,vector<ListNode*>,mycompare> q;
	for(auto l:lists){
		if(l) q.push(l);
	}
	if(q.empty()) return nullptr;
	ListNode* head = q.top();
	q.pop();
	if(head->next)
		q.push(head->next);
	ListNode* tail = head;
	while(!q.empty()){
		tail->next=q.top();
		q.pop();
		tail=tail->next;
		if(tail->next)
			q.push(tail->next);
	}
	return head;
}

char* ReverseSentence(char* strings){
	if(strings==nullptr) return nullptr;
	char* start = strings, *end = strings;
	while(*end!='\0')
		end++;
	end--;
	ReverseString(start,end);
	end=start;
	while(*start!='\0'){
		if(*start==' ')
			start++,end++;
		else if(*end==' '|| *end=='\0'){
			ReverseString(start,--end);
			start=++end;
		}
		else
			end++;
	}
	return strings;

}

int partition(int* array, int start, int end){
	int left = start, right = end;
	int pivot = array[end];
	while(left<right){
		while(left<right && array[left]<pivot)
			left++;
		while(left<right && array[right]>=pivot)
			right--;
		if(left<right)
			swap(array[left],array[right]);
	}
	swap(array[left],array[end])
	return left;
}

void QuickSort(int* array,int start, int end){
	if(start<end){
		int k = partition(array, start,end);
		QuickSort(array,start,k-1);
		QuickSort(array,k+1,end);
	}
}

int MinOfRotateArray(int *arr, int length){
	int start = 0, end = length-1;
	int mid = start;
	while(arr[start]>=arr[end]){
		if(end-start==1){
			mid=end;
			break;
		}
		int mid = (start + end)/2;
		if(arr[mid]==arr[start] && arr[start]==arr[end]){
			int result=arr[start];
			for(int i=start;i<end;i++){
				if(arr[i]<result) result=arr[i];
			}
			return result;
		}
		if(arr[mid]<=arr[end])
			end=mid;
		else
			start=mid;
	}
	return arr[mid];
}

int maxProfit(vector<int> &prices) {
	if(prices.size()<2) return 0;
	int minPrice = prices[0];
	int maxProfit = prices[1]-prices[0];
	for(int i=2;i<prices.size();i++){
		minPrice = min(minPrice,prices[i-1]);
		maxProfit = max(maxProfit,prices[i]-minPrice);
	}
	return maxProfit;
}




