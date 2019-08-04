vector<int> maxSubarray(vector<int>& nums)
{
	if(nums.empty()) return {};
	int start = 0, end = 0; // 返回结果，跟随 max_so_far
	int j = 0; // j 是游标，跟随 max_end_here
	int max_end_here = nums[0];
	int max_so_far = nums[0];
	for(int i=1;i<nums.size();i++)
	{
		if(max_end_here<0){
			max_end_here = 0;
			j = i;
		}
		max_end_here = max_end_here + nums[i];
		if(max_end_here>max_so_far){
			max_so_far = max_end_here;
			start = j;
			end = i;
		}
	}
}

/* 最小编辑距离：初始条件+状态转移
   另外注意：编辑距离是对称的，对称的，对称的！！！ */

int MinDistance(string& word1, string& word2)
{
	int m = word1.size(), n = word2.size();
	vector<int> dp(n+1,0);
	vector<int> dp2(n+1,0);
	for(int i=0;i<n+1;i++)
		dp2[i] = i; // dp2 代表上一个行
	for(int i=1;i<=m;i++){
		dp[0] = i;
		for(int j=1;j<=n;j++){
			if(word1[i-1]==word2[j-1])
				dp[j] = dp2[j-1];
			else
				dp[j] = min(dp2[j-1],min(dp[j-1],dp2[j]))+1;
		}
		swap(dp,dp2);
	}
	return dp2[n];
}

/* 最长公共最序列 */
int LongestCommonSequence(string& str1, string& str2)
{
	int m = str1.size(), n = str2.size();
	
	vector<int> dp(n+1,0);
	vector<int> dp2(n+1,0);
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			dp[j] = (str1[i-1]==str2[j-1])?dp2[j-1] + 1 : max(dp2[j],dp[j-1]);
		}
		swap(dp,dp2);
	}
	return dp2[n];
}

/* 最长上升子序列 */
int LongestIncreasingSequence(vector<int>& nums)
{
	if(nums.empty())
		return 0;

	vector<int> tailTable;
	tailTable.push_back(nums[0]);
	for(int i=1;i<nums.size();i++){
		auto j = lower_bound(tailTable.begin(),tailTable.end(),num);
		if(j==tailTable.end())
			tailTable.push_back(nums[i]);
		else{
			*j=nums[i]; // 注意迭代器的使用
		}
	}
	return tailTable.size();
}

/* Unique paths：从左上到右下有多少种不同的走法 */
int uniquePaths(int m, int n)
{
	vector<int> dp(n,1); // 这样初始化就够了，上边和左边都是1 中走法，用 1初始化
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			dp[i] = dp[i-1] + dp[i];
		}
	}
	return dp[n-1];
}

/* 题目升级：方格中有阻碍 */
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	if(obstacleGrid.empty() || obstacleGrid[0].empty)
		return 0;
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector<long> dp(n,0);// 第0行
	for(int i=0;i<m;i++){
		dp[0] = obstacleGrid[i][0]==1?0:dp[0]; // 很关键啊
		for(int j=1;j<n;j++){
			dp[j] = obstacleGrid[i][j]==1?0:dp[j-1]+dp[j];
		}
	}
	return dp[n-1];
}


/* 题目：最长回文字串
   dp 表示 [j,i] 区间是否为 回文串
   要点在于 i-j<2 && s[j]==s[i] 巧妙地处理了 i==j, i+1=j 两种情况，如此优雅，叹为观止  */
string LongestPalindrome(string& s)
{
	string result;
	if(s.empty())
		return result;

	int start = 0, maxLen = 0;
	int n = s.size();
	vector<vector<bool>> dp(n, vector<bool>(n));

	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(s[j]==s[i] && (i-j<2 || dp[j+1][i-1])){
				dp[j][i] = true;
				if(j-i+1>maxLen){
					start = j;
					maxLen = i-j+1;
				}
			}
		}
	}

	return s.substr(start,maxLen);
}

/* 题目：最长回文子序列
   dp[j][i] = dp[j+1][i-1]+2 or max(dp[j+1][i],dp[j][i-1]) */
int LongestPalindromeSubsequence(string& s)
{
	int n = s.size();
	vector<int> dp(n,0);
	vector<int> dp2(n,0);
	for(int i=n-1;i>=0;i--){
		dp[i] = 1;
		for(int j=i+1;j<n;j++){
			dp[j] = (s[i]==s[j])?dp2[j-1]+2:max(dp[j-1],dp2[j]);
		}
		swap(dp,dp2);
	}
	return dp2[n-1];
}

