/* 不限制操作次数，相当于把所有的正利润全部加起来，比较简单 */

int MaxProfit(const vector<int>& prices) {
    int result =0;
    for(int i=1;i<prices.size();i++){
        int profit=max(prices[i]-prices[i-1],0);
        result += profit;
    }
    return result;
}