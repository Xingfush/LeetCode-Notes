/* 题目：滑动窗口的中位数
    维持一个大小为 k 的二叉树 multiset，新数字维护过程如下：
    1. nums[i]<*mid, nums[i-k]<=*mid --mid ++mid，mid 不动
    2. nums[i]>=*mid, nums[i-k]>*mid 不动
    3. nums[i]<*mid, nums[i-k]>*mid --mid;
    4. nums[i]>=*mid, nums[i-k]<=*mid ++mid
    这四种情况可以通过两个 if 判断实现，强行记忆吧，<+<=，*mid双在后 */

vector<double> MedianSlidingWindow(const vector<int>& nums, int k){
    vector<double> res;
    multiset<double> ms(nums.begin(),nums.begin()+k);
    auto mid = next(ms.begin(), k/2);
    for(int i=k;;i++){
        res.push_back((*mid+*prev(mid,1-k%2))/2);
        if(i==nums.size()) return res; // 从 k+1开始，过后判断
        ms.insert(nums[i]);
        if(nums[i]<*mid) mid--;
        if(nums[i-k]<=*mid) mid++;
        ms.erase(ms.lower_bound(nums[i-k])); // 因为有重复元素，因此找到第一个大于等于的就行了
        // 找到第一个大于等于 nums[i-k]的数，重复元素只能删一个
    }

}
