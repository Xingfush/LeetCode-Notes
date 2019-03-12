### Quick Sort

#### 1.思想：

1. 取一个参考值，让序列所有的元素排序后，左侧子序列的值都比参考值小，右侧子序列的值都比参考值大。
2. 分别对左侧和右侧的子序列做1中的递归操作。

#### 2.Lomuto partition scheme：

《Programming Pearls》and 《Introduction to Algorithms》都采用这种框架。这个框架通常选择最后一个元素作为`pivot`，设置游标`i`，使用`j`作为索引遍历数组，保证游标`i`左侧的元素都`<= pivot`，右侧的元素全都`>pivot`。

```python
def partition(array, l, r):
    pivot = array[r]
    i = l - 1
    for j in range(l, r):
        if array[j] <= pivot:
            i += 1
            array[i], array[j] = array[j], array[i]
    array[i + 1], array[r] = array[r], array[i + 1]
    return i + 1

def partition(array, l, r):
    pivot = array[r]
    i = l
    for j in range(l, r):
        if array[j] <= pivot:
            array[i], array[j] = array[j], array[i]
            i += 1
    array[i], array[r] = array[r], array[i]
    return i

# from wikipedia
```

#### 3.Hoare partition scheme

> --- From wikipedia
>
> 该方法设置两个索引，从数组的两端相向移动，直到它们分别发现了可转换的元素：左索引`array[i]>pivot`，右索引`array[j]<=pivot`，显然，这两个位置的元素应该交换。当两个索引相遇，停止移动，返回最后一个index。
>
> *优点*
>
> 1. 效率高，交换次数相当于**Lumoto** 方法的1/3，平均来看；
> 2. 对于等值数组，交换次数为0；
> 3. 对于已排序数组，`pivot=array[first],array[last]`都会导致$n^2$的时间复杂度，而`pivot=array[mid]`反而会达到最优时间复杂度$n lg(n)$。 

```pseudocode
algorithm quicksort(array, l, r) is
	if l<r then
		p := partition(array, l, r)
		quicksort(array, l, p)  // 没有间隔元素
		quicksort(array, p+1, r)
		
algorithm partition(array, l, r) is
	pivot := array[(l+r)//2]
	i := l -1
	j := r +1
	loop forever
		do
			i := i+1
		while A[i]<pivot
		do
			j := j-1
		while A[j]>pivot
		if i>=j then
			return j
		swap A[i] with A[j]
```

**Python Implementation-1**

```python
---- Modified from wiki
def partition(array,l,r):
    pivot = array[l] 
    left = l +1 
    right = r 
    while left <= right:
        while left <= right and array[left] <= pivot:
            left += 1
        while left <= right and array[right] >= pivot:
            right -= 1
        if left <= right:
            array[left],array[right] = array[right],array[left]
    array[l],array[right] = array[right],array[l]
    return right

---- Copy online
def partition(array,l,r):
    pivot = array[l]
    left = l+1
    right = r
    done = False
    while not done:
        while left<=right and array[left]<=pivot:
            left += 1
        while left<=right and array[right]>=pivot:
            right -= 1
        if right < left:
            done = True
        else:
            array[left],array[right]= array[right],array[left]
    array[right],array[l]= array[l],array[right]
    return right
```

边界条件分析：为什么`array[l],array[right] = array[right],array[l]`是对的

1. `array[left]<=pivot`时，`left`会不断增加，但是由于前面有`array[right]>pivot`阻隔，至多到`left=right`，然后`right`还可以左移一位，从而使`left>right`，此时`array[left]>pivot,array[right]<=pivot`显然交换是对的；
2. `array[left]>pivot`时，`left`暂停，`array[right]>=pivot`不断左移，至`right=left`，此时`right`再左移一位，`right<left, array[left]>pivot,array[right]<=pivot`；
3. 所有的情况只有上面两种结局，最后的状态都是`array[right]<=pivot,array[left]>pivot`（等值数组显然不是这种情况）。

**Python Implementation-2**

```python
def QuickSort(array,l,r):
    if l>=r:
        return
    left = l
    right = r
    pivot = array[left]
    while left < right:
        while left < right and array[right] > pivot:
            right -= 1
        array[left] = array[right]
        while left < right and array[left] <= pivot:
            left += 1
        array[right] = array[left]
    array[right] = pivot
    QuickSort(array, l, left-1)
    QuickSort(array, left+, r)
    return array
```

**边界条件分析：**

1. `while left<right`终止条件为`left=right`，保证不会出现索引溢出。
2. 若`array[right]>pivot`使`right -= 1`直至`left=right`，由于此时`array[left]<=pivot`，那么整个过程相当于交换了`array[left] and array[right]`。
3. 若`array[right]<=pivot`且`left<right`，那么`array[right]`先复制进`left`位置，当`array[left]<=pivot`使得`left+=1`直至`left=right`时，注意此时`array[right]<=pivot`但是`left<right`的限制使得至多`left=right`。
4. 所有的情况都可以归结为这两种结束方式，`left added to right` or `right decreased to left`，构成一个交换的闭环。

另外一点需要注意的是，`array[right]>pivot and array[left]<=pivot`一定是完整的`> and <=`，不然无法处理元素和`pivot`相等的情况，而且由于不是`>= and <=`，`right and left`至多以`=`结束，不会出现上面实现方式中的`left>right`，所以终止判别条件是`left<right , instead of left<=right`。 