/* 题目：找出所有回文子串的个数 */
int CountOfPalindromeSubstrings(string & s)
{
	if(s.empty()) return 1;
	int n = s.size();
	int res = 0;
	vector<vector<bool>> dp(n,vector<bool>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(s[i]==s[j] && (i-j<2 || dp[j+1][i-1])){
				dp[j][i] = true;
				res++;
			}
		}
	}
	return res;
}

int MaxProfit(vector<int>& prices){
	if(prices.size()<2)
		return 0;
	int minPrice = prices[0];
	int profit = prices[1] - prices[0]; // 使用前两天先初始化 minPrice 和 profit
	for(int i=2;i<prices.size();i++){
		minPrice = min(prices[i-1],minPrice);
		profit = max(profit, prices[i]-minPrice);
	}
	return max(profit,0);
}

int MaxProfit(vector<int>& prices)
{
	int result;
	for(int i=1;i<prices.size();i++){
		int profit = max(prices[i]-prices[i-1], 0);
		result += profit;
	}
	return result;
}

/* 最多交易k 次的利润 */
int MaxProfit(vector<int>& prices, int k)
{
	if(prices.size()<=1)
		return 0;

	int n = prices.size();
	if(n<=k)
		return MaxProfitHelper(prices);

	vector<int> dp(n,0);
	for(int i=1;i<=k;i++){
		int temp = dp[0]-prices[0]; // 从零开始，第1天买，第 j天卖，所以后面的 j从 1就行了
		for(int j=1;j<n;j++){
			int dp_temp = dp[j];
			dp[j] = max(dp[j-1], temp + prices[j]);
			temp = max(temp, dp_temp-prices[j]);
		}		
	}
}
/* dp[k,j] = max(dp[k,j-1], max_i(dp[k-1, i] + prices[j] - prices[i]))
   这里的 i 满足 i>=0, i<j，即 j天卖，i天买
   代码中我们只用了一个 dp 数组，然而需要遍历找出 max_i(dp[k-1,i] - prices[i])
   所以我们用了 dp_temp 变量，同时由于 先更新 dp[j]，即新的 dp[k,j]
   然后才使用 temp = max(temp, dp_temp-prices[j]) 找到最佳 temp，所以可以保证 i<j */


ListNode* DetectCircle(ListNode* head)
{
	if(head==nullptr || head->next==nullptr)
		return nullptr;
	ListNode* slow = head, *fast = head;
	ListNode* entry = head;
	while(fast!=nullptr && fast->next!=nullptr){
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow){
			while(entry!=slow){
				slow = slow->next;
				entry = entry->next;
			}
			return entry;
		}
	}
	return nullptr;
}


