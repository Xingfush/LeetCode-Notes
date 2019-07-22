double findMedianOfSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size(), n = nums2.size();
    // 确保运行时间为 lg(min(m,n))
    if( m>n)
        return findMedianOfSortedArrays(nums2, nums1);

    int imin = 0, imax = m;
    int halfLen = (m+n+1)/2;
    int max_of_left = 0, min_of_right =0;

    while(imin<=imax) // 只要还有划分点，注意两端闭合
    {
        int i = (imin+imax)/2;
        int j = halfLen - i;
        // 以下讨论三种情况
        // 由 i<m 可以推出 j>0，由 i>0 可以推出 j<n，这是等价条件，是后面nums[j-1]存在的必要条件
        if(i>0 && nums1[i-1]>nums2[j])
            imax = i-1;
        else if(i<m && nums2[j-1]>nums1[i])
            imin = i+1;
        else{
            if(i==0)
                max_of_left = nums2[j-1];
            else if(j==0)
                max_of_left = nums1[i-1];
            else
                max_of_left = max(nums1[i-1], nums2[j-1]);

            if((m+n)%2==1)
                return max_of_left;

            if(i==m)
                min_of_right = nums2[j];
            else if(j==n)
                min_of_right = nums1[i];
            else
                min_of_right = min(nums1[i], nums2[j]);

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



/* 彻底分析：
A: 0....i-1 | i.....m (左边 i 个元素，右边 m-i 个元素)
B: 0.....................j-1 | j.....................n (左边 j 个元素，右边 n-j 个元素)

令 i=[0,m] 游动，那么所有的情况都会纳入，左边为0或者m，因为使用 imin<=imax
另外，halflen = (m+n+1)/2, i+j = halflen
可以推导出性质:
i>0 --> j<n
i<m --> j>0

以下讨论所有情况：
1. i<m && j>0 && nums2[j-1] > nums1[i]
2. i>0 && j<n && nums1[i-1] > nums2[j]

总共 4 个条件，共有 2^4 种情况，即：
3. i=m && nums2[j-1] > nums1[i]
4. i=m && nums2[j-1] < nums1[i]
5. i<m && nums2[j-1] < nums1[i]

6. i=0 && nums1[i-1] > nums2[j]
7. i=0 && nums1[i-1] < nums2[j]
8. i>0 && nums1[i-1] < nums2[j]

因为 i=m 时， nums1[i] 不存在，所以 3.4 归为一种
因为 i=0 时， nums1[i-1] 不存在，所以 6.7 归为一种

现在还有4 种情况
5,6 属于正常的情况，即得到了我们想要的 nums1[i-1]<=nums2[j] && nums2[j-1]<=nums2[i]，合为一种

还有两种
当 i=0 时，这代表 nums1 所有的元素全都是大于 nums2[j-1]的，因为直接取 max_of_left = nums2[j-1]
当 i=m 时，这代表 nums1 所有元素全都是小于 nums2[j]的，因此 max_of_left = max(nums[i-1],nums[j-1])

然而除了上面的情况之外，还有关于 j 的讨论：

当 j=0 时，我们有命题 i<m --> j>0 的逆否命题 j=0 --> i=m ，同时由于 i+j = halflen，
所以，此时必有 m = n，所以我们直接取 max_of_left = nums1[i-1]
当 j=n 时，同上我们有 i= 0, 由于 i+j = halflen，然后 m = n，这和 i=0 可以并为一种情况；

综上，我们只需要处理 i =0 和 j=0 两种特殊情况就行了。

*/
