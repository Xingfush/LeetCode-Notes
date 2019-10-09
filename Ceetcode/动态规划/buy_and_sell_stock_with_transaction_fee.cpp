/* 每次交易需要交易费，交易次数尽可能少，减少交易费，这道题还是用动态规划做，具体的原理和思路暂时
	不深究，只说一下方法：使用两个一维数组，sold[],hold[]。
	sold:表示第i 天卖掉股票此时最大的利润，hold:表示第 i天保留手里的股票此时最大的利润。
	如果我们要卖掉手中的股票，那么此时我们的总利润应该是前一天手里有股票的利润（不然手里没有股票没法卖），加上此时的卖出价格
	减去交易费。同时和前一天卖出的利润进行对比，去其中的最大值。
	第i 天不卖的利润，就是昨天股票卖了然后减去今天的价格，即今天买入股票，得到的值和昨天股票保留时的利润相比，取其中的较大值。
	如果昨天的股票保留的利润大，那么就继续留到今天。
	动态规划的状态转移方程为：
	sold[i] = max( sold[i-1], hold[i-1]+prices[i]-fee)
	hold[i] = max( hold[i-1], sold[i-1]-prices[i]) */

int MaxProfit(const vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> sold(n,0);
    vector<int> hold(n,0);
    hold[0]=-prices[0];
    for(int i=1;i<n;i++){
        sold[i]=max(sold[i-1],hold[i-1]+prices[i]-fee);
        hold[i]=max(hold[i-1],sold[i]-prices[i]);
    }
    return sold.back();
}
