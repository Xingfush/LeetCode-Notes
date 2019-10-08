vector<int> TwoSum(vector<int>& nums, int target) {
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