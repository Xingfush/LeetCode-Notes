/* 一道典型的贪心算法的题目，求跳到终点需要的最小步数 */

int jump(vector<int>& nums) {
    int n = nums.size(),i=0,cur=0,pre=0;
    int res =0;
    while(cur<n-1){
        res++;
        pre = cur;
        for(;i<=pre;i++) // i 表示在上一个最远位置之后一个位置到当前最远位置之间遍历，找到下一个最远位置
            cur = max(cur,i+nums[i]);
    }
    return res;
}

/* 这里的贪心不是指在当前位置上跳到最远，而是指在当前位置可达的范围内，找到其中一个位置
这个位置的 i+nums[i] 是最大的，表示两步之内的贪心。我们需要用 pre表示这步内的最远范围，
使用 cur 表示下步内能跳的最远位置。 */
