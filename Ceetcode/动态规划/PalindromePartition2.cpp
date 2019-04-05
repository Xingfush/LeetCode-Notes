/* 找出使字符串成为回文子串的最小分割数，题目有点难 */

int minCut(string & s)
{
	if(s.empty()) return 0; // 空字符串默认回文，不用切分
	int n = s.size();
	vector<vector<bool> > p(n, vector<bool>(n));
	vector<int> dp(n);

	for(int i=0;i<n;i++){
		dp[i] = i; // 子串 [0,i]的长度为 i+1，最多需要 i 次切分
		for(int j=0;j<=i;j++){ // 遍历子区间切分点
			if(s[i]==s[j] && (i-j<2 || p[j+1][i-1])) // 动态规划转移方程
			{
				p[j][i] = true;
				dp[i] = (j==0)?0:min(dp[i],dp[j-1]+1); // 最核心的部分
			}
		}
	}
	return dp[n-1];
}

