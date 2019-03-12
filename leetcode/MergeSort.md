### Merge Sort

使用分治法的典型例子，将array分为两个子数组，子数组排序之后，再进行合并。显然，如果对于每个子数组进行复制，而不是就地排序，那么空间占用将达到`O(nlg(n))`，这是非常大的内存开销，所以这里**通过索引的变化来定义子数组**。这个问题的关键是索引的变化千万不能出错，推荐这种情况下统一使用左闭右开的数组表示法。

特点如下：

- **连续性：**`[left,right)`直接分为`[left,mid)`+`[mid,right)`。
- **完整性：**`[left,right)`中元素的数目等于`right-left`

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

