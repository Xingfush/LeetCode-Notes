from heapq import heappush,heappop
import itertools

# 关于heapq使用的简要说明：
# 创建：1.initialied as [] 2.transform a list into a heap via function heapify()
# 特点：1.index从0开始 2.heap[0]返回最小值，而不是最大值

counter=itertools.count()
REMOVED='removed-task'
class PriorityQueue:
    def __init__(self):
        self._queue=[]
        self._entry_finder={}
    def push(self,item,priority=0):
        if item in self._entry_finder: # 相当于对已有任务更新priority
            self.remove(item)
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

