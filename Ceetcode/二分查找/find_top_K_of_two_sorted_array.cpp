int TopKElementOfTwoSortedArray(int* array1, int length1,
                                int* array2, int length2, int k){
    if(length1>length2)
        return TopKElementOfTwoSortedArray(array2, length2,
                                           array1, length1, k);
    if(length1==0)
        return array2[k-1];
    if(k==1)
        return min(array1[0], array2[0]);

    int k1 = min(k/2, length1);
    int k2 = k- k1;
    /*说明array2的k2-1前部分一定在第k大元素之前，因此
    1.将k2-1这部分全跳过：更新数组首位地址索引，同时更新数组长度；
    2.将这k2个元素纳入到已找到的第k大元素范围内，更新k值
    */
    if(array1[k1-1]>array2[k2-1])
        return TopKElementOfTwoSortedArray(array1, length1,
                                           array2+k2, length2-k2, k-k2);
    else if(array2[k2-1]>array1[k1-1])
        return TopKElementOfTwoSortedArray(array1+k1, length1-k1,
                                           array2, length2, k-k1);
    else
        return array2[k1-1];

    return 0;
}

/* 想清楚边界条件：首先 k 不可能是 0，其次对于1有特殊处理，那么k=2之后不断二分，永远不会出现
 k=0 的情况。这几点非常重要：
 1. len1==0的时候(因为k1<=len1)，所以必然是len1先缩减至长度为0，直接定位第二个数组
 2. k==1的时候，直接定位两个头元素最小值
 3. k1=min(k/2,len1) 防止数组长度小于k
 4. 当array1[k1-1]==array2[k2-1]时候，直接返回结果。
*/