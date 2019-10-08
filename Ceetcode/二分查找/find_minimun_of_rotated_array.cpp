int MinimunInOrder(int* array, int left, int right){
    int res = array[right];
    for(int i=left;i<right;i++){
        if(array[i]<res) res = array[i];
    }
    return res;
}

int MinimumOfRotatedArray(int* array, int length){
    if(length<=1) return array[0];
    int left = 0, right = length-1;
    int mid = 0; // 防止出现没有旋转的情况，这样可以直接返回 arr[mid]=arr[0]

    while(array[left]>=array[right]){
        if(right-left==1){
            mid = right;
            break;
        }
        mid = (left+right)/2;
        if(array[mid]==array[left] &&  //三点相等的特殊情况
           array[left]==array[right]){
            return MinimunInOrder(array, left, right);
        } else if(array[mid]<=array[right]) { // arr[mid]<=arr[right]一定确定mid位于右区间
            right = mid;
        } else { // 不在右区间，那么肯定在左区间，由arr[mid]>=arr[left]一定确定位于左区间
            left = mid;
        }
    }

    return array[mid];
}
