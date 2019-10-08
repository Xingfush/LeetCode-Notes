void dfs(const vector<int>& nums, int ind,
         vector<int> path, vector<vector<int>>& res){
    res.push_back(path);
    for(int i=ind;i<nums.size();i++){
        if(i==ind || nums[i]!=nums[i-1]){
            path.push_back(nums[i]);
            dfs(nums,i+1,path,res);
            path.pop_back();
        }
    }
}

vector<vector<int>> Subsets(vector<int> nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    vector<int> path;
    dfs(nums, 0, path, res);
    return res;
}