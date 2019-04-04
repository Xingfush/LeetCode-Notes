/* 使用中心扩展法，时间复杂度同样是O(n^2)，空间复杂度甚至达到了常数，非常好的一个解法，面试优先 */

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

int longestPalindromeSubseq(string s) {
    int n=s.size();
    vector<int> dp(n+1,0);
    vector<int> dp2(n+1,0);
    for(int i=n;i>0;i--)
    {
        dp[i]=1;
        for(int j=i+1;j<=n;j++)
            dp[j]=(s[i-1]==s[j-1])?dp2[j-1]+2:max(dp[j-1],dp2[j]); // 不要忘记i,j是 1 索引的，需要减 1.
        swap(dp,dp2);
        dp.clear(); // 这里的 clear() 是要把 dp数组清零，按理说是这里的用法是错的，但是在 leetcode上能通过。
    }
    return dp2[n];
}
