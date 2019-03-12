### Merge Two Sorted Arrays

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