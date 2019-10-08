/* 本题是典型的两端指针法，左右指针向中间移动，确定最小的长度，同时右指针向右移动，遍历数组
    方法非常典型，和 longest consecutive sequence有异曲同工之妙

    nums数组元素必须全部>=0，不然，该方法不适用，必须使用动态规划 */


int MinimumSubarraySum(const vector<int>& nums, int target){
    int sum = 0, left = 0, right = 0;
    int res = INT_MAX;
    while(right<nums.size()){
        sum += nums[right++];
        while(sum>=target){
            res = min(res, right-left);
            sum -= nums[left++];
        }
    }

    return res==INT_MAX?-1:res;
}