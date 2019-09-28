/* 全子集问题，优先使用深度优先遍历回溯法 */
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<int> path;
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	dfs(nums, 0, path, res);
	return res;
}

void dfs(vector<int>& nums, int ind, vector<int>& path, 
				vector<vector<int>>& res)
{
	res.push_back(path); // 和组合问题的区别
	for(int i=ind;i<nums.size();i++)
	{
		path.push_back(nums[i]);
		dfs(nums, i+1, path, res);
		path.pop_back();
	}
}

/* 问题稍微扩展，如果数组中有重复数字，又该如何 */

vector<vector<int>> subsetsWithDuplicate(vector<int>& nums)
{
	if(nums.empty()) return {};
	vector<int> path;
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	dfs(nums, 0, path, res);
	return res;
}

void dfs(vector<int>& nums, int ind, vector<int>& path, vector<vector<int>>& res)
{
	res.push_back(path); // 去掉收敛条件，就是全组合，必须记住
	for(int i=ind;i<nums.size();i++)
	{
		if(i==ind || nums[i]!=nums[i-1]){
			path.push_back(nums[i]);
			dfs(nums, i+1, path, res);
			path.pop_back();
		}
	}
}

