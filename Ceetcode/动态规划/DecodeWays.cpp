/* 和爬梯子的斐波那契数列性质很像，不过加了些限制条件 */

int numDecodings(string s) {
    if(s.empty() || (s.size()>1 && s[0]=='0'))
        return 0;
    vector<int> dp(s.size()+1,0);
    dp[0]=1;
    for(int i=1;i<s.size()+1;i++){
        dp[i]=(s[i-1]=='0')?0:dp[i-1];
        if(i>1 && (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6')))
            dp[i] +=dp[i-2];
    }
    return dp.back();
}