/* 字节跳动秋招笔试题目：给定m秒，做n道题目，每道题目需要的时间已知，现在
   我们按顺序开始做题，比如时间为 [1,2,3,4,5]，总时间为 5，那么为了保证第i
   道题目做完，我们可能要放弃前面一些题目，比如，要做第三题，那么第一道和
   第二道只能留 2时间去做，必须放弃一道，现在：
   输入：每道题目需要的时间，和总的时间
   输出：做i道题目而必须放弃的前面的题目数
   例如 [1,2,3,4,5], 5
   输出：[0,0,1,2,4] */

vector<int> solution(vector<int>& nums, int total)
{
	vector<int> candidates; // 不断保存[0,i-1]的时间数组，有序
	vector<int> result(nums.size(), 0);
	for (int i = 0; i < nums.size(); i++) {
		int res_sum = total - nums[i];
		int temp = 0, j = 0;
		for (; j < candidates.size() && temp <= res_sum;j++)
			temp += candidates[j];
		if (temp > res_sum) // 必须先检查是否 temp>res_sum，而不是 j==candidates.size()，否则会出错
			// 非常微妙的细节，仔细体会
			// 例如 [1,2,3.5,4,5],10现在 i=3, res_sum = 10-4=6，for终止时j=4, temp = 6.5，但是必须要放弃一个  
			result[i] = candidates.size() - j + 1; 
		else
			result[i] = 0;
		auto ind = upper_bound(candidates.begin(), candidates.end(), nums[i]); // 保证有序，保证O(n)时间查找
		if (ind == candidates.end()) 
			candidates.push_back(nums[i]);
		else {
			candidates.insert(ind, nums[i]); // insert 的用法
		}
	}
	return result;
}


