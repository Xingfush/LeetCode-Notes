/* 使用回溯法 */ 

vector<vector<int> > combinationSum(vector<int> & candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vector<vector<int> > result;
	vector<int> combination;
	combinationSum(candidates, target, result, combination, 0); // 需要进行传引用的 result combination
	return result;
}

// trick1：排序后，遍历是必要的，遇见重复的元素，直接跳过，不做判断
// trick2：继续搜索时，begin 从i+1 开始，表示，这个元素不能重复使用

void combinationSum(vector<int>& nums, int target, vector<vector<int> >& res,
				vector<int> path, int ind)
{
	if(target==0){
		res.push_back(path); // 注意这里后面不要加 return，因为会出现后面组合为0，
		// 例如 target = 8, [2,4,2,2,-2,0]，如果加了 return 那么 [2,4,2,2-2]就不会出现
	}
	for(int i=ind;i<nums.size();i++){
		if(i==ind || nums[i]!=nums[i-1]){
			path.push_back(nums[i]);
			combinationSum(nums, target-nums[i], res, path, i+1);
			path.pop_back();
		}
	}
}

