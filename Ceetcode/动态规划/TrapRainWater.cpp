int trap(vector<int> & height){
	int res = 0, mx = 0, n= height.size();
	vector<int> dp(n,0);
	for(int i=0;i<n;i++){
		dp[i] = mx;
		mx = max(mx, height[i]);
	}
	mx = 0;
	for(int i=n-1;i>=0;i--){
		dp[i] = min(dp[i],mx);
		mx = max(mx, height[i]);
		if(dp[i]>height[i])
			res += dp[i] - height[i];
	}
	return res;
}