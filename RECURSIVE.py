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

# Problem 3: Different ways to add Parentheses，多种情况返回，而非最优解，本质都是遍历
# 括号的本质是一个点的分割
# Solution 1: 分治法，以operator为中点左右分割，终止条件是剩余项是否是数字
def diffWaysToCompute1(input):
    if input.isdigit():
        return [int(input)] # 一个元素依然要使用列表形式
    res=[] # 多种情况都要返回，但每次只能计算一个，因此最终要汇总成一个List
    for i in range(len(input)):
        if input[i] in '-+*':
            res1=diffWaysToCompute1(input[:i]) # 索引左开右闭
            res2=diffWaysToCompute1(input[i+1:])
            for j in res1:
                for k in res2:
                    res.append(helper(j,k,input[i]))

    return res

def helper(m,n,op):
    if op=='+':
        return m+n
    elif op=='-':
        return m-n
    else:
        return m*n

# Solution 2: 分治法，使用列表推导是进行多种情况叠加返回，内容和上面完全一样
def diffWaysToCompute2(input):
    return [a+b if c=='+' else a-b if c=='-' else a*b
            for i,c in enumerate(input) if c in '+-*'
            for a in diffWaysToCompute2(input[:i])
            for b in diffWaysToCompute2(input[i+1:])] or [int(input)]
# if c not in '+-*'，那么a,b都是空，[a+b]也是空，相反[int(input)]此时必是一个值。
# 多级的for循环在列表推导式里是相乘的


if __name__ == '__main__':
    A=[2,-5,3,7,-11,8,-10,-3,6,89,80,3,4]
    r=[1,3,5,7,9]
    s=[2,4,6,8,10,11,12,13]
    opstr='2*3-4*5'
    # print("The max subarray is:",MergeSort(A))
    # print('All values of different ways to compute are:',diffWaysToCompute2(opstr))
    print(MergeSort([-9,10,3,42,-2,7,5,2,2,7]))