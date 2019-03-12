def MaxSubarray(array):
    max_ending_here = 0
    max_so_far = 0
    for i in range(len(array)):
        max_ending_here += array[i]
        if max_ending_here < 0:
            max_ending_here = 0
        elif max_ending_here > max_so_far:
            max_so_far = max_ending_here
    return max_so_far

def MaxSubarray2(array):
    max_ending_here = array[0]
    max_so_far = array[0]
    for i in range(1,len(array)):
        max_ending_here = max(max_ending_here+array[i],array[i])
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

def MaxSubarray3(array):
    max_ending_here = 0
    max_so_far = 0
    start = 0
    end = 0 # 子序列 [start, end ) 左开右闭
    j = 0
    for i in range(len(array)):
        max_ending_here = max_ending_here + array[i]
        if max_ending_here < 0:
            max_ending_here = 0
            j = i+1
        elif max_ending_here > max_so_far:
            max_so_far = max_ending_here
            start = j
            end = i+1
    return start,end

def MaxSubarray4(array):
    max_ending_here = array[0]
    max_so_far = array[0]
    start = 0
    end = 1
    j = 0
    for i in range(1,len(array)):
        if max_ending_here < 0:
            max_ending_here = array[i]
            j = i # 此处和3的解法不同，需要注意
        else:
            max_ending_here += array[i]
        if max_so_far < max_ending_here:
            max_so_far = max_ending_here
            start = j
            end = i+1
    return start,end

# 使用分治法
def MaxSubarray5(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    if len(nums)==1:
        return nums[0]
    else:
        mid=len(nums)//2
        left_sum=MaxSubarray5(nums[:mid])
        right_sum=MaxSubarray5(nums[mid:])
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

# Brute-Force 暴力破解法
def MaxSubarray6(array):
    maxSum = array[0]
    start = 0
    end = 1
    for i in range(len(array)):
        curSum = 0
        for j in range(i,len(array)):
            curSum += array[j]
            if curSum > maxSum:
                maxSum = curSum
                start = i
                end = j+1 # 左开右闭
    return start,end


if __name__=='__main__':
    print(MaxSubarray5([-2, 3, -5, 6, 7, 10, -9, -12]))