ListNode* FindKthToTail(ListNode* head, int k)
{
	if(head==nullptr || k==0)
		return nullptr;

	ListNode* fast = head, *slow = head;
	for(int i=0;i<k-1;i++){
		if(fast->next!=nullptr)
			fast = fast->next;
		else
			return nullptr;
	}

	while(fast->next!=nullptr){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int count(ListNode* head){
	return head?count(head->next):0;
}

ListNode* IntersectionOfLists(ListNode* head1, ListNode* head2)
{
	if(head1==nullptr || head2==nullptr)
		return nullptr;

	int len1 = count(head1), len2 = count(head2);

	if(len1>len2){
		int diff = len1-len2;
		for(int i=0;i<diff;i++)
			head1 = head1->next;
	}
	else{
		int diff = len2 - len1;
		for(int i=0;i<diff;i++)
			head2 = head2->next;
	}

	while(head1 && head2){
		if(head1==head2)
			return head1;
		head1 = head1->next;
		head2 = head2->next;
	}

	return nullptr;
}

ListNode* MergeTwoSortedLists(ListNode* head1, ListNode* head2)
{
	if(head1==nullptr)
		return head2;
	if(head2==nullptr)
		return head1;

	ListNode* result = nullptr;
	if(head1->val<head2->val){
		result = head1;
		result->next = MergeTwoSortedLists(head1->next, head2);
	}
	else{
		result = head2;
		result->next = MergeTwoSortedLists(head1, head2->next);
	}

	return result;
}

ListNode* MergeKSortedLists(ListNode* arr[], int n)
{
	while(n!=1){
		int i=0, j=n-1;
		while(i<j){
			arr[i] = MergeTwoSortedLists(arr[i],arr[j]);
			i++,j--;
			if(i>=j)
				n = j+1;
		}
	}
	return arr[0];
}

struct compare{
	bool operator()(const ListNode* l1, const ListNode* l2){
		return l1->val>l2->val; // 建立一个最小堆，因为 C++ 默认建立最大堆，因此需要自己定义一个比较函数
	}
}

ListNode* MergeKSortedLists(vector<ListNode*>& lists)
{
	priority_queue<ListNode*, vector<ListNode*>, compare> q;
	for(auto l:lists){
		if(l) q.push(l);
	}
	if(q.empty())
		return nullptr;
	ListNode* result = q.top();
	q.pop();
	if(result->next)
		q.push(result->next);
	ListNode* tail = result;
	while(!q.empty()){
		tail->next = q.top();
		q.pop();
		tail = tail->next;
		if(tail->next)
			q.push(tail->next);
	}
	return result;
}

/* 调整链表：左边的元素都小于 x ，右边的元素都大于 x */
ListNode* partition(ListNode* head, int x)
{
	ListNode* left = new ListNode(0);
	ListNode* right = new ListNode(0);
	ListNode* l = left, *r = right;
	while(head){
		if(head->val<x){
			l->next = head;
			l = l->next;
		}
		else{
			r->next = head;
			r = r->next;
		}
	}
	l->next = right->next;
	r->next = nullptr;
	head = left->next;
	delete left;
	delete right;
	return head;
}

/* 反转链表 */
ListNode* ReverseList(ListNode* head)
{
	ListNode* cur = head, *pre = nullptr, *post = nullptr;
	while(cur){
		post = cur->next;
		cur->next = pre;
		pre = cur;
		cur = post;
	}
	return head;
}

/* 链表排序
   1.快慢指针寻找中点；
   2.使用pre 来分子链表，也就是 slow 的前一个节点，进行链表切分；
   3.两个有序链表的合并，这个已经很熟了 */
ListNode* SortList(ListNode* head)
{
	if(head==nullptr || head->next==nullptr)
		return head;
	ListNode* slow = head, *fast = head, *pre = head;
	while(fast && fast->next){
		pre = slow;
		fast = fast->next->next;
		slow = slow->next;
	}
	pre->next = nullptr;
	return MergeTwoSortedLists(SortList(head),SortList(slow));
}

/* 删除一个节点，主要是考虑头结点被删除如何处理，这里使用 伪头结点法 */
ListNode* RemoveListNode(ListNode* head, int key)
{
	if(head==nullptr)
		return nullptr;
	ListNode* front = new ListNode(0);
	front->next = head;
	ListNode* pre = front, *cur = head;

	while(cur)
	{
		if(cur->val==key){
			ListNode* temp = cur;
			pre->next = cur->next;
			cur = pre->next;
			delete temp; // 删除结点时，一定要释放内存，防止内存泄漏
		}
		else{
			pre = cur;
			cur = cur->next;
		}
	}
	return front->next;
}

/* 删除链表中的重复结点 */
ListNode* RemoveDuplicate(ListNode* head)
{
	if(head==nullptr || head->next==nullptr)
		return head;

	ListNode* cur = head->next, * pre = front;
	while(cur)
	{
		if(cur->val==pre->val){
			ListNode* temp = cur;
			pre->next = cur->next;
			cur = cur->next;
			delete temp;
		}
		else{
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}

/* 链表结点两两交换：1->2->3->4 交换为 2->1->4->3 */
ListNode* SwapPairs(ListNode* head)
{
	ListNode* front = new ListNode(0);
	front->next = head;
	ListNode* pre = front;
	while(head && head->next){
		pre->next = head->next;
		head->next = head->next->next;
		pre->next->next = head->next;
		pre = head;
		head = head->next;
	}
	head = front->next;
	delete front;
	return head;
}

/* 稀疏矩阵的乘法 */
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B)
{
	if(A.empty() || A[0].empty() || B.empty() || B[0].empty() || 
											A[0].size()!=B.size())
		throw "matrix can not be empty.";
	
	vector<vector<int>> C(A.size(),vector<int>(B[0].size()));
	for(int i=0;i<A.size();i++){
		for(int k=0;k<A[0].size();++k){
			if(A[i][k]!=0){
				for(int j=0;j<B[0].size();j++){
					if(B[k][j]!=0)
						C[i][j] += A[i][k]*B[k][j];
				}
			}
		}
	}
	return C;
}

/* 其实这里先对 A 的行遍历，然后遍历 A 的列，然后遍历 B 的列，也是可以的，只是和我们平时
   理解的矩阵乘法顺序不太一样，重点是需要在 A的列，也就是B的行累计，res[i][j]++ */

/* 旋转矩阵 */

void rotate(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			swap(matrix[i][j],matrix[n-j-1][n-i-1]);
		}
	}
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n;j++){
			swap(matrix[i][j],matrix[n-i-1][j]);
		}
	}
}

