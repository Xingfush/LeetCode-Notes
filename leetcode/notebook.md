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

### 5.Longest Unique Subsequence

本题的思路和4基本一致，记录最大值和更新游标，唯一不同的是判别条件。如何判别子序列中含有重复元素，显然使用哈希表，python中集合和字典均可以实现哈希表。

要区分清楚，对于字典`dict.get(key,default_value)`仅用于`read`键为空返回默认值，不能用于设置时候使用。另外，推荐使用`dict.pop`方法进行删除键，键不存在时可以设置默认返回值。

注意集合的使用：

```python
st = set() # 初始化
st.add('a') # 添加元素
st.remove('b') # 删除元素
st.discard('c') # 删除元素，元素不存在不会出错
set1 & set2 # 集合与
set1 | set1 # 集合并
```

### 6.Two Sum

使用哈希表，此题最优解法的技巧性较强，多加记忆理解。

```python
def TwoSum(num,value):
    dic = {}
    res = []
    for i in range(len(num)):
        if num[i] in dic:
            res.append([i,dic[num[i]]])
            dic.pop(num[i])
        else:
            dic[value-num[i]] = i
    return res
```

### 7.Max Subarray

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

### 8.Add Parentheses

本题的递归形式和前面不太相同，虽然都是分治法的思想，但是合并的时候，`Max Subarray`是子问题返回一个值到上层问题，而`Add Parentheses`是返回一个list，该list中包含所有的`possible value`，这样的list逐级合并（乘式）。以operator为中点左右分割，终止条件是剩余项是否是数字。

递归的思想体现：只要解决该阶段的问题就行，找出该子数组所有的组合，并返回上级即可。

这里附上使用列表推导式的实现（乘式递归）：

```python
def AddParentheses2(input):
    return [a+b if c=='+' else a-b if c=='-' else a*b
            for i,c in enumerate(input) if c in '+-*'
            for a in AddParentheses(input[:i])
            for b in AddParentheses(input[i+1:])] or [int(input)] 
# 一个元素仍要以列表形式返回
```

另外，需要注意，在`input`是正确的情况下（单个数字，或者两端是数字），`input[i+1:]`的使用不需要提前检验元素的存在性。

### 9.Merge Sort

使用分治法的典型例子，将array分为两个子数组，子数组排序之后，再进行合并。显然，如果对于每个子数组进行复制，而不是就地排序，那么空间占用将达到`O(nlg(n))`，这是非常大的内存开销，所以这里**通过索引的变化来定义子数组**。这个问题的关键是索引的变化千万不能出错，推荐这种情况下统一使用左闭右开的数组表示法。

特点如下：

* **连续性：**`[left,right)`直接分为`[left,mid)`+`[mid,right)`。
* **完整性：**`[left,right)`中元素的数目等于`right-left`

这两个性质是的左闭右开的表示法在具体的编程实践中避免了代码冗余和易错。

另外，对于mid中点的计算，统一使用`l+(r-l)//2`的方式，如果是左开右闭，那么使用`r-(r-l)//2`，这样可以避免溢出。

```python
def merge(arr,l,m,r): # 传入m参数是必要的，下有对应
    n1 = m-l # 简洁性可见一斑
    n2 = r-m
    L = [0]*n1 # 一般避免使用append,extend这些不定长度的list，占内存过大
    R = [0]*n2
    for i in range(n1):
        L[i] = arr[l+i]
    for j in range(n2):
        R[j] = arr[m+j]
    i = j =0
    k = l
    while i<n1 and j<n2: 通过i,j游标来判断是否结束，而不是通过数组为空判别
        if L[i]<R[j]:
            arr[k]=L[i]
            i += 1
        else:
            arr[k]=R[j]
            j += 1
        k += 1
    while i<n1:
        arr[k] = L[i]
        i += 1
        k += 1
    while j<n2:
        arr[k] = R[j]
        j += 1
        k += 1
    return arr

def MergeSort(array,l,r): # 通过索引定义子序列，显然参数必得传入l,r
    if r-l<2:
        return array
    else:
        m = l+(r-l)//2
        MergeSort(array,l,m)
        MergeSort(array,m,r)
        merge(array,l,m,r)
    return array
```

### 10.Insert Sort

理解了新元素插入的过程，那么实现就很简单了。有两点需要注意：

1. `for i in range(1,len(array))`后面无论如何更改`i`的值（本题中使用`i`作为游标值，不断后退找到插入位置），都不会影响循环，当再次运行到`for`语句时，`i`照常。
2. 使用`key=array[i]`有保存当下元素的作用，因为就地排序`array[i]`会发生改变。另外注意，寻找合适插入位置时，索引是由范围的`while key<array[i-1] and i>0`中的`i>0`很重要。