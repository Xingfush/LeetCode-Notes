/* 全排列：一个经典的深度优先遍历问题 */
/* 条件：数组内没有重复元素 */

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visited(nums.size(),false);
    dfs(nums,0,res,path,visited);
    return res;    
}

void dfs(vector<int>& nums, int len, vector<vector<int>>& res, 
         vector<int>& path, vector<bool>& visited){
    if(len==nums.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(visited[i]) continue;
        path.push_back(nums[i]);
        visited[i]=true;
        dfs(nums,len+1,res,path,visited);
        path.pop_back();
        visited[i]=false;
    }
}

/* 如果加强要求，数组内有重复元素，且结果中不能包含重复组合，解决方法和 combination sum 基本相同
	但是这里有一点不同：
	例如 1 1 2，先选1，然后 i>0 && nums[i]==nums[i-1]，那么此时如果直接 continue，则永远都为空，
	显然是错误的，应该为 i>0 && !visited[i-1] && nums[i]==nums[i-1]，当 出现 1 1 2 排列后，
	下次先选 1（第二个1），由于第一个已经回溯释放，visited[i-1]=false，所以可以直接跳过*/
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visited(nums.size(),false);
    dfs(nums,0,res,path,visited);
    return res;    
}

void dfs(vector<int>& nums, int len, vector<vector<int>>& res, 
         vector<int>& path, vector<bool>& visited){
    if(len==nums.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(visited[i]) continue;
        if(i>0 && !visited[i-1] && nums[i]==nums[i-1]) continue; // 核心
        path.push_back(nums[i]);
        visited[i]=true;
        dfs(nums,len+1,res,path,visited);
        path.pop_back();
        visited[i]=false;
    }
}