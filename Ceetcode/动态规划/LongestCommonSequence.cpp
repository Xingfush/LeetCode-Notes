/* 最长公共子序列：经典的动态规划题目，时常复习，解法经典 */
/* 下面是测试通过的案例 */

int longestCommonSequence(string &A, string &B) {
	int m = A.size(), n = B.size();
	if (m < n)
		return longestCommonSequence(B, A); // 保证有最小的空间复杂度

	vector<int> dp(n + 1, 0);
	vector<int> dp2(n + 1, 0);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			dp[j] = (A[i - 1] == B[j - 1]) ? dp2[j - 1] + 1 : max(dp[j - 1], dp2[j]);
		}
		swap(dp, dp2);
	}
	return dp2[n];
}

