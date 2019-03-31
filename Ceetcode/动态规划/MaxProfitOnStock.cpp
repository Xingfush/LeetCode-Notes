/* Best time to buy and sell stock to get maximum profit. */
/* 题目1：限制交易一次，本质就是max sum of subarray，但是这里 记录最小价格和最大利润
          的操作和 max sum of subarray还有一点不同，特此铭记。 */
int maxProfit(vector<int> &prices) {
    if(prices.size()<2)
        return 0;
    int minPrice = prices[0]; // 初始化
    int profit = prices[1]-prices[0]; // 利润初始化
    for(int i=2;i<prices.size();i++) // 从2 开始
    {
        minPrice = min(prices[i-1],minPrice);
        profit = max(profit, prices[i]-minPrice);
    }
    if(profit<=0) // 如果利润小于0， 那么就不进行买卖
        return 0;
    return profit;
}

/* 不限制操作次数，相当于把所有的正利润全部加起来，比较简单 */
int maxProfit(vector<int>& prices) {
    int result =0;
    for(int i=1;i<prices.size();i++)
    {
        int profit=max(prices[i]-prices[i-1],0);
        result += profit;
    }
    return result;
}



