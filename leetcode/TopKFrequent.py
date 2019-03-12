from heapq import heappush,heappop
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