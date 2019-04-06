/* 给定两个字符串 s,t 加入 s="rabbbit",t ="rabbit"，求 s 的子串中有多少是 t,例子中显然是3个。
	我们使用 dp[i][j]表示 子串 s[0,...j-1]中有多少 t[0,...i-1]的子串，分两种情况：
	1.若 s[j-1]==t[i-1]，那么 dp[i][j] = dp[i-1][j-1] + dp[i-1][j]，仔细理解这个式子，为什么要加上 dp[i-1][j-1]
	2.若 s[j-1]!=t[i-1]，那么 dp[i][j] = dp[i-1][j]，因为条件已知最后一个字母是无效的。 */

int numDistinct(string s, string t) {
    int n = s.size(),m=t.size();
    if(n<m) return 0;
    
    vector<long> dp(n+1,0); // 
    vector<long> dp2(n+1,1); // i=0 时的边界条件，t为空串 s全为1
    for(int i=1;i<=m;i++){
        dp[0]=0;
        for(int j=1;j<=n;j++){
            dp[j]=dp[j-1]+(s[j-1]==t[i-1]?dp2[j-1]:0);
        }
        swap(dp,dp2);
    }
    return dp2[n];
}