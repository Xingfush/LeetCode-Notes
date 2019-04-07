int maxProfit(vector<int> &prices){
	if(prices.size()<=1)
		return 0;
	int K=2, n = prices.size();
	int maxProfit = 0;
	vector<vector<int> > dp(K+1,vector<int>(n,0)); // k=0是边界条件
	for(int k = 1;k < K;k++){
		int tempMax = dp[k-1][0]-prices[0];
		for(int i=1;i<n;i++){
			dp[k][i] = max(dp[k][i-1],prices[i]+tempMax);
			tempMax = max(tempMax, dp[k-1][i]-prices[i]);
			maxProfit = max(dp[k][i],maxProfit);
		}
	}
	return maxProfit;
}


int maxProfit(int k, vector<int>& prices) {
    if(prices.size()<=1)
        return 0;
    int n = prices.size();
    if(n<=k)
        return maxProfitHelper(prices); // 这个特殊情况很重要，因为这种情况下，动态规划会运行的很慢，达到n^2数量级
    vector<int> dp(n,0);
    for(int i=1;i<=k;i++){
        int temp = dp[0]-prices[0];
        for(int j=1;j<n;j++){
            int dp_temp = dp[j];
            dp[j]=max(dp[j-1],temp+prices[j]); // 更新 dp[j] 使用的是上个 j-1 的最大 max temp
            temp = max(temp,dp_temp-prices[j]); // temp 的更新比 dp[j]要慢，意思就是 temp = dp[i-1,j-1]-prices[j]中的 j始终小于j
        }
    }
    return dp[n-1];
}

int maxProfitHelper(vector<int>& prices){
    int res =0;
    for(int i=1;i<prices.size();i++){
        res+=max(0,prices[i]-prices[i-1]);
    }
    return res;
}