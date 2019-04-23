/* 背水一战，Microsoft, I am coming. */
vector<vector<int>> combine(int n, int k) {
	vector<int> out;
	vector<vector<int>> res;
	dfs(n,1,k,out,res);
	return res;
}

void dfs(int n, int ind, int k, vector<int>& out, vector<vector<int>>& res){
	if(out.size()==k){
		res.push_back(out);
		return;
	}
	for(int i=ind;i<=n;i++){
		out.push_back(i);
		dfs(n, i+1, k, out, res);
		out.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int> & candidates, int target){
	sort(candidates.begin(),candidates.end());
	vector<int> combination;
	vector<vector<int>> res;


}

void dfs(vector<int>& candidates, int ind, int target, vector<int>& combination,
	vector<vector<int>>& res){
	if(target == 0){
		res.push_back(combination);
		return;
	}
	for(int i=ind;i<candidates.size() && target>=candidates[i];i++){
		if(i==ind || candidates[i]==candidates[i-1]){
			combination.push_back(candidates[i]);
			dfs(candidates,i+1,target-candidates[i],combination,res);
			combination.pop_back();
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	vector<int> path;
	vector<vector<int>> res;
	vector<bool> visited(nums.size(),false);

}

void dfs(vector<int>&nums, vector<int>& path, vector<vector<int>>& res, vector<bool>& visited){
	if(path.size()==nums.size()){
		res.push_back(path);
		return;
	}
	for(int i=0;i<nums.size();i++){
		if(visited[i]) continue;
		if(i>0 && !visited[i-1] && nums[i]==nums[i-1]) continue;
		visited[i]=true;
		path.push_back(nums[i]);
		dfs(nums,path,res,visited);
		path.pop_back();
		visited[i]=false;
	}
}

bool hasPath(char* matrix, int rows, int cols, char*str){
	if(matrix==nullptr || rows<1 || cols<1 || str==nullptr) return false;
	vector<vector<bool>> visited(rows,vector<bool>(cols,false));
	int len = 0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
		if(dfs(matrix,i,j,rows,cols,str,0,visited))
			return true;
		}
	}
	return false;
}

bool dfs(char* matrix, int i, int j, int m, int n, char* str, int len ,vector<vector<bool>>& visited){
	// 收敛条件
	if(str[len]=='\0') return true;
	// 判别准入
	if(i>=0 && i<m && j>0 && j<n && !visited[i][j] && str[len]==matrix[i][j]){
		visited[i][j] = true;
		bool hasPath = dfs(matrix,i+1,j,m,n,str,len+1,visited) ||
		dfs(matrix,i-1,j,m,n,str,len+1,visited)||
		dfs(matrix,i,j+1,m,n,str,len+1,visited)||
		dfs(matrix,i,j-1,m,n,str,len+1,visited);
		if(!hasPath){
			visited[i][j] = false;
		}
	}
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
	if(matrix.empty() || matrix[0].empty()) return 0;
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> dp(m,vector<int>(n,0));
	int res = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			res = max(res, dfs(matrix, i, j, dp));
		}
	}
	return res;
}

int dfs(vector<vector<int>>& matrix, int i, int j,vector<vector<int>> &dp){
	// 缓存加速
	if(dp[i][j]>0) return dp[i][j];
	int res = 1;
	if(i>0 && matrix[i][j]>matrix[i-1][j]) res = max(res, dfs(matrix, i-1, j, dp));
	if(i<m-1 && matrix[i][j]>matrix[i+1][j]) res = max(res, dfs(matrix, i+1, j, dp));
	if(j>0 && matrix[i][j]>matrix[i][j-1]) res = max(res, dfs(matrix, i, j-1, dp));
	if(j<n-1 && matrix[i][j]>matrix[i][j+1]) res = max(res, dfs(matrix, i, j+1, dp));
	dp[i][j] = res;
	return dp[i][j];
}

int count(int threshold, int m, int n, int i, int j, vector<vector<bool>>& visited){
	int count = 0;
	if(check(threshold,m,n,i,j,visited)){
		visited[i][j] = true;
		count + = 1 + count(threshold,m,n,i+1,j,visited)
			 + count(threshold,m,n,i-1,j,visited)
			 + count(threshold,m,n,i,j+1,visited)
			 + count(threshold,m,n,i,j-1,visited);
	}
}

int movingCount(int threshold, int rows, int cols){
	if(threshold<0 || rows<1 || cols<1) return 0;
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	int res = count()
}

