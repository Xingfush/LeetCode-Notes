/* 使用回溯法 */ 


void dfs(const vector<int>& nums, int ind, int target,
         vector<int> path, vector<vector<int>>& res){
    if(target==0){
        res.push_back(path); // 注意这里后面不要加 return，因为会出现后面组合为0，
		// 例如 target = 8, [2,4,2,2,-2,0]，如果加了 return 那么 [2,4,2,2-2]就不会出现
    }
    for(int i=ind;i<nums.size();i++){
        if(i==ind || nums[i]!=nums[i-1]){
            path.push_back(nums[i]);
            dfs(nums,i+1,target-nums[i],path,res);
            path.pop_back();
        }
    }
}

vector<vector<int>> CombinationSum(vector<int> nums, int target){
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    vector<int> path;
    dfs(nums, 0, target, path, res);
    return res;
}

// trick1：排序后，遍历是必要的，遇见重复的元素，直接跳过，不做判断
// trick2：继续搜索时，begin 从i+1 开始，表示，这个元素不能重复使用

