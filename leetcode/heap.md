## Binary Heap

满足以下性质的二叉树`Binary Tree`可以成为`Binary Heap`：

1. `Complete Tree`：所有的层都是完全的，除了最后一层，且最后一层的叶子靠左。
2. `Min Heap or Max Heap`：根节点是最大值或者最小值，而且这个性质对于任何递归得到的子树都成立。

`Binary Heap`通常使用`array`表示：

1. 根节点在`array[0]`;
2. `array[(i-1)//2]`返回父节点，`array[2*i+1]`返回左孩子树，`array[2*i+2]`返回右孩子树。

![img](https://www.geeksforgeeks.org/wp-content/uploads/binaryheap.png)

## Implementation

### 1.Heap

#### 1.表示方法

`Binary Heap`通常使用`array`表示，对于任意索引`i`：

```python
def parent(i):
    return (i-1)//2
def left(i):
    return 2*i+1
def right(i):
    return 2*i+2
```

#### 2.`Max-Heapify`

`max heapify`是保持`max-heap`性质的操作，输入为`array A and index i`，假设输入时，以`left(i) and right(i)`为根节点的子数都满足最大堆性质，但是以`i`为根节点的子数不满足最大堆性质。`max heapify`函数让`A[i]`向下层转移，进行调整。

```python
def MaxHeapify(array,i):
    l = left(i)
    r = right(i)
    largest = i
    if l<=len(array) and array[l]>array[i]:
        largest = l
    if r<=len(array) and array[r]>array[i]:
        largest = r
    if largest != i:
        array[largest],array[i] = array[i],array[largest]
        MaxHeapify(array,largest)
```

**时间复杂度分析：**

在一个以`i`作为根节点、包含`n`个节点的子数上运行`MaxHeapify`的时间包含：调整`largest`常数时间，孩子子树运行`MaxHeapify`的时间。由于孩子子数最多有`2n/3`个节点（这种情况只会发生在最底层节点刚好是 *half full* 的情况），因此可以描述为以下形式：

$ T(n)\leq T(2n/3)+\Theta(1)$

按照公式法可以得到时间复杂为`O(lgn)`。

#### 3.`Build-Max-Heap`

`MaxHeapify`前提条件是以`left(i) and right(i)`根节点的子数都是满足最大堆性质的，那么显然如果我们从最底层的子数开始，逐渐往上，对每个节点执行`MaxHeapify(array,i)`操作，那么这个堆所有的节点都满足最大堆性质，变为最大堆。但是，如果我们从最上层开始执行`MaxHeapify`，那么显然不满足前提条件。

另外具体从哪个节点开始呢，`heap`有个性质，对于`array[0,1,...,n-1]`的数组，`array[(n-1)//2+1:n-1]`的节点全是叶节点，而叶节点是不需要`MaxHeapify`操作的，所以我们只对`array[:(n-1)//2]`的元素进行操作：

```python
def BuildMaxHeap(array):
    for i in reversed(range((len(array)-1)//2+1)):
        MaxHeapify(array,i)
```

计算得到`BuildMaxHeap`的时间复杂度为`O(n)`，也就是说堆的建立是线性时间，而不是`O(nlgn)`，这是堆相对于普通排序最大的优点之一。

#### 4.`HeapSort`

`heapsort`的时间复杂度为`O(nlgn)`，而且是就地排序算法，除输入数组只外只占用恒定的内存空间，这兼具了`insertion sort`（就地排序）和`merge sort`（时间复杂度）的优点。

堆排序的思想就是，不断地弹出根节点，也就是当前堆的最大值，把它放到`array`的最后，同时把堆最后的叶节点放到新堆根节点的位置，就是做了一个交换，然后对新的堆进行`MaxHeapify`，注意此时新堆根节点的子堆都是符合最大堆性质的，只有根节点一个不符合，所以对它做一次`MaxHeapify`就可以使堆变为最大堆。这样不断地向前推进，直至第一个元素。

```python
def MaxHeapify(array,n,i):
    l = 2*i+1
    r = 2*i+2
    largest = i
    if l<=n and array[l]>array[largest]:
        largest = l
    if r<=n and array[r]>array[largest]:
        largest = r
    if largest != i:
        array[largest],array[i] = array[i],array[largest]
        MaxHeapify(array,n,largest)

def HeapSort(array):
    n = len(array)
    for i in reversed(range(n//2)):
        MaxHeapify(array,n-1,i)
    for i in reversed(range(1,len(array))):
        array[i],array[0] = array[0],array[i]
        n -= 1
        MaxHeapify(array,n-1,0)
    return array
```

**注意：**这里有个常见的编程错误，`HeapSort`开头已经定义`n=len(array)`，后面使用`for i in reversed(range(1,len(array))):`中的`len(array)`而不是`n`，因为内部代码块中`n-=1`时刻在变化。这个地方是非常容易出错的，这启发我们在定义变量的时候，要第一点想到这个变量是干什么用的，能用在那哪些地方，而不是简单地静态地看待变量的值。

程序中所有的变量本质上都是动态地，变化的，一定要动态的分析，变量间的关系和边界条件，这才是算法的核心。

#### 5.`Max-Heap-Insert`

和快速排序相比，堆排序并不占优势，虽然二者时间复杂度都是`O(nlgn)`，堆最广泛的应用为`Priority Queues`优先队列。

>***Priority Queue*** is a data structure for maintaining a set $S$ of elements, each with an associated value called a $key$.   It is widely applied in job scheduling or event-driven simulation.                                                                                   --- *Introduction to Algorithm*
>
>很像Python中字典这个数据结构 Key-value，键值对

一个`Max-priority queue`应该支持以下操作：

* `Insert(S,x)`将一个元素插入集合；
* `Maximum(S)`返回队列中key 值最大的元素；
* Increase-key(s,x,k)`修改队列元素，使得元素`x`的key value变为k。

```python
def HeapMaximum(array):
    return array[0]

def HeapExtractMax(array,n):
    if n<=0:
       raise "heap underflow error"
    Max = array[0]
    array[0] = array[n]
    n -= 1
    MaxHeapify(array,n,0)
    return Max
# 这里统一，使用n作为堆在array中最后一个元素的索引，而不是元素个数

def HeapIncreaseKey(array,i,key):
    if key<array[i]:
        raise "New key value is smaller than current key."
    array[i] = key
    while i>0 and array[parent(i)]<array[i]:
        array[i],array[parent(i)] = array[parent(i)],array[i]
        i = parent
        
def MaxHeapInsert(array,n,key):
    n += 1 # 堆的大小要相应地改变
    array[n] = key
    HeapIncreaseKey(array,n,key)
```

`HeapIncreaseKey`操作和`InsertSort`操作的思想是一致的，给新元素找到合适的位置，这个合适的位置如何确定，有两个关键点，方向和终止条件。此处，由于是key的值增大了，所以方向是向根节点移动，不断地使用`parent(i)`替换`i`。另一个是终止条件，`i>0`表示不能超过根节点，`array[parent(i)]<array[i]`表示此时已经满足最大堆性质。此操作的时间复杂度，显然是`O(lg(n))`的，因为移动路径的长度。

类似的，如果是`HeapDecreaseKey`，那么相应的，移动的方向和终止条件也要改变。

`MaxHeapInsert`操作以`HeapIncreaseKey`为基础，首先插入一个无穷小key值得元素，然后然后执行`HeapIncreaseKey`操作。运行时间显然是一样的。

#### 5.Python Package for Heap

`heapq`模块使用Python `list`完成，里面包含了操作`heappush`，`heappop`，`heapify`，`heapreplace`，`merge`，`nlargest`，`nsmallest`，`heappushpop`. 这里的`heap`使用`list`完成。和算法导论中的例子不同，这里的实现：

* 使用 0-based indexing；
* 建立最小堆，而不是最大堆；

```python
# 基本使用
heap = []
heappush(heap,item)
item = heappop(heap)
item = heap[0]
heapify(x)
item = heapreplace(heap,item)
```


## Examples
### 1.Merge Two Sorted Lists

`Min Heap` 来解决这类问题，假设有k个sorted lists，每个list有n各元素（不要求每个list元素数目相等），具体的解决算法如下：

1. 建立一个输出array，尺寸为n*k;
2. 创建一个大小为k的堆，将每个list的第一个元素插入；
3. 然后重复以下步骤 n*k步：
   1. 取堆的最小元素放入 output array
   2. 如果某个堆的元素被弹出放入了array，那么取出下一个元素替换堆的根节点，如果这个array没有元素了，那么就用正无穷替代。替换之后，`heapify`这个堆。

```python
from heapq import heapify,heappop,heappush,heapreplace

def Merge(*iterables):
    output = []
    h = []
    for order,it in enumerate(map(iter,iterables)):
        try:
            next = it.__next__
            h.append([next(),order,next])
        except StopIteration:
            pass
    heapify(h)
    while len(h) > 1:  # 终止条件是堆中有元素
        try:
            while True:
                value, order, next = s = h[0]  # 取出堆的根节点
                output.append(value)
                s[0] = next() 
                
                # raises StopIteration when exhausted
                heapreplace(h, s)  # restore heap condition
        except StopIteration:
            heappop(h)  # remove empty iterator
    if h:
        # fast case when only a single iterator remains
        value, order, next = h[0]
        try:
            while True:
                output.append(value)
                value = next()
        except StopIteration:
            pass
    return output
```

上述实现基本按照所述算法的思路，有两个需要注意的地方：

1. 变量order用于对相同value的元素进行排序，这是`heapify`中的多重排序默认设置；
2. 

这里简要的复习一下两个知识点：

1.`iter()` and `next()`

上面两个Python内置方法用于迭代器操作。迭代器是一个可以记住遍历的位置的对象，从集合的第一个元素开始访问，直到所有的元素被访问结束，迭代器只向前去而不会后退。使用`next()`函数操作迭代器，当索引超过范围时，会引发`StopIteration Error`。

```python
# 创建
# 字符串，列表，元组 都可以用于创建迭代器
a = [1,2,3,4]
it = iter(list)
next(it)
next(it)

# 使用 for 语句进行遍历
for i in it:
    print(i)

# 使用 next() 函数
while True:
    try:
        print(next(it))
    except StopIteration:
        sys.exit()
```

将一个对象创建为迭代器很简单，只要加上`__iter__()`和`__next__()`方法即可。

`__iter__()`方法返回一个特殊的迭代器对象，这个迭代器对象实现了`__next__()`方法并且通过`StopIteration`异常标志索引迭代结束。

`__next__()`会返回下一个迭代器对象。

```python
class MyNumbers:
    def __iter__(self):
        self.a = 1
        return self
    def __next__(self):
        x = self.a
        self.a += 1
        return x
myclass = MyNumbers()
myiter = iter(myclass)
next(myiter)
next(myiter)
```

2.`yield`与生成器

Python中使用了`yield`的函数被称为生成器，这里注意，生成器是一个函数(generator)。

只能用于迭代操作，简单地可以把生成器理解为迭代器。调用生成器的过程中，每次遇到yield时，函数会暂停并保存当前所有的运行信息，并且返回yield的值，并且在下次执行next()方法时从当前位置继续执行。

```python
# 例：斐波那契数列
def fibonacci(n):
    a,b,counter = 0,1,0
    while True:
        if counter>n:
            return
        yield a
        a,b = b, a+b
        counter += 1
f = fibonacci(10)
while True:
    try:
        print(next(f))
    except StopIteration:
        sys.exit()
# 依然使用next()和StopIteration控制调用
```

3.异常处理

`try...except xxx`按照如下方式工作：

1. 首先，执行`try`子句（在try 和 except之间的语句；
2. 如果没有异常发成，忽略except 子句，try 子句执行后结束；
3. 如果在执行try子句时候发生了异常，那么try子句余下部分将被忽略，如果异常的类型和except后的异常相同，那么except后面的子句将会被执行。
4. 如果没有一个异常能够与except匹配，那么这个异常将会传递给上层的try。

注意：

1. 一个try语句可以包含多个except子句用于处理多个不同的异常。
2. 一个except可以处理多个异常，用元组进行表示。
3. 最后一个except子句可以忽略异常的名称，它将被当做通配符使用，可以用它来打印错误信息，然后再次把异常抛出。
4. `try ...except..`有一个可选的`else`语句，如果使用这个子句，那么必须放在所有的except之后使用，这个字句将在没有任何异常发生时执行。

`raise`关键词用于抛出一个指定的异常，唯一的参数必须是一个异常的实例或者异常的子类。

用户可以自定义异常类。

