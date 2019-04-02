/* 题目要求：判断数组中是否存在递增的三元组，绝妙的解法 */
bool increasingTriplet(vector<int>& nums) {
    int c1= INT_MAX,c2=INT_MAX;
    for(int x:nums)
    {
        if(x<=c1)
            c1=x;
        else if(x<=c2)
            c2=x;
        else
            return true;
    }
    return false;
}