/* 最基础的0-1背包问题：
有 N 件物品和一个容量为 V 的背包，第 i 件物品的费用为 c[i], 价值为 w[i]
	求解将哪些物品装入背包可以使价值总和最大。
每个物品仅有一件，可以选择放或不放，用子问题定义状态：即 f[i][v] 表示前 i 俭物品放入一个容量为 v
的背包可以获得的最大价值，则其状态转移方程为：
f[i][v] = max{f[i-1][v], f[i-1][v-c[i]] + w[i]}
这个方法的时间复杂度和空间复杂度均为 o(VN)，其中时间复杂度不能再优化，下面优化空间复杂度。
 */

// 价值为 w, 所占体积为 c， 容量限制为 v
int knapsack01(vector<int>& w, vector<int>& c, int v)
{
	assert(w.size()==v.size() && v>=0);

	int n = w.size();
	if(n==0||v==0) return 0;

	// 体积为0是有意义的，必须加上，故为 v+1
	vector<vector<int>> dp(n, vector<int>(v+1,0));
	// 初始化为 第1件物品放入 体积从 0，v的最大价值
	for(int j=0;j<=v;j++)
		dp[0][j] = (j>=c[0]?w[0]:0);

	for(int i=1;i<n;i++){
		for(int j=0;j<=v;j++){
			// 0~1这些物品容积为j的背包所获得的最大价值
			dp[i][j] = dp[i-1][j];
			if(j>=c[i])
				dp[i][j] = max(dp[i][j], w[i]+dp[i-1][j-c[i]]);
		}
	}
	return dp[n-1][v];
}

// 优先使用下面这种解法
// 空间复杂度进行优化，最简单的就是使用两行轮流进行刷新，但是其实可以缩减为一行进行处理
int knapsack01(vector<int>& w, vector<int>& c, int v)
{
	assert(w.size()==v.size() && v>=0);
	int n = w.size();
	if(n==0||v==0) return 0;

	vector<int> dp(v+1,0);

	// 初始所有体积下对于第一个物品的价值，思考这个单独步骤是否必要
	for(int j=0;j<=v;j++)
		dp[j] = (j>=c[0]?w[0]:0);

	for(int i=1;i<n;i++){
		// 变成逆序，可以减少需要遍历次数
		for(int j=v;j>=c[i];j--){
			dp[j] = max(dp[j],w[i]+dp[j-c[i]]);
		}
	}
	return dp[v];
}











