/* 经典的动态规划题目：必须熟练掌握 */

bool WordBreak(const string& s,
               const vector<string>& wordDict){
    int n = s.size();
    unordered_set<string> map(wordDict.begin(),wordDict.end());
    vector<bool> dp(n+1,false);
    dp[0] = true;// 处理空串的情况，即长度为零，必须加上
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){ // 这里的 j<i，而不是 j<=i，表示至少还有一个字符的间隔
            if(dp[j] && map.count(s.substr(j,i-j))){ 
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[n];
}

/*j=0的时候 dp[0],s.substr(0,i=size) 和 j=i, dp[i], s.substr(i,0) 是等效的，都是判断 s[0,i-1] 是不是在字典里。
    # l e e t c o d e
i:  0 1 2 3 4 5 6 7 8
j:    0 1 2 3 4 5 6 7
dp: 0 1 2 3 4 5 6 7 8
以 i = 5 为例，判断字符串 leetc 是否可分，那么 j 从 0 开始到 i-1，即 j=[0,4],正好覆盖 l e e t c 五个字母
j = 0 时，判断 dp[0] && leetc
j = 1 时, 判断 dp[1] && eetc
...
j = 4 时，判断 dp[4] && c
正好 子数组 [j,i] 越来越小，从全字符串到 最后一个字母，使用 s.substr(j,i-j) 表示

