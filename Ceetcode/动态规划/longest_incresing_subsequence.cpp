int LongestIncreasingSubsequence(const vector<int>& nums) {
    if(nums.size()==0)
        return 0;
    vector<int> tailTable;
    tailTable.push_back(nums[0]);
    for(int num:nums)
    {
        // 找到第一个大于等于 num 的元素
        auto j = lower_bound(tailTable.begin(),tailTable.end(),num);
        if(j==tailTable.end())
            tailTable.push_back(num);
        else
            *j=num;
    }
    return tailTable.size();
}

/* 返回内容 */

vector<int> LongestIncreasingSubsequence(const vector<int>& nums){
    if(nums.empty()) return {};
    int n = nums.size();
    vector<int> tail_table;
    vector<vector<int>> record_table;
    tail_table.push_back(nums[0]);
    record_table.push_back(tail_table);

    for(int num:nums){
        int start = 0, end = tail_table.size();
        while(start<end){ // 找到第一个大于等于 num 的元素
            int mid = start + (end-start)/2;
            if(tail_table[mid]<num) start = mid+1;
            else end = mid;
        }
        if(start==tail_table.size()){
            tail_table.push_back(num);
            vector<int> temp = record_table.back();
            temp.push_back(num);
            record_table.push_back(temp);
        } else {
            tail_table[start] = num;
            record_table[start].back()=num;
        }
    }

    return record_table.back();
}