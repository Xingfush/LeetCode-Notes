bool CanPartition(const vector<int>& nums){
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        assert(nums[i]>0);
        sum += nums[i];
    }
    if(sum%2) return false;

    int C = sum/2;
    vector<bool> dp(C+1,false);
    for(int j=0;j<=C;j++)
        dp[j]=(nums[0]==j);
    for(int i=1;i<nums.size();i++){
        for(int j=C;j>=nums[i];j--){
            dp[j] = dp[j] || dp[j-nums[i]];
        }
    }

    return dp[C];
}


