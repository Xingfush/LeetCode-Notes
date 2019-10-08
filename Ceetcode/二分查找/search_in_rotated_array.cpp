bool SearchInRotatedArray(int* array, int length, int target){
    int left = 0, right = length-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(array[mid]==target){
            return true;
        } else if(array[mid]<array[right]) {
            if(array[mid]<target && array[right]>=target)
                left = mid+1;
            else
                right = mid-1;
        } else if(array[mid]>array[right]) {
            if(array[mid]>target && array[left]<=target)
                right = mid-1;
            else
                left = mid+1;
        } else {
            right--;
        }
    }

    return false;
}