/* 经典题目：青蛙过河
一只青蛙如果上一次跳了k距离，那么下次只能跳k-1,k,k+1的距离，照这种跳法，
青蛙能不能跳到最后的石头上。
用一个哈希表建立每个石头和在该位置上能跳的距离之间的映射，建立一个
一维dp数组，其中dp[i]表示在位置i的石头青蛙的弹跳力（只有青蛙能够跳
到这个石头，dp[i]才大于0），由于题目中规定了第一个石头青蛙的跳距离
必须是1，为了后面的统一，我们对青蛙在第一块石头的弹跳力初始化为0。
我们用k表示当前石头，然后开始遍历剩余的石头，对于遍历到的石头i，我们找到
刚好能跳到i上的石头k，如果i和k的距离大于青蛙在k上的弹跳力+1，则说明
青蛙在k上到不了i，则k自增1。 
我们从k遍历到i，如果青蛙能从中间某个石头跳到i上，我们更新石头i上的弹跳力
和最大弹跳力，当这样的循环完成之后，我们只要检查最后一个石头上青蛙的
最大弹跳力是否大于0即可：
这里的m表示石头i上青蛙的弹跳力，即从k跳到i上的距离*/

bool canCross(vector<int>& stones)
{
	unordered_map<int, unordered_set<int>> m;
	vector<int> dp(stones.size(), 0);
	m[0].insert(0);;
	int k = 0;
	for(int i=1;i<stones.size();i++){
		while(dp[k]+1<stones[i]-stones[k]) k++;
		for(int j=k;j<i;j++){
			int t = stones[i]-stones[j];
			if(m[j].count(t-1) || m[j].count(t) || m[j].count(t+1)){
				m[i].insert(t);
				dp[i] = max(dp[i], t);
			}
		}
	}
	return dp.back()>0;
}




