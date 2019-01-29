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

>***Priority Queue*** is a data structure for maintaining a set $S$ of elements, each with an associated value called a $key$.   It is widely applied in job scheduling or event-driven simulation.                 -- *Introduction to Algorithm*
>
>很像Python中字典这个数据结构 Key-value，键值对

一个`Max-priority queue`应该支持以下操作：

* `Insert(S,x)`将一个元素插入集合$S$
* `Maximum(S)`返回队列中key 值最大的元素
* `Increase-key(s,x,k)`修改队列元素，使得元素`x`的key value变为k。



## Examples

