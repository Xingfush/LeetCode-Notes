from heapq import heapify,heappop

def findKthLargest(nums,k):
    if k>len(nums) or not nums:
        return -1
    heap=[-num for num in nums] # o(n)
    heapify(heap) # o(n) time to build a heap
    for _ in range(k-1):
        heappop(heap) # k*lg(n)
    return -heappop(heap)
