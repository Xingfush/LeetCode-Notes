/* 作为 Sliding Window 的一类题目，下面的解法非常典型，使用双端队列
	队列只保存可能成为 sliding window内最大值的元素“索引”，每次只返回队首元素即可
	如果队首元素已经“过期了”（q.front()==i-k）那么必须删除，因为不在窗口内了
	如果队尾元素小于新的元素，那么队尾元素删除，新元素入队。
	每次求最大值的过程就是 取队首。*/

vector<int> MaximunSlidingWindow(const vector<int>& nums, int k){
    vector<int> res;
    deque<int> q;
    for(int i=0;i<nums.size();i++){
        while(!q.empty() && q.front()==i-k)
            q.pop_front();
        while(!q.empty() && nums[q.back()]<nums[i])
            q.pop_back();
        q.push_back(i);
        if(i>=k-1)
            res.push_back(nums[q.front()]);
    }

    return res;
}

// 之前所有 小于新入元素的队元素，全部移除
// 新元素一定入队