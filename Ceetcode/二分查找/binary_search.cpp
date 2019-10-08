/* 二分法查找的变形：找到重复的排序数组的出现的第一个位置 */

int BinarySearchFirst(int* array, int start, int end, int target){
    int res = -1;
    while(start<end){
        int mid = start + (end-start)/2;
        if(array[mid]==target){
            res = mid;
            end = mid;
        }
        else if(array[mid]<target)
            start = mid+1;
        else
            end = mid;
    }

    return res;
}

/* 二分法查找的变形：找到重复的排序数组的出现的最后一个位置 */

int BinarySearchLast(int* array, int start, int end, int target){
    int res = -1;
    while(start<end){
        int mid = start + (end-start)/2;
        if(array[mid]==target){
            res = mid;
            start = mid+1;
        }
        else if(array[mid]<target)
            start = mid+1;
        else
            end = mid;
    }

    return res;
}