int getDigitSum(int member){
	int sum = 0;
	while(member){
		sum += member%10;
		member /= 10;
	}
	return sum;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	if(grid.empty() || grid[0].empty()) return 0;
	int m = grid.size(), n = grid[0].size();
	int res = 0;
	vector<vector<bool>> visited(m, vector<bool>(n,false));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			res = max(res, dfs());
		}
	}
	return res;
}

int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> & visited){
	int count = 0;
	if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() 
		&& !visited[i][j] && grid[i][j]==1)
	{
		visited[i][j] = true;
		count += 1 + dfs(grid, i+1, j, visited) + dfs(grid, i-1, j, visited)
					+ dfs(grid, i, j+1, visited) + dfs(grid, i, j-1, visited); 
	}
	return count;
}

vector<vector<string>> partition(string s){
	vector<vector<string>> res;
	if(s.empty()) return res;
	vector<string> path;
	dfs(s, 0, path, res);
	return res;
}

void dfs(string& s, int ind, vector<string>& path, vector<vector<string>>& res){
	if(ind ==s.size()){
		res.push_back(path);
		return;
	}
	for(int i=ind;i<s.size();i++){
		if(isPalindrome(string& s, int ind, int i)){
			path.push_back(s.substr(ind, i-ind+1));
			dfs(s, i+1, path, res);
			path.pop_back();
		}
	}
}

bool isPalindrome(string& s, int start, int end){
	while(start<end){
		if(s[start++]!=s[end--]) return false;
	}
	return true;
}

int maxProfit(vector<int> &prices) {
	if(prices.size()<2) return -1;
	int minPrice = prices[0];
	int profit = prices[1]-prices[0];
	for(int i=2;i<prices.size();i++){
		minPrice = min(minPrice, prices[i-1]);
		profit = max(profit, prices[i]-minPrice);
	}
	return profit;
}

int maxProfit(int k, vector<int>& prices) {
	if(prices.size()<2) return 0;
	int n = prices.size();
	if(n<k)
		return maxProfitHelper(prices);
	vector<int> dp(n,0);
	for(int j=1;j<=k;j++){
		temp = dp[0] - prices[0];
		for(int i=1;i<n;i++){
			dp_temp = dp[i];
			dp[i] = max(dp[i-1], temp+prices[i]);
			temp = max(temp, dp_temp-prices[i]);
		}
	}
	return dp[n-1];
}

int maxProfitHelper(vector<int>& prices){
	int profit = 0;
	for(int i=1;i<prices.size();i++){
		profit += max(0,prices[i]-prices[i-1]);
	}
	return profit;
}

int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();
	int res = 0;
	for(int i=0;i<n;i++){
		if(i+1<n && heights[i]<=heights[i+1]) continue;
		int minH = heights[i];
		for(int j=i;j>=0;j--){
			minH = min(heights[j],minH);
			res = max(minH*(i-j+1),res);
		}
	}
	return res;
}

int maximalRectangle(vector<std::vector<char>> &matrix){
	int m=matrix.size(), n= matrix[0].size();
	vector<int> heights(n,0);
	int res=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			heights[j] = (matrix[i][j]=='1')?heights[j]+1:0;
		}
		res = max(res, largestRectangleArea(heights));
	}
	return res;
}

int maximalRectangle(vector<vector<char> > & matrix){
	if(matrix.empty() || matrix[0].empty()) return 0;
	int m = matrix.size(), n = matrix[0].size();
	vector<int> left(n,0), right(n,n), high(n,0);
	int res = 0;
	for(int i=0;i<m;i++){
		int cur_left = 0, cur_right = n;
		for(int j=0;j<n;j++){
			high[j]=(matrix[i][j]=='0')?0:high[j]+1;
		}
		for(int j=0;j<n;j++){
			if(matrix[i][j]=='0'){
				left[j] = 0;
				cur_left = j+1;
			}
			else{
				left[j] = max(left[j],cur_left);
			}
		}
		for(int j=n-1;j>=0;j--){
			if(matrix[i][j]=='0'){
				right[j] = n;
				cur_right = j; // 这里是 cur_right = j 而不是 cur_right =j-1，就体现了左闭右开的思想
			}
			else{
				right[j] = min(right[j],cur_right);
			}
		}
		for(int j=0;j<n;j++){
			res = max(res, (right[j]-left[j])*high[j]);
		}
	}
	return res;

}

