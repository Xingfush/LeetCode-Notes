/* 组合：相对于排列要简单一点，因为这里不用考虑顺序，所以，只用长度作为终止条件即可 */
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> out;
    dfs(n, k, 1, out, res);
    return res;
}

void dfs(int n, int k, int ind, vector<int>& out, vector<vector<int>>& res) {
    if (out.size() == k) {
    	res.push_back(out);
    	return;
    }
    for (int i = ind; i <= n; ++i) {
        out.push_back(i);
        dfs(n, k, i + 1, out, res);
        out.pop_back();
    }
}

/* 对数组进行 组合，借鉴combination sum 去重操作 */

vector<vector<int>> combine(vector<int>& nums, int k)
{
    sort(nums.begin(),nums.end())
    vector<vector<int>> res;
    vector<int> out;
    dfs(nums, k, out, res, ind);
    return res;
}

void dfs(vector<int>& nums, int k, vector<int>& out, 
                vector<vector<int>>& res, int ind)
{
    if(out.size()==k){
        res.push_back(out);
        return;
    }
    for(int i=ind;i<nums.size();i++)
    {
        if(i!=ind || nums[i]!=nums[i-1]){
            out.push_back(nums[i]);
            dfs(nums,k,out,res,ind+1);
            out.pop_back()
        }
    }
}