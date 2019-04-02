/* 找出两个无序数组的最长重复子数组，例如[1 2 3 2 1]和[3 2 1 4 7]的最长重复子数组为 3 2 1，返回为3
   显然，应该使用动态规划，这里的动态转移方程为 
   if A[i]==B[j]
        dp[i][j]=dp[i-1][j-1]+1
   else
   		dp[i][j]=0 
   	时间复杂度为o(mn),空间复杂度为O(min(m,n))，这里由于有对角线的元素关系，所以必须使用两个状态数组，进行滚动*/
int findLength(vector<int>& A, vector<int>& B) {
    int m=A.size(),n=B.size();
    vector<int> dp(n+1,0); // 两个状态数组，进行滚动
    vector<int> dp2(n+1,0);
    int res = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(A[i]==B[j-1]) // 这里必须多一个元素，初始化边界条件
            {
                dp[j]=dp2[j-1]+1;
                res=max(res,dp[j]); // 实时记录最大的res
            }
            else
                dp[j]=0; // 一定要赋值为0，为下一阶段清理
        }
        swap(dp,dp2); // 滚动更新常用手段，使用STL swap函数。
    }
    return res;
}
