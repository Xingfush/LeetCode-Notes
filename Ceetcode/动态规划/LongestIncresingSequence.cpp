/* lower_bound()返回第一个大于等于target的位置（迭代器）
   upper_bound()返回第一个 大于 target的位置（迭代器）
   这里我们到底用 lower_bound还是 upper_bound？
   如果 要求严格单调递增，那么我们必须找到 >= num的第一个数，就取而代之，
   例如 [1,2,2,3,4]，我们找到的tailTable中必须是 [1,2,3,4]，到 num=2的
   时候，我们必须找到>= 2的，因为如果找 >2 的，那么就又会.push_back num=2。
   所以这时候必须用 lower_bound。
   而如果不要求严格单调递增，那么用 upper_bound即可，可以容易多个 num=2。
   仔细理解一下！！！*/

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

// 如果面试官不允许我们使用STL函数，那么手写 lower_bound 函数，要求严格递增
int lengthOfLIS(vector<int>& nums)
{
    if(nums.size()==0)
        return 0;
    vector<int> tailTable;
    tailTable.push_back(nums[0]); // 这个其实无所谓，因为 lower_bound不对空数组报错

    for(int num:nums)
    {
        int start=0,end=nums.size();
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(tailTable[mid]<num)
                start=mid+1;
            else
                end=mid; // 从 tailTable 找到第一个大于等于 num的值
        }
        if(start==tailTable.size())
            tailTable.push_back(num);
        else
            tailTable[start]=num;
    }
    return tailTable.size();
}

/* 返回内容 */

int LongestIncreasingSequence(vector<int>& nums)
{
    if(nums.empty()) 
        return 0;
    vector<int> tailTable;
    vector<vector<int>> records;
    tailTable.push_back(nums[0]);
    records.push_back(tailTable);

    for(int num:nums)
    {
        int start = 0, end = tailTable.size();
        while(start<end){
            int mid = start+(end-start)/2;
            if(tailTable[mid]<num)
                start = mid+1;
            else
                end = mid;
        }
        if(start==tailTable.size()){
            tailTable.push_back(num);           
            records.push_back(tailTable.back().push_back(num));
        }
        else{
            tailTable[start] = num;
            records[start].pop_back();
            records[start].push_back(num);
        }
    }
    return records.back();
}