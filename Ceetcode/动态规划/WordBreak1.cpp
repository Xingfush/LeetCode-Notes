/* 经典的动态规划题目：必须熟练掌握 */

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    unordered_set<string> map(wordDict.begin(),wordDict.end());
    vector<int> dp(n+1,0);
    dp[0]=1; // 处理空串的情况，即长度为零，必须加上
    for(int i=1;i<=s.size();i++){
        for(int j=0;j<i;j++){  // 这里的 j<i，而不是 j<=i，表示至少还有一个字符的间隔
            if(dp[j] && map.count(s.substr(j,i-j))){ // 这里的s.substr(j,i-j)，j坐标表示长度为 j+1
                dp[i]=1;
                break;
            }
        }
    }
    return dp[n];
}

//j=0的时候 dp[0],s.substr(0,i=size) 和 j=i, dp[i], s.substr(i,0) 是等效的，都是判断 s[0,i-1] 是不是在字典里。