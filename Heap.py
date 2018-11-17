from heapq import heapify,heappush,heappop

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
    a=[1,1,1,2,2,3]
    print('Top K frequent elements:',topKFrequent(a,2))