/* 奇偶对换 */

vector<int> ReorderOddEven(vector<int> nums)
{
	if(nums.empty())
		return {};
	int left = 0, right = nums.size()-1;
	while(left<right)
	{
		while(left<right && nums[left] & 0x1 ==1)
			left++;
		while(left<right && nums[right] & 0x1 ==0)
			right++;
		if(left<right)
			swap(nums[left], nums[right]);
	}
	return nums;
}

int BinarySearch(int* array, int left, int right, int key)
{
	while(left<right)
	{
		int mid = left + (right-left)/2;
		if(array[mid] <= key)
			left = mid + 1;
		else
			right = mid;
	}
	return right;
}

void Heapify(int* array, int n, int i)
{
	int largest = i;
	int left = 2*i+1, right = 2*i+2;
	if(left<n && array[left]>array[largest])
		largest = left;
	if(right<n && array[right]>array[largest])
		largest = right;
	if(largest!=i){
		swap(array[largest],array[i]);
		Heapify(array, n, largest);
	}
}

void Siftup(int* array, int i)
{
	int key = array[i];
	while(i>0)
	{
		int parent = (i-1)/2;
		if(key<array[parent])
			break;
		else{
			array[i] = array[parent];
			i = parent;
		}
	}
	array[i] = value;
}

void HeapSort(int* array, int n)
{
	for(int i=n/2;i>=0;i--){
		Heapify(array, n, i);
	}
	for(int i=n;i>0;i++){
		swap(array[0],array[n-1]);
		Heapify(array, n-1, 0);		                                               
	}

}

int kthSmallest(vector<vector<int>>& matrix, int k)
{
	int n = matrix.size();
	int left = matrix[0][0], right = matrix[n-1][n-1];
	while(left<right)
	{
		mid = left + (right-left)/2;
		int num = 0;
		for(int i=0;i<n;i++)
		{
			num += upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
		}
		if(num<k)
			left = mid+1;
		else
			right = mid;
	}
	return left;
}

void randomShuffle(int* array, int n)
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		int temp = rand() %(n-i) + i;
		if(temp!=i)
			swap(array[temp],array[i]);
	}
}

double myPow(double x, int n)
{
	double res = 1.0;
	for(int i=n;i!=0;i/=2){
		if(i%2!=0)
			res *= x;
		x *= x;
	}
	return n<0?1/res:res;
}

vector<int> findPeak2D(vector<vector<int>> & matrix)
{
	int top = 1, bottom = matrix.size()-2;
	vector<int> result;
	while(top<=bottom)
	{
		int m = (bottom+top)/2; // 二分定行
		int col = findPeak1D(matrix,m); // 一维定列
		if(matrix[m][col]<matrix[m-1][col])
			bottom = m-1;
		else if(matrix[m][col]<matrix[m+1][col])
			top = m+1;
		else{
			result.push_back(m);
			result.push_back(col);
			return result;
		}
	}
	return result;
}

int findPeak1D(vector<vector<int>>& matrix, int m)
{
	int start = 0, end = matrix[m].size() - 1;
	while(start<end) // start=end 结束时剩下一个元素就够了
	{
		int mid = start + (end-start)/2;
		if(matrix[m][start]<matrix[m][mid])
			mid = start +1;
		else 
			mid = end;
	}
	return start;
}

int majorityElement(vector<int>& nums)
{
	int counter = 1;
	int majorInd = 0;
	for(int i=1;i<nums.size();i++){
		nums[i]==nums[majorInd]?counter++:counter--;
		if(counter==0){
			majorInd =i;
			counter = 1;
		}
	}
	return nums[majorInd];
}

