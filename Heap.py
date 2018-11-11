def maxSubArray(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    if len(nums)==1:
        return nums[0]
    else:
        mid=len(nums)//2
        left_sum=maxSubArray(nums[:mid])
        right_sum=maxSubArray(nums[mid:])
        cross_sum=maxcrossSubArray(nums,mid)
        if left_sum>=right_sum and left_sum>=cross_sum:
            return left_sum
        elif right_sum>=left_sum and right_sum>=cross_sum:
            return right_sum
        else:
            return cross_sum

def maxcrossSubArray(nums,mid):
    left=nums[mid-1]
    Sum=0
    for num in reversed(nums[:mid]):
        Sum+=num
        if Sum>left:
            left=Sum
    right=nums[mid]
    Sum=0
    for num in nums[mid:]:
        Sum+=num
        if Sum>right:
            right=Sum
    return left+right

# 这种分治法和快速排序类似
def partition(seq):
    pi = seq[0]  # 挑选主元
    lo = [x for x in seq[1:] if x <  pi]  # 所有小的元素
    hi = [x for x in seq[1:] if x >= pi]  # 所有大的元素
    return lo, pi, hi


# 查找第 k 大的元素
def select(seq, k):
    # 分解
    lo, pi, hi = partition(seq)

    m = len(hi)
    if m == k-1:
        return pi  # 解决！
    elif m > k-1:
        return select(hi, k)  # 递归（树），分治
    else:
        return select(lo, k-1-m)  # 递归（树），分治

# 简单堆 python 实现

def PARENT(i):
    return i//2

def LEFT(i):
    return 2*i+1 # 从0计数，需要注意

def RIGHT(i):
    return 2*i+2 # 从0计数，需要注意


def MAX_Heapify(heap,HeapSize,i): # 加上HeapSize这个属性，方便后面改变Heap
    l,r=LEFT(i),RIGHT(i)
    largest=i
    if l<HeapSize and heap[largest]<heap[l]:
        largest=l
    if r<HeapSize and heap[largest]<heap[r]:
        largest=r
    if largest!=i:
        heap[i],heap[largest]=heap[largest],heap[i]
        MAX_Heapify(heap,HeapSize,largest) # 就地操作，这里不需要返回值

def Build_MAX_Heap(heap):
    HeapSize=len(heap)
    for i in range(HeapSize//2-1,-1,-1): # HeapSize//2后面要再减1，和0对应
        MAX_Heapify(heap,HeapSize,i)

def HeapSort(heap):
    Build_MAX_Heap(heap)
    for i in range(len(heap)-1,-1,-1):
        heap[0],heap[i]=heap[i],heap[0]
        MAX_Heapify(heap,i,0)
    return heap

from heapq import heapify,heappush,heappop

def findKthLargest(nums,k):
    if k>len(nums) or not nums:
        return -1
    heap=[-num for num in nums] # o(n)
    heapify(heap) # o(n)
    for _ in range(k-1):
        heappop(heap) # k*lg(n)
    return -heappop(heap)

# Top K 词频统计
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
    a=[1,1,1,2,2,3]
    print('Top K frequent elements:',topKFrequent(a,2))