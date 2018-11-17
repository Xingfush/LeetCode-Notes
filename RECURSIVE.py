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

# remote test
if __name__ == '__main__':
    A=[2,-5,3,7,-11,8,-10,-3,6]
    print("The max subarray is:",MaxSubArray(A))