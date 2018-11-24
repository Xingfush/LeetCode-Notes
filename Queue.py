# This file fullfill the implementation of Stack in Python and Some typical problems.

# Implementation of Queue using an Array Circularly
class Empty(Exception):
    """Error attempting to acess an element from an empty container."""
    pass

class ArrayQueue:
    """FIFO queue implementation using a Python list as underlying storage."""
    DEFAULT_CAPACITY=10 # 类的变量，而不是对象的成员

    def __init__(self):
        self._data=[None]*ArrayQueue.DEFAULT_CAPACITY
        self._size=0
        self._front=0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size==0

    def first(self):
        if self.is_empty():
            raise Empty('Queue is empty')
        return self._data[self._front]

    def dequeue(self):
        """Remove and return the first element of the queue."""
        if self.is_empty():
            raise Empty('Queue is empty')
        answer=self._data[self._front]
        self._data[self._front]=None # 原位置变为None
        self._front=(self._front+1)%len(self._data) # front 加1
        self._size-=1 # 尺寸-1
        if 0<self._size<len(self._data)//4:
            self._resize(len(self._data)//2)
        return answer

    def enqueue(self):
        """Add an element to the back of queue."""
        if self._size==len(self._data):
            self._resize(2*len(self.data)) # 将队列的尺寸扩大二倍
        avail=(self._front+self._size)%len(self._data) # avail的位置等于front+size，刚好是可以插入的位置
        self._data[avail]=e
        self._size+=1

    def _resize(self,cap):
        old=self._data
        self._data=[None]*cap
        walk=self._front
        for k in range(self._size): # 把现有元素全都转到新数组的前面，重置front=0，size不变
            self._data[k]=old[walk]
            walk=(1+walk)%len(old) # use old size as modulus进行从头到尾的遍历
        self._front=0




