/* 问题1：找出所有的回文子串的个数 */
/* 使用中心扩展法，时间复杂度同样是O(n^2)，空间复杂度甚至达到了常数，非常好的一个解法，面试优先 */
// 解法1：
int countSubstrings(string s) {
    int n=s.size();
    int res =0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;i-j>=0 && i+j<n && s[i-j]==s[i+j];j++) // 以 i为中心,判断 [i-j,i+j]
            res++;
        for(int j=0;i-j-1>=0 &&i+j<n && s[i-j-1]==s[i+j];j++) // 以(i-1,i)为中心，判断 [i-j-1,i+j]
            res++;
    }
    return res;
    
}

/* 使用动态规划，不过扩展方向有点不同 */
// 解法2：
int countSubstrings(string s) {
    if(s.empty()) return 1;
    int n=s.size();
    int res=0;
    vector<vector<bool> > dp(n,vector<bool>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(s[i]==s[j] && (i-j<2 || dp[j+1][i-1]))
            {
                dp[j][i]=true;
                res++;
            }
        }
    }
    return res;
}


/* 问题2：找出最长回文子串 */
// 使用中心扩展法求最长回文子串，超级棒的解法，面试优先
string longestPalindrome(string s) {
    string result;
    if(s.size()==0)
        return result;
    int n = s.size();
    int start =0, maxLen=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;i-j>=0 && i+j<n && s[i-j]==s[i+j];j++)
        {
            if(2*j+1>maxLen)
            {
                start=i-j;
                maxLen=2*j+1;
            }
        }
        for(int j=0;i-1-j>=0 && i+j<n && s[i-1-j]==s[i+j];j++)
        {
            if(2*j+2>maxLen)
            {
                start=i-j-1;
                maxLen=2*j+2;
            }
        }
    }
    
    result=s.substr(start,maxLen);
    return result;
}

/* 使用动态规划，不过扩展方向有点不同 */
// 解法2：
string longestPalindrome(string s) {
    string result;
    if(s.empty())
        return result;
    
    int start = 0, maxLen = 0;
    int n=s.size();
    vector<vector<bool> > dp(n,vector<bool>(n));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(s[j]==s[i] && (i-j<2 || dp[j+1][i-1]))
            {
                dp[j][i]=true;
                if(i-j+1>maxLen){
                    start=j;
                    maxLen=i-j+1;
                }
            }
        }
    }
    
    return s.substr(start,maxLen);
}

/* 问题3：找出最长回文子序列 */
int longestPalindromeSubseq(string s) {
    int n=s.size();
    vector<int> dp(n,0);
    vector<int> dp2(n,0);
    for(int i=n-1;i>=0;i--){
        dp[i]=1;
        for(int j=i+1;j<n;j++){
            dp[j]=(s[i]==s[j])?dp2[j-1]+2:max(dp[j-1],dp2[j]);
        }
        swap(dp,dp2);
    }
    return dp2[n-1];
}
