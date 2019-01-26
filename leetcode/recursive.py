# Example 1: Max Subarray

def maxcrossSubarray(nums,mid):
    left = right = 0
    lsum = 0
    for num in reversed(nums[:mid]):
        lsum += num
        if lsum > left:
            left = lsum
    rsum = 0
    for num in nums[mid:]:
        rsum += num
        if rsum > right:
            right = rsum
    return left + right

def MaxSubarray(array):
    if len(array)==1:
        return array[0]
    else:
        mid = len(array)//2
        left_sum = MaxSubarray(array[:mid])
        right_sum = MaxSubarray(array[mid:])
        middle_sum = maxcrossSubarray(array,mid)
        if left_sum > right_sum and left_sum > middle_sum:
            return left_sum
        elif right_sum > left_sum and right_sum > middle_sum:
            return right_sum
        else:
            return middle_sum

if __name__ == '__main__':
    print(maxcrossSubarray([5,6,8,-7,-4,-5,-3,-8,2,-10],5))
    print(MaxSubarray([5,6,8,-7,-4,-5,-3,-8,2,-10]))