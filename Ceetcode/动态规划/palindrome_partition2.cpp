/* 找出使字符串成为回文子串的最小分割数，题目有点难 */
/* 字符串分割为 [0,j-1],[j,i]两个部分，j从0到i全覆盖 [0,i]的字串 */

int MinimumCutToPalindrome(const string& s){
    if(s.empty()) return 0;
    int n = s.size();
    vector<int> dp(n);
    vector<vector<bool>> p(n,vector<bool>(n));

    for(int i=0;i<n;i++){
        dp[i] = i; // 子串 [0,i]的长度为 i+1，最多需要 i 次切分
        for(int j=0;j<=i;j++){ // 遍历子区间切分点
            if(s[i]==s[j] && (i-j<2 || p[j+1][i-1])){ // 动态规划转移方程
                p[j][i] = true;
                dp[i] = (j==0?0:min(dp[i], dp[j-1]+1)); // 最核心的部分
            }
        }
    }

    return dp[n-1];
}