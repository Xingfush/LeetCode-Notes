vector<vector<int>> ThreeSum(vector<int> nums){
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());

    for(int i=0;i<nums.size()-2;i++){
        int target = -nums[i];
        int front = i+1, back = nums.size()-1;
        while(front<back){
            int sum = nums[front]+nums[back];
            if(sum<target) front++;
            else if(sum>target) back--;
            else {
                vector<int> triplet(3);
                triplet[0] = nums[front];
                triplet[1] = nums[back];
                triplet[2] = nums[i];
                res.push_back(triplet);
                while (front < back && nums[front] == triplet[0]) front++;
                while (front < back && nums[back] == triplet[1]) back--;
            }
        }
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
    }

    return res;
}


// 如果有一天我也能写出如此思路清晰、简介优雅的代码，那么我会非常骄傲！
/* Two Sum 代码如下，但是注意思路完全不同，这里不能排序，因为要达到线性时间复杂度 */