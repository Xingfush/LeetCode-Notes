# Problem 1: Max-subArray when to buy and when to sell.

# Solution 1: brute-force O(n^2)
def MaxSubArray(array):
    left=0
    right=0
    maxSum=array[0]
    l=len(array)
    if l==1: return maxSum
    for i in range(l):
        curSum=0
        for j in range(i,l):
            curSum=curSum+array[j]
            if curSum>maxSum:
                maxSum=curSum
                left=i
                right=j
    return maxSum

# Solution 2: divide-and-conquer
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
    left=nums[mid-1] # 注意left的位置，mid-1
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


# Problem 2: 查找第 k 大的元素
# 这种分治法和快速排序类似
def partition(seq):
    pi = seq[0]  # 挑选主元
    lo = [x for x in seq[1:] if x <  pi]  # 所有小的元素
    hi = [x for x in seq[1:] if x >= pi]  # 所有大的元素
    return lo, pi, hi

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


if __name__ == '__main__':
    A=[2,-5,3,7,-11,8,-10,-3,6]
    print("The max subarray is:",MaxSubArray(A))