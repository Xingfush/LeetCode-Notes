/* lower_bound()返回第一个大于等于target的位置（迭代器）
   upper_bound()返回第一个 大于 target的位置（迭代器）*/

int lengthOfLIS(vector<int>& nums) {
    if(nums.size()==0)
        return 0;
    vector<int> tailTable;
    tailTable.push_back(nums[0]);
    for(int num:nums)
    {
        auto j = lower_bound(tailTable.begin(),tailTable.end(),num);
        if(j==tailTable.end())
            tailTable.push_back(num);
        else
            *j=num;
    }
    return tailTable.size();
}

// 如果面试官不允许我们使用STL函数，那么手写 lower_bound 函数
int lengthOfLIS(vector<int>& nums)
{
    if(nums.size()==0)
        return 0;
    vector<int> tailTable;
    tailTable.push_back(nums[0]);

    for(int num:nums)
    {
        int start=0,end=nums.size();
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(tailTable[mid]<num)
                start=mid+1;
            else
                end=mid;
        }
        if(start==tailTable.size())
            tailTable.push_back(num);
        else
            tailTable[start]=num;
    }
    return tailTable.size();
}

