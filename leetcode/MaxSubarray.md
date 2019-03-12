### Max Subarray

#### 解法1：动态规划

有关子序列问题的，关键点在于记录之前子序列的最大值，如何更新最大值，同时注意游标的设置。

这里有两个变量`max_so_far`用来记录遍历至此最大的子序列的和，`max_ending_here`表示当前子序列的和，两者不断进行比较。`max_ending_here`的更新很有技巧性，如果`max_ending_here`为负，那么直接舍弃，置为0，重新开始新的子序列。如果要求开始和终止的索引，那么就必须设置游标。

另外注意，如果题目要求，子序列的长度可以为零，那么也就是最大值>=0，则`max_ending_here`和`max_so_far`的起始值设置为0；如果子序列的长度>=1，也就是不能为空，那么子序列就必须初始化为`array[0]`，而且`max_ending_here<0, max_ending_here=0`这一条也要去掉。简化为：

```python
def MaxSubarray(array):
    max_ending_here = array[0]
    max_so_far = array[0]
    for i in range(1,len(array)):
        max_ending_here = max(max_ending_here+array[i],array[i])
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far
```

游标的设置，需要两对，`j->i`用来标记`max_ending_here`；`start->end`用来标记`max_so_far`。

```python
def MaxSubarray(array):
    max_ending_here = 0
    max_so_far = 0
    start = 0
    end = 0 # 子序列 [start, end ) 左开右闭
    j = 0
    for i in range(len(array)):
        max_ending_here = max_ending_here + array[i]
        if max_ending_here < 0:
            max_ending_here = 0
            j = i+1
        elif max_ending_here > max_so_far:
            max_so_far = max_ending_here
            start = j
            end = i+1
    return start,end
```

#### 解法2：分治法(Recursive.py)

在`maxcrossSubarray`函数中，注意`lefe=right=0`的赋值，不同于`left=nums[mid-1], right=nums[mid]`，第一种情况允许子序列为空，而第二种则不然，长度至少为1。

有几个非常微妙的地方：

1. 若nums=[1,2,3,-9,-10,-2]，第一种情况直接在`maxcrossSubarray`就可以求出最优解，因为`left=6,right=0`，而第二种情况`left=6,right=-9`，因为子序列不能为空，但是`MaxSubarray`求出的最优解都是一样的，因为第二种情况会在`nums=[1,2,3]`时求出最优解。以此类推，对于`nums=[1,2,-3,-9,-10,-2]`同样第二种情况能得出最优解。
2. 如果`left=nums[mid-1],right=nums[mid]`，那么`lsum=rsum=0`的初始化仍是对的，因为`lsum, rsum`的初始化和`for num in  xxx`的起始点有关，与`left, right`的初始化无关。

```python
def maxcrossSubarray(nums,mid):
    # left = right = 0
    left = nums[mid-1]
    right = nums[mid]
    lsum = 0 
    for num in reversed(nums[:mid]):
        lsum += num
        if lsum > left:
            left = lsum
    rsum = 0
    for num in nums[mid:]:
        rsum += num
        if rsum > right:
            right = rsum
    return left + right

def MaxSubarray(array):
    if len(array)==1:
        return array[0]
    else:
        mid = len(array)//2
        left_sum = MaxSubarray(array[:mid])
        right_sum = MaxSubarray(array[mid:])
        middle_sum = maxcrossSubarray(array,mid)
        if left_sum > right_sum and left_sum > middle_sum:
            return left_sum
        elif right_sum > left_sum and right_sum > middle_sum:
            return right_sum
        else:
            return middle_sum
```