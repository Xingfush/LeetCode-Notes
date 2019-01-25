## 目录

1. Longest Increase Subsequence
2. Binary Search (lower_bound and upper_bound)
3. Longest Common Subsequence

### 1.Longest Increase Subsequence

本题的核心为如何在O(n)的时间复杂度解决问题，一次遍历，如何进行找出最长的上升子序列。

1. tailTable记录了各个长度上升子序列末尾元素的值，首先明确必须要记录各个长度上升子序列，任何子序列后面都有可能成为最长子序列；
2. 如果不需要恢复最长子序列，那么是否要记录所有的元素的，显然，只要记录各个子序列的末尾元素即可；
3. 新的元素如何处理，和各个子序列的末尾元素进行比较，更新各个长度的最长的上升子序列，分三种情况最好；

### 2.Binary Search

- [first, last) 左开右闭；
- 因为左开右闭，索引while first<last可以保证终止时区间为0；
- `mid=first+(last-first)//2` 是为了保证长度为1时，mid仍在[first,first+1)区间内；
- 循环不变式为[first, last)区间的左侧区间[first0,first)的元素全部<value，右侧[last,last0)全部>=value；
- 终止时first=last，按条件可以保证上面的循环不变式成立。 该问题分为求上界和求下界两类：
- 求下界，即找满足`x>=value`或`x>value`条件的最小的`x`的值，因最小而称为求下界；
- 求上界，即找满足`x<=value`或`x<value`条件的最大的`x`的值，因最大而称为求上界； 上界问题和下界问题本质一样，结果相差1，只要记住标准的求下界解法即可。

```python
def BinarySearch(array,first,last,value):
    # 求下界（x>=value），return first
    # 求上界（x<value），return first-1
    while first<last:
        mid=first+(last-first)//2
        if array[mid]<value:
            first=mid+1
        else:
            last=mid
    return first
```

**注意：**

1. 这里`BinarySearch`有个非常好的性质，当value>max(array)时，函数返回len(array)；当value<=min(array)，return 0。这两个边界结果都是符合逻辑的。
2. 上述实现中的if..else条件。若将if..else改为`if array[mid]<=value`，则实现了求下界（x>value,return first），求上界（x<=value,return first-1）。这种互补的效果利于记忆。

### 3.Longest Common Subsequence

使用动态规划的思想，bottom up方法，注意边界起始条件为0，也就是形状为$m\times n$的矩阵的上边和左边为零，使用`numpy`利于设置。

### 4.Longest Increase Subsequence

和题目1`longest increase sequence`对比，本题要求子序列必须是连续的，是原序列一个完整的部分。在遍历时候，只需要记录**最长的子序列**（而不是所有长度子序列）的长度即可。技巧是游标的设置，一段子序列的起点由`j`标定，具体关于`j`的更新。

```python
def LongestIncreaseSubsequence(num):
    res = 1
    j = 0
    for i in range(1,len(num)):
        if num[i] < num[i-1]: # 设置游标，j为一个子序列的起点
            j = i
        res = max(res,i-j+1)
    return res
```

