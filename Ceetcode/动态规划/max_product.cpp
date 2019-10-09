/* 和 max subarray sum 不同的是，由于会出现负数，因此需要保存两个动态数组，
保存最大和最小，这里注意，初始化非常重要。 */

int MaxProduct(const vector<int>& nums) {
    int mx = nums[0], mn = nums[0], res = nums[0];
    for(int i=1;i<nums.size();i++){
        int temp_mx = mx, temp_mn = mn;
        mx = max(max(temp_mx*nums[i],nums[i]),temp_mn*nums[i]);
        mn = min(min(temp_mn*nums[i],nums[i]),temp_mx*nums[i]);
        res = max(mx,res);
    }
    return res;
}

/* 一个易错点就是，在更新 mn 的时候忽略了 mx 已经被更新，导致逻辑错误，
因此，要在更新 mx, mn 的时候，保存上个状态的 mx, mn. */