int InversePairs(int* data, int* copy, int* start, int* end)
{
	if(end-start<=1){// 左闭右开，元素数目小于2{
		copy[start] = data[start];
		return 0;// 没有逆序对
	}
	int mid = start + (end-start)/2;

	int leftPairs = InversePairs(copy, data, start, mid);
	int rightPairs = InversePairs(copy, data, mid, end);

	int i = start, j = mid;
	int copyInd = start;
	int count =0;

	while(i<mid && j <end)
	{
		if(data[i]>data[j]){
			count += middle -i;
			copy[copyInd++] = data[j++];
		}
		else
			copy[copyInd++] = data[i++];
	}
	while(i<mid)
		copy[copyInd++] = data[i++];
	while(j<end)
		copy[copyInd++] = data[j++];

	return count + leftPairs + rightPairs;
}

int InversePairs(int* data, int length)
{
	if(data==nullptr || length<=1)
		return 0;
	int *copy = new int[length];
	for(int i=0;i<length;i++)
		copy[i]= data[i];
	int count = InversePairs(data, copy, 0, length);
	delete [] copy;

	return count;
}

/*矩阵最长上升字串 */
int longestIncresingPath(vector<vector<int>> & matrix)
{
	if(matrix.empty() || matrix[0].empty())
		return 0;
	rows = matrix.size();
	cols = matrix[0].size();
	int res = 0;
	dp = vector<int>(rows, vector<int>(cols,0));
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			res = max(res, dfs(matrix, i, j));
		}
	}
	return res;
}

/* 设置全局变量 */
int rows ,cols;
vector<vector<int>> dp;

int dfs(vector<vector<int>>& matrix, int i, int j)
{
	if(dp[i][j]>0) 
		return dp[i][j]; // 已访问，作剪枝
	int res = 1;
	if(i>0 && matrix[i][j]>matrix[i-1][j]) // 终止条件和扩张方向合在一起 
		res = max(res, dfs(matrix, i-1, j)+1);
	if(i<rows-1 && matrix[i][j]>maxtrix[i+1][j]) 
		res = max(res, dfs(matrix, i+1, j)+1);
	if(j>0 && matrix[i][j]>maxtrix[i][j-1])
		res = max(res, dfs(matrix, i, j-1)+1);
	if(j<cols-1 && matrix[i][j]>matrix[i][j+1])
		res = max(res, dfs(matrix, i, j+1)+1);
	dp[i][j] = res; // 四个方向遍历完之后才最作为该位置的 dp，下一次剪枝，状态更新
	return res;
}

/* 这个问题没有收敛条件 */

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if(matrix==nullptr || rows<=0 || cols<=0 || str==nullptr)
		return false;
	bool* visited = new bool[rows*cols];
	memset(visited, sizeof(bool)*rows*cols);
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(dfs(matrix))
				return true;
		}
	}
	return false;
}

bool dfs(char* matrix, int rows, int cols, int i, int j, char* str, 
								int length, bool* visited)
{
	if(str[length]=='\0')
		return true; // 收敛条件
	bool hasPath = false;
	if(i>=0 && i<m && j>0 && j<=n && !visited[i*cols+j] &&
									str[length]==matrix[i*cols+j])
	{
		length++;
		visited[i*cols+j] = true;

		hasPath = dfs(matrix, rows, cols, i+1, j, str, length, visited)
		|| dfs(matrix, rows, cols, i-1, j, str, length, visited)
		|| dfs(matrix, rows, cols, i, j+1, str, length, visited)
		|| dfs(matrix, rows, cols, i, j-1, str, length, visited);

		if(hasPath){
			length--;
			visited[i*n+j]
		}
	}
	return hasPath;
}

int longestIncresingPath(vector<vector<int>>& matrix)
{
	if(matrix.empty() || matrix[0].empty()) return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	int res = 0;
	vector<vector<int>> dp = vector<int>(m, vector<int>(n,0));

	return res;
}

int dfs(vector<vector<int>>& matrix, int m, int n, int i, int j,
						vector<vector<int>>& dp)
{
	if(dp[i][j]>0)
		return dp[i][j];
	int res = 1;
	if(i>0 && matrix[i][j]>matrix[i-1][j])
		res = max(res, dfs(matrix, m, n, i-1, j, dp));
	if(i<m-1 && matrix[i][j]>matrix[i+1[j]])
		res = max(res, dfs(matrix, m, n, i+1, j, dp));
	if(j>0 && matrix[i][j]>matrix[i][j-1])
		res = max(res, dfs(matrix, m, n, i, j-1, dp));
	if(j<n-1 && matrix[i][j]>matrix[i][j+1])
		res = max(res, dfs(matrix, m, n, i, j+1, dp));
	dp[i][j] = res;
	return res;
}


