/* 给定一个严格递增的数组，求这个数组能构成斐波那契数组的最长子序列 */
/* 使用动态规划进行求解：dp[a,b]代表以(a,b)结束的fibo sequence的长度，
	dp[a,b]= dp[b-a,a]+1 or 2 */

int LongestFibonacciSubsequence(const vector<int>& nums){
    unordered_map<int,int> map;
    int n = nums.size(), res = 0;
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        map[nums[i]] = i; // 永远是 i先行，因此 m[nums[i]] = i 不用单独先赋值
        for(int j=0;j<i;j++){ // j<i 而不是 j<=i, 因此最少有两个元素
        	// 判断其差是否为数组中的元素，这种是否存在的问题，优先用哈希表
            int k = (map.find(nums[i]-nums[j])==map.end()?-1:map[nums[i]-nums[j]]);
            dp[j][i] = (nums[i]-nums[j]<nums[j] && k>=0)?dp[k][j]+1:2;
            res = max(dp[j][i],res);
        }
    }

    return res>2?res:0;
}

/* 本题思考：
1.和最长递增子序列相似，但是斐波那契数列的判断稍复杂，但是解的结构依然满足
最优子问题结构，这里子问题的划分需要用 哈希表 来判断；
2.查找存在性的问题，使用哈希表，这是必备的解题思路。
3.重要的判别条件： nums[j]-nums[i]<nums[i]，
  这个条件很重要，因为 nums[j]-nums[i]，很可能是小于 nums[i]的
  此时我们的假设，即 nums[i] 是斐波那契第二项就是不成立的，所以必须要判断 */

