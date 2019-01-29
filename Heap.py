from heapq import heapify,heappush,heappop,nsmallest

# 关于heapq使用的简要说明：
# 创建：1.initialied as [] 2.transform a list into a heap via function heapify()
# 特点：1.index从0开始 2.heap[0]返回最小值，而不是最大值
# 关键字排序的使用，key=callable object，输入iterable的元素，输出为值，可以比较的值
portfolio = [
    {'name': 'IBM', 'shares': 100, 'price': 91.1},
    {'name': 'AAPL', 'shares': 50, 'price': 543.22},
    {'name': 'FB', 'shares': 200, 'price': 21.09},
    {'name': 'HPQ', 'shares': 35, 'price': 31.75},
    {'name': 'YHOO', 'shares': 45, 'price': 16.35},
    {'name': 'ACME', 'shares': 75, 'price': 115.65}
]
cheap = nsmallest(3, portfolio, key=lambda s: s['price'])
# expensive = nlargest(3, portfolio, key=lambda s: s['price'])

# Problem 0: 使用heapq实现优先级队列
import heapq
import itertools
counter=itertools.count()
REMOVED='removed-task'
class PriorityQueue:
    def __init__(self):
        self._queue=[]
        self._entry_finder={}
    def push(self,item,priority=0):
        if item in self._entry_finder: # 相当于对已有任务更新priority
            self.remove_item(item)
        self._index=next(counter)
        entry=[-priority,self._index,item]
        self._entry_finder[item]=entry # 此处字典加入是引用传递，只是dict[item]指向了entry
        heappush(self._queue,entry)
    def remove(self,item):
        entry=self._entry_finder.pop(item)
        entry[-1]=REMOVED # 此处改变entry，即heapq里指向的entry也会随之改变
    def pop(self):
        while self._queue:
            priority,index,item=heappop(self._queue)
            if item is not REMOVED:
                del self._entry_finder[item]
                return item
        raise KeyError('pop from an empty priority queue')
# 当加入多级元组时，heapq会自动进行多级比较，只要手动加入二级index即可。


# Problem 1: 找到第Kth的元素
def findKthLargest(nums,k):
    if k>len(nums) or not nums:
        return -1
    heap=[-num for num in nums] # o(n)
    heapify(heap) # o(n)
    for _ in range(k-1):
        heappop(heap) # k*lg(n)
    return -heappop(heap)

# Problem 2: Top K 数字统计
def topKFrequent(nums, k):
    dic = {}
    heap = []
    res = []
    for num in nums:
        if num in dic:
            dic[num]+=1
        else:
            dic[num]=1
    for key in dic:
        heappush(heap, (-dic[key], key))

    for i in range(k):
        res.append(heappop(heap)[1])

    return res

# 使用优先队列和Counter进行 Top K Frequent Word
def topKFrequentW(words,k):
    dic={}
    heap=[]
    res=[]
    for word in words:
        if word in dic:
            dic[word]+=1
        else:
            dic[word]=1

    for key in dic:
        heappush(heap,(-dic[key],key))


if __name__ == '__main__':
    # a=[1,1,1,2,2,3]
    # print('Top K frequent elements:',cheap)
    h=heapq()
    h.push('write code',5)
    h.push('release product',7)
    h.push('write poet',5)
    h.push('go dancing',5)
    h.push('study painting',3)
    h.push('prepare test',1)
