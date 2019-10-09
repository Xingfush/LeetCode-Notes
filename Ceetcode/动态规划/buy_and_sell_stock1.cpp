/* Best time to buy and sell stock to get maximum profit. */
/* 题目1：限制交易一次，本质就是max sum of subarray，但是这里 记录最小价格和最大利润
          的操作和 max sum of subarray还有一点不同，特此铭记。 */

int MaxProfit(const vector<int>& nums){
    if(nums.size()<2) return 0;
    int min_price = nums[0], max_profit = nums[1]-nums[0];
    for(int i=2;i<nums.size();i++){
        min_price = min(nums[i-1], min_price);
        max_profit = max(nums[i] - min_price, max_profit);
    }

    return max(0,max_profit);
}

