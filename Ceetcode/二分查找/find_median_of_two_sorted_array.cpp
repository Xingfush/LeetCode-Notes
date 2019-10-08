double MedianOfTwoSortedArray(const vector<int>& nums1,
                              const vector<int>& nums2){
    int m = nums1.size(), n = nums2.size();
    if(m>n)
        return MedianOfTwoSortedArray(nums2, nums1);

    int imin = 0, imax = m, half_length = (m+n+1)/2;
    int max_of_left = 0, min_of_right = 0;
    // 只要还有划分点，注意两端闭合
    while(imin<=imax) { 
        int i = (imin+imax)/2, j = half_length - i;

        // 以下讨论三种情况
        // 由 i<m 可以推出 j>0，由 i>0 可以推出 j<n，这是等价条件，是后面nums[j-1]存在的必要条件
        if(i>0 && nums1[i-1]>nums2[j]) {
            imax = i-1;
        } else if(i<m && nums2[j-1]>nums1[i]) {
            imin = i+1;
        } else {
            if(i==0)
                max_of_left = nums2[j-1];
            else if(j==0)
                max_of_left = nums1[i-1];
            else
                max_of_left = max(nums1[i-1], nums2[j-1]);

            if((m+n)%2) return max_of_left;

            if(i==m)
                min_of_right = nums2[j];
            else if(j==n)
                min_of_right = nums1[i];
            else
                min_of_right = min(nums1[i], nums2[j]);

            return (max_of_left+min_of_right)/float(2);
        }
    }

    return 0;
}

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
