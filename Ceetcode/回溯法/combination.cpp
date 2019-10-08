/* 组合：相对于排列要简单一点，因为这里不用考虑顺序，所以，只用长度作为终止条件即可 */
void dfs(const vector<int>& nums, int k, int ind,
         vector<int> path, vector<vector<int>>& res){
    if(path.size()==k){
        res.push_back(path);
        return;
    }
    for(int i=ind;i<nums.size();i++){
        if(i==ind || nums[i]!=nums[i-1]){
            path.push_back(nums[i]);
            dfs(nums,k,i+1,path,res); // 这里是 i+1, 而不是 ind+1
            path.pop_back();
        }
    }
}

vector<vector<int>> Combination(vector<int> nums, int k){
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    vector<int> path;
    dfs(nums, k, 0, path, res);
    return res;
}