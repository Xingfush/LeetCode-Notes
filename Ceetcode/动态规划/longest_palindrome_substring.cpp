/* 方法1:动态规划 */

string LongestPalindromeSubstring(const string& s){
    string result;
    if(s.empty()) return result;
    int n = s.size();
    int start = 0, len = 0;
    vector<vector<bool>> dp(n,vector<bool>(n,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){ // j 从 0 到 i，[j,i] 从 全长到 一个字符
            if(s[i]==s[j] && (i-j<2 || dp[j+1][i-1])){
                dp[j][i] = true;
                if(i-j+1>len){
                    len = i-j+1;
                    start = j;
                }
            }
        }
    }

    return s.substr(start,len);
}


// 使用中心扩展法求最长回文子串，超级棒的解法，面试优先
string LongestPalindromeSubstring(const string& s) {
    string result;
    if(s.size()==0)
        return result;
    int n = s.size();
    int start =0, maxLen=0;

    for(int i=0;i<n;i++){
        for(int j=0;i-j>=0 && i+j<n && s[i-j]==s[i+j];j++){
            if(2*j+1>maxLen){
                start=i-j;
                maxLen=2*j+1;
            }
        }
        for(int j=0;i-1-j>=0 && i+j<n && s[i-1-j]==s[i+j];j++){
            if(2*j+2>maxLen){
                start=i-j-1;
                maxLen=2*j+2;
            }
        }
    }
    
    return  s.substr(start,maxLen);
}

