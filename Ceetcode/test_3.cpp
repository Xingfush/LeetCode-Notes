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



