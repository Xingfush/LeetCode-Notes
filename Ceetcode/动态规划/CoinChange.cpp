/* 背包问题的又一延伸，动态规划的遍历方式相同 */

int coinChange(vector<int>& coins, int amount)
{
	int max = amout + 1;
	vector<int> dp(amount+1, max);
	dp[0] = 0;

	for(int i=1;i<=amount;i++){
		for(int j=0;j<coins.size();j++){
			if(coins[j]<=i)
				dp[i] = min(dp[i], dp[i-coins[j]]+1);
		}
	}

	return dp[amount]>amount?-1:dp[amount];
}

/* 这里一定要明白这道题的动态规划和背包问题是不一样的，
这里的硬币可以重用比如 [2,5,1] 凑 12，5可以用两次 5+5+1，
而如果当作背包问题来看的话，是凑不了 12 的。
动态规划的求解顺序体现了这种不同：
对同样的amount，内层用 coins.size()循环表示 coins可以复用 */

/* 要是硬币不可以复用，那么这个问题更加的普遍 */

int coinChange(vector<int>& coins, int amount)
{
	int max = amount + 1;
	vector<int> dp(amount+1, max);
	dp[0] = 0;

	for(int i=0;i<coins.size();i++){
		for(int j=amount;j>=coins[i];j--){
			dp[j] = min(dp[j], dp[j-coins[i]]+1);
		}
	}

	return dp[amount]>amount?-1:dp[amount];
}