int maximalSquare(vector<vector<char>>& matrix) {
	int m = matrix.size(), n= matrix[0].size();
	vector<int> dp(n+1,0),dp2(n+1,0);
	int res = 0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[j]=(matrix[i-1][j-1]=='0')?0:min(dp[j-1],min(dp2[j],dp2[j-1]))+1;
			res = max(res, dp[j]);
		}
		swap(dp,dp2);
		fill(dp.begin(),dp.end(),0);
	}
	return res*res;
}

int findTargetSumWays(vector<int>& nums, int S) {
	int n = nums.size();
	unordered_map<int,int> dp2;
	dp2[0] = 1;
	for(int num:nums){
		unordered_map<int,int> dp;
		for(auto a:dp2){
			int sum = a.first, cnt = a.second;
			dp[sum+num] += cnt;
			dp[sum-num] += cnt;
		}
		dp2 = dp;
	}
	return dp2[S];
}

bool wordBreak(string s, vector<string>& wordDict) {
	int n = s.size();
	unordered_set<string> map(wordDict.begin(),wordDict.end());
	vector<bool> dp(n+1,false);
	dp[0] = true;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(dp[j] && map.count(s.substr(j,i-j))){
				dp[i] = true;
				break; 
			}
		}
	}
	return dp[n];
}

vector<string> wordBreak(string s,vector<string>& wordDict){
	unordered_map<string,vector<string>> map;
	helper();
	return map[s];
}

vector<string> helper(string s, vector<string>& wordDict, unordered_map<string,vector<string>>& m){
	// 缓存加速
	if(m.count(s)) return m[s];
	// 终止条件
	if(s.empty()) return {""};
	vector<string> res;
	for(string word:wordDict){
		if(s.substr(0,word.size())!=word) continue;
		vector<string> rem = helper(s.substr(word.size()),wordDict,m);
		for(string &str:rem){
			res.push_back(word+(str.empty())?"":" "+str); 
		}
	}
	return res;

}

int countSubstrings(string s) {
	int res =0;
	int n = s.size();
	for(int i=0;i<n;i++){
		for(int j=0;i-j>=0 && i+j<n && s[i-j]==s[i+j];j++){
			res++；
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;i-j-1>=0 && i+j<n && s[i-j-1]==s[i+j];j++){
			res++；
		}
	}
	return res;
}

int longestPalindromeSubstring(string s) {
	int n = s.size();
	vector<vector<bool>> dp(n,vector<bool>(n,false));
	int start = 0, len = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(s[i]==s[j] && (i-j<2 || dp[j+1][i-1])){
				dp[j][i] = true;
				if(i-j+1>len){
					len = i-j+1;
					start = j;
				}
			}
		}
	}
	return s.substr(start,len);
}

int longestPalindromeSubseq(string s) {
	int n = s.size();
	vector<int> dp(n,0),dp2(n,0);
	for(int i=n-1;i>=0;i--){
		dp[i] = 1;
		for(int j=i+1;j<n;j++){
			dp[j] = (s[i]==s[j])?dp2[j-1]+2:max(dp[j-1],dp2[j]);
		}
		swap(dp,dp2);
	}
	return dp2[n-1];
}

int minCut(string & s)
{
	int n = s.size();
	vector<vector<bool>> p(n,vector<bool>(n,false));
	vector<int> dp(n);
	for(int i=0;i<n;i++){
		dp[i] = i;
		for(int j=0;j<=i;j++){
			if(s[i]==s[j] || (i-j<2 || p[j+1][i-1])){
				p[j][i] = true;
				dp[i] = (j==0)?0:min(dp[i],dp[j-1]+1);
			}
		}
	}
	return dp[n-1];
}

int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size(), n= grid.size();
	vector<int> dp(n,INT_MAX);
	dp[0] = 0;
	for(int i=0;i<m;i++){
		dp[0] += grid[i][0];
		for(int j=1;j<n;j++){
			dp[j] = min(dp[j-1],dp[j])+grid[i][j];
		}
	}
	return dp[n-1];
}

int majorityElement(vector<int>& nums) {
	int count = 1;
	int candidate = nums[0];
	for(int i=1;i<nums.size();i++){
		(candidate==nums[i])?count++:count--;
		if(count==0){
			candidate = nums[i];
			count=1;
		}
	}
	count =0;
	for(int i=0;i<nums.size();i++){
		if(nums[i]==candidate) count++;
	}
	return candidate;
}

