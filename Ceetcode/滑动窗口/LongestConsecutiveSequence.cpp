/* 题目：找出无序数组的最长连续子序列 [3,100,4,5,10,6]（而不是子数组），那么应该返回长度为4 */
/* 必须是o(n)的时间复杂度，这里我们采用两端扩张法，扩展之后将元素删除，防止重复计算，保证线性时间复杂度 */
int LongestConsecutiveSeq(vector<int>& nums)
{
	int result =0;
	unordered_set<int> s(nums.begin(),nums.end()); // set的初始化方式，数组变集合
	for(int val:nums)
	{
		if(!s.count(val)) // 使用count函数来判定是否存在
			continue; // 如果已经访问过，那么直接跳过
		s.erase(val);
		int pre = val-1;
		int next = val +1;
		while(s.count(pre))
			pre--;
		while(s.count(next))
			next++; // 最终pre+1,next-1都是连续子序列的一部分，而pre和next不是
		result = max(result, next-pre-1); // 所以计算长度时使用 next-pre-1,而不是 next-pre+1
	}
	return result;
}

