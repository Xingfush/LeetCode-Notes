/* 有一列数组，其中一般为奇数，一般为偶数，
调整位置，要求奇数位置全为奇数，偶数位置全为偶数，
常数空间，线性时间复杂度 */

void ArrangeOddEevenElements(const vector<int>& nums){
    int odd = 0, even = 1; // 双标指针交换法
    while(even<nums.size() && odd<nums.size()){
        while(nums[odd] & 1) odd+=2;
        while((nums[even] & 1) == 0) even+=2;
        swap(nums[odd], nums[even]);
        odd+=2;
        even+=2;
    }
}