/* 题目描述，找到数组的局部峰值，可以将两端看做无穷小
	思路：最简单的思路就是，从索引1开始，本元素小于上一个元素，那么上一个元素就是峰值 */

int findPeakElement(vector<int>& nums) {
    if(nums.size()==1) return 0;
    for(int i =1;i<nums.size();i++){
        if(nums[i]<nums[i-1]) return i-1;
    }
    return nums.size()-1;
}

/* 二分查找： */
int findPeakElement(vector<int>& nums) {
    if(nums.size()==1) return 0;
    int left =0,right = nums.size()-1;
    while(left<right){
        int mid = left+(right-left)/2;
        if(nums[mid]<nums[mid+1]) left = mid+1;
        else right = mid;
    }
    return right;
}

/* 这里二分查找的应用非常典型，画个图一目了然，需要明确：
	1.起始条件 right = nums.size()-1, 终止条件 left<right
	2.left = mid+1, right = mid,画个图就很清楚了 */