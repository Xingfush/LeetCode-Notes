### Binary Search

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

#### 延伸

上面这个形式有很多的延伸，但是根本原则是不变的，包括：

* 区间[first0, first), [last,last0)，左闭右开，这个形式的主要目的是遍历元素，没有遗漏，没有死循环；
* 按需变化，调整`if array[mid]<value`还是`if array[mid]<=value`。

##### 形式一：重现重复元素，求第一个出现的位置

```python
def BinarySearchFirst(array,first,last,key):
    res = -1
    while(first<last):
        mid = first + (last-first)//2
        if array[mid]==key:
            res = mid
            last = mid
        elif array[mid]<key:
            first = mid+1
        else:
            last = mid
    return res
```

本身这个[last,last0)就是大于等于key的区间，结束时last就是第一个不小于的元素，我们只要记录等于时候的答案就行了。

```python
def BinarySearchLast(array,first,last,key):
    res = -1
    while(first<last):
        mid = first+(last-first)//2
        if array[mid]==key:
            res = mid
            first =mid+1
        elif array[mid]<key:
            first = mid+1
        else:
            last = mid
    return res
```

 需要明白，上述访问过的元素，下一个while循环是绝对不会再访问的，因此需要记录res，而`array[mid]=key`之后`first=mid+1`还是`last=mid`决定了继续向左还是向右寻找的方向。

另外注意，这个`BinarySearchLast`和`BinarySearchFirst`和`upper_bound`，`lower_bound`一样，全部都是访问每一个元素，知道区间[first,last)为空。