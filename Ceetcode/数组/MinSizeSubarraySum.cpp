/* 本题是典型的两端指针法，左右指针向中间移动，确定最小的长度，同时右指针向右移动，遍历数组
    方法非常典型，和 longest consecutive sequence有异曲同工之妙 */

int minSubArrayLen(int s, vector<int>& nums) {
    
    int sum=0;
    int len=INT_MAX;
    int l=0,r=0;
    int n=nums.size();
    while(r<n)
    {
        sum+=nums[r++];// 加的顺讯考虑一下
        while(sum>=s)
        {    
            len=min(r-l,len);
            sum -=nums[l++];
        }
    }
    return len==INT_MAX?0:len;
}