/* 将一个数组旋转 k 位，例如
  1 2 3 4 5 6 7, 旋转 k = 3
  5 6 7 1 2 3 4,
  要求 O(n) 时间复杂度， O(1) 空间复杂度，也就是不能使用辅助数组，
  这里优先想到使用 旋转的方法，in-place，解法有很多，这里选一种简单的。
   */

void RotateArrayByK(vector<int>& array, int k){
    if(array.empty()) return;
    int start = 0, n = array.size();
    while(n && (k%n)){
        for(int i=0;i<k;i++){
            swap(array[i+start],array[i+start+n-k]);
        }
        n -= k;
        start += k;
    }
}

