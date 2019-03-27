/* 使用O(n) 空间复杂度完成的动态规划 */

int longestPalindromeSubseq3(string s) {
    int length = s.size();
    int *dp = new int[length]();
    int *dp2 = new int[length]();
    for (int i = length - 1; i >= 0; i--)
    {
        dp[i] = 1; // 对角线上的元素，直接为1，边界条件
        for (int j = i + 1; j < length; j++)
        {
            dp[j] = (s[j] == s[i] ? dp2[j - 1] + 2 : max(dp[j - 1], dp2[j]));
        }
        swap(dp, dp2); // dp 表示本行的动态规划记录, dp2 表示上一行的，二者交替向上移动
        memset(dp, 0, sizeof(int)*length); // dp 每一次都会更新，清零
    }
    int result = dp2[length - 1];
    delete[] dp;
    delete[] dp2;

    return result;
}

/* 使用动态规划二维数组记录的空间复杂度为O(n^2)，遍历方式与上面是不一样的 */
int longestPalindromeSubseq(string s) {
    int length = s.size();
    int** PalindRecord = new int*[length];
    for (int i = 0; i<length; i++)
        PalindRecord[i] = new int[length]();
    for (int i = 0; i<length; i++)
    {
        PalindRecord[i][i] = 1;// 长度为1 是边界条件，下面的len从2开始
    }
    for (int len = 2; len <= length; len++)
    {
        for (int i = 0; i <= length - len; i++) // length 和 len都表示长度，长度和长度运算
        {
            int j = i + len - 1; // j-i+1=len,
            if (s[i] == s[j])
                PalindRecord[i][j] = PalindRecord[i + 1][j - 1] + 2; // 状态转移方程
            else
                PalindRecord[i][j] = max(PalindRecord[i + 1][j], PalindRecord[i][j - 1]);
        }
    }
    int result = PalindRecord[0][length - 1];

    for (int i = 0; i < length; i++)
        delete[]PalindRecord[i];
    delete[]PalindRecord;
    
    return result;

/* 题目：最长的回文子串，子串是连续的，区别于上面的子序列 */
// 使用动态规划记录一个bool数组，区别于上面的int数组
string findLongestPalindrome2(string & s)
{
    int length = s.size();
    int start;
    int maxLength;
    bool **PalinRecord = new bool*[length];
    for (int i = 0; i < length; i++)
    {
        PalinRecord[i] = new bool[length];
        memset(PalinRecord[i], 0, sizeof(bool)*length);
    }
    for (int i = 0; i < length; i++)
    {
        PalinRecord[i][i] = true; // 设置len为1的边界条件
        // 这一部分的处理非常重要
        if (i < length - 1 && s[i] == s[i + 1])
        {
            PalinRecord[i][i + 1] = true;
            maxLength = 2; // 如果有2那么设置为2的边界条件，必须有这一步，分别应付奇、偶两种情况
            start = i;
        }
    }
    for (int len = 3; len <= length; len++)
    {
        for (int i = 0; i <= length - len; i++) {
            int j = i + len - 1;
            if (PalinRecord[i + 1][j - 1] && s[i] == s[j])
            {
                PalinRecord[i][j] = true;
                maxLength = len;
                start = i;
            }
        }
    }
    for (int i = 0; i < length; i++)
        delete[]PalinRecord[i];
    delete []PalinRecord;
    return s.substr(start, maxLength);
}

// 使用暴力破解法，子串有O(n^2)个，加上遍历，复杂度为O(n^3)
string findLongestPalindrome(string & s)
{
    int length = s.size();
    int maxLength = 0;
    int start = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            int temp1 = i, temp2 = j;
            while (temp1 < temp2) // 这里是<
            {
                if (s[temp1] == s[temp2])
                    temp1++, temp2--;
                else
                    break;
            }
            if (temp1 >= temp2 && maxLength<j-i+1) // 常用技巧，终点检查
            {
                maxLength = j - i + 1;
                start = i;
            }
        }
    }
    if (maxLength > 0)
        return s.substr(start, maxLength);
    return 0;
}

// 本答案只是记录一下如何使用 vector来操作。
int longestPalindromeSubseq(string s) {
        int i = 0, j = 0, n = s.size();
        if (n < 2) return n;
        vector<int> dp(n, 0), dp2(n, 0);

        for (i = n-1; i >= 0; --i)
        {
            dp[i] = 1;
            for (j = i + 1; j < n; ++j)
            {
                dp[j] = s[i] == s[j] ? dp2[j-1] + 2 : max(dp2[j], dp[j-1]);
            }
            dp2.swap(dp);
            dp.clear();
        }
        return dp2[n-1];
    }