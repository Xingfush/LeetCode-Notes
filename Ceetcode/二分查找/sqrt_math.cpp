/* 二分查找的经典应用：题目的本质就是在数组 [0,1,2...,n]中找到 第一个平方小于等于 target的元素
	使用 lower_bound-1 的求解 */

int MySqrt(int x) {
    if(x<2) return x;
    int left = 0, right =x;
    while(left<right){
        int mid = left+(right-left)/2;
        if(x/mid>=mid)
            left = mid+1;
        else
            right = mid;
    }
    return left-1;
}