/* 给定正整数 n，找到若干个完全平方数（比如1,4,9,16..)使得它们的和等于 n。
你需要让组成和的完全平方数的个数最少。
这题本质上就是 coinchanges，j是硬币，i是需要凑出的金额 */

int NumSquares(int n){
	vector<int> dp(n+1, INT_MAX);
	for(int i=1;i*i<=n;i++)
		dp[i*i] = 1;
	for(int i=1;i<n;i++){
		for(int j=1;i+j*j<n;j++){
			dp[i+j*j] = min(dp[i+j*j],dp[i]+1);
		}
	}

	return dp[n];
}
