/* 题目描述，找到数组的局部峰值，可以将两端看做无穷小
	思路：最简单的思路就是，从索引1开始，本元素小于上一个元素，那么上一个元素就是峰值 */

int FindPeakElement(int* array, int length){
    int left = 0, right = length-1;
    while(left<right){
        int mid = (left+right)/2;
        if(array[mid]>array[mid+1]) right = mid;
        else left = mid+1;
    }
    return array[right];
}
/* 这里二分查找的应用非常典型，画个图一目了然，需要明确：
	1.起始条件 right = nums.size()-1, 终止条件 left<right
	2.left = mid+1, right = mid,画个图就很清楚了 */