/* 题目要求：判断数组中是否存在递增的三元组，有点像智力题
保存一个最小元素和一个第二小元素的有序对，一旦出现第三个，立刻返回 */

bool FindIncreasingTriplet(const vector<int>& nums){
    int c1 = INT_MAX, c2 = INT8_MAX;
    for(int a:nums){
        if(a<c1)
            c1 = a;
        else if(a<c2)
            c2 = a;
        else
            return true;
    }
    
    return false;
}