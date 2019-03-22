double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    // 保证 m<n
    if(m > n) // 这招很妙，一定避免逐个赋值，这个一下子复杂度立马上升到O(n)
    {
        return findMedianSortedArrays(nums2,nums1);
    }
    // 没有左闭右开，只有划分[0,i),[i,end),划分点i取值[0,end]=[imin,imax]
    int imin = 0, imax = m;
    int halflen = (m+n+1)/2;
    int max_of_left = 0, min_of_right =0;

    while(imin<=imax)// 只要还有划分点，注意是两端闭合
    {
        int i = (imin+imax)/2;
        int j = halflen-i; // 按照定义求j
        // 情况1，增大i
        // 由 i<m 可以推出 j>0，由 i>0 可以推出 j<n，这是等价条件，是后面nums[j-1]存在的必要条件
        if(i<m && nums2[j-1]>nums1[i])  //非临界情况检查: i<m and j>0
            imin = i+1;
        else if(i>0 && nums1[i-1]>nums2[j]) 
            imax = i-1;
        else
        { // 上面的条件不满足，有6种情况，注意原命题和逆否命题
            if(i==0)
                max_of_left=nums2[j-1];
            else if(j==0)
                max_of_left=nums1[i-1];
            else
                max_of_left=max(nums1[i-1],nums2[j-1]);
            // 如果有奇数个元素，那么直接返回左边的，因为j偏右，左边区间肯定较多方
            if((m+n) & 1==1)
                return max_of_left;
            
            if(i==m)
                min_of_right=nums2[j];
            else if(j==n)
                min_of_right=nums1[i];
            else
                min_of_right=min(nums1[i],nums2[j]);

            return (max_of_left+min_of_right)/2.0;
        }
    }
    return 0;
}


double findTopKofSortedArrays(int* array1, int len1, int* array2, int len2, int k)
{
    // 保证len1<len2
    if(len1>len2)
        return findMedianSortedArrays(array2, len2, array1, len1, k);
    // 处理边界条件
    if(len1 ==0)
        return array2[k-1];
    if(k==1)
        return min(array1[0],array2[0]);

    // 将k分为两个部分，分别在array1和array2上查找
    int k1 = min(k/2,len1);
    int k2 = k-k1;

    /*说明array2的k2-1前部分一定在第k大元素之前，因此
        1.将k2-1这部分全跳过：更新数组首位地址索引，同时更新数组长度；
        2.将这k2个元素纳入到已找到的第k大元素范围内，更新k值
    */
    if(array1[k1-1]>array2[k2-1])
        return findTopKofSortedArrays(array1,len1,array2+k2,len2-k2,k-k2);
    else if(array1[k1-1]<array2[k2-1])
        return findTopKofSortedArrays(array1+k1,len1-k1,array2,len2,k-k1);
    // 两个相等，求均值即可
    else
        return array1[k1-1];
}
/* 想清楚边界条件：首先 k 不可能是 0，其次对于1有特殊处理，那么k=2之后不断二分，永远不会出现
 k=0 的情况。这几点非常重要：
 1. len1==0的时候(因为k1<=len1)，所以必然是len1先缩减至长度为0，直接定位第二个数组
 2. k==1的时候，直接定位两个头元素最小值
 3. k1=min(k/2,len1) 防止数组长度小于k
 4. 当array1[k1-1]==array2[k2-1]时候，直接返回结果。
*/
