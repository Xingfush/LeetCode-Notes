void RemoveDuplicates(vector<int>& nums){
    if(nums.empty()) return;
    int pre = nums[0];
    for(auto iter=nums.begin()+1;iter!=nums.end();iter++){
        if(*iter!=pre){
            pre = *iter;
            iter++;
        }
        else{
            iter = nums.erase(iter);
        }
    }
}