vector<int> majorityElement(vector<int>& nums) {
	int count_a = 0, count_b = 0;
	int a = 0, b= 0;
	for(int num:nums){
		if(num==a) count_a++;
		else if(num==b) count_b++;
		else{
			if(count_a==0){
				a = num;
				count_a = 1;
			}
			else if(count_b==0){
				b = num;
				count_b = 1;
			}
			else{
				count_a--, count_b--;
			}
		}
	}
	count_a =0, count_b=0;
}

int findPeakElement(vector<int>& nums) {
	int left =0, right = nums.size();
	while(left<right){
		int mid = left+(right-left)/2;
		if(nums[mid]<nums[mid+1])
			left = mid+1;
		else
			right = mid;
	}
	return left;
}

vector<int> findPeak2D(vector<vector<int>> & matrix){
	int top=1, bottom = matrix.size()-2;
	while(top<=bottom){
		int mid = (top+bottom)/2;
		int col = findPeakElement(matrix[mid]);
		if(matrix[mid][col]<matrix[mid+1][col])
			top = mid+1;
		else if(matrix[mid][col]<matrix[mid-1][col])
			bottom = mid-1;
		else{

		}
	}
}

void rotate(vector<vector<int>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			swap(matrix[i][j],matrix[n-1-j][n-1-i]);
		}
	}
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n;j++){
			swap(matrix[i][j],matrix[n-1-i][j]);
		}
	}
}

int InversePairsCore(int* data, int* copy, int start, int end){
	if(end-start<=1){
		copy[start] = data[start];
		return 0;
	}
	int mid = start +(end-start)/2;
	int left = InversePairsCore(copy,data,start,mid);
	int right = InversePairsCore(copy,data,mid,end);

	int count = 0;
	int i=start, j=mid, k = start;
	while(i<mid && j<end){
		if(data[i]>data[j]){
			count += mid-i;
			copy[k++] = data[j++];
		}
		else
			copy[k++] = data[i++];
	}
	while(i<mid)
		copy[k++] = data[i++];
	while(j<end)
		copy[k++] = data[j++];
	return count +left+right;
}

int numMatchingSubseq(string S, vector<string>& words) {
	unordered_map<char,vector<int>> map;
	int n = S.size();
	for(int i=0;i<n;i++) 
		map[S[i]].push_back(i);
	int res=0;
	for(string word:words){
		res ++;
		pre = -1;
		for(char c:word){
			auto ind = upper_bound(map[c].begin(),map[c].end(),pre);
			if(ind==map[c].end()){
				res--;
				break;
			}
			pre = *ind;
		}
	}
	return res;
}

string decodeString(string s) {
	int n = s.size();
	stack<int> st_cnt;
	stack<string> st_str;
	int cnt = 0;
	string str;
	for(int i=0;i<n;i++){
		if(isdigit(s[i]))
			cnt = cnt*10 +s[i];
		else if(s[i]=='['){
			st_cnt.push_back(cnt);
			st_str.push_back(str);
			cnt = 0;
			str.clear();
		}
		else if(s[i]==']'){
			int k = st_cnt.top();
			st_cnt.pop();
			for(int j=0;j<k;j++)
				st_str.top() += str;
			str = st_str.top();
			st_str.pop();
		}
		else
			str += s[i];
	}
}

void ReverseString(char* start, char* end){
	while(start<end){
		swap(*start++,*end--);
	}
}

char* ReverseSentence(char* strings){
	char* start = strings, *end = strings;
	while(*end!='\0')
		end++;
	end--;
	ReverseString(start,end);
	end = strings;
	while(*start!='\0'){
		if(*start==' ')
			start++,end++;
		else if(*end==' ' || *end=='\0'){
			ReverseString(start,--end);
			start = ++end;
		}
		else
			end++;
	}
	return strings;
}

vector<int> maxSlidingWindow(vector<int> & nums, int k){
	vector<int> res;
	deque<int> q;
	for(int i=0;i<nums.sie();i++){
		if(!q.empty() && q.front()==i-k) q.pop_front();
		while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
		q.push_back(i);
		if(i>=k-1){
			res.push_back(nums[q.front()]);
		}
	}
	return res;

}

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
	vector<double> res;
	multiset<double> ms(nums.begin(),nums.begin()+k);
	auto mid = next(nums.begin(), k/2);
	for(int i=k;;i++){
		res.push_back((*mid+*prev(mid,1-k%2))/2);
		if(i==nums.size()) return res;
		ms.insert(nums[i]);
		if(nums[i]<*mid) --mid;
		if(nums[i-k]<=*mid) ++mid;
		ms.erase(ms.lower_bound(nums[i-k]));
	}
}

