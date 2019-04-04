vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;

    std::sort(num.begin(), num.end()); // 排序用于去重

    for (int i = 0; i < num.size()-2; i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target) 
                front++;

            else if (sum > target)
                back--;

            else { 
                // 记录答案
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }
            
        }
        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    return res； 
}

// 如果有一天我也能写出如此思路清晰、简介优雅的代码，那么我会非常骄傲！
/* Two Sum 代码如下，但是注意思路完全不同，这里不能排序，因为要达到线性时间复杂度 */

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // 哈希表
        
    for(int i =0; i< nums.size(); i++){
         int complement = target - nums[i];
         if(map.find(complement) != map.end()){
             return {map[complement], i};
          }
        
          map[nums[i]] = i;
     }   
    
    return {};
}

// map.find(complement)!=map.end() 非常经典，STL设计的find函数找不到时都是返回
// end()迭代器。