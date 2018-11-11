#

# Item 1: Longest Increasing Subsequence Size (NlogN)
# Solution One: N^2 brute force
# Solution Two: Dynamic Programming
# How to add or replace an element in the existing sequence. Each new smallest element in the array can be
# a potential candidate to start new sequence,so we must maintain lists of increasing sequences and update.
# 使用二分法查找新的A[i]在数组tailTable中的位置，有序数组查找使用二分查找
def CeilIndex(A,l,r,key):

    while (r-l>1):
        m=l+(r-l)//2
        if (A[m]>=key):
            r=m
        else:
            l=m
    return r

def LongestIncreasingSubsequenceLength(A,size):
    tailTable=[0 for i in range(size+1)] # 使用任意元素初始化List，不用Numpy
    Record=[[] for i in range(size+1)]
    len=0

    tailTable[0]=A[0]
    Record[0]=[A[0]]
    len=1
    for i in range(1,size):
        if (A[i]<tailTable[0]):
            tailTable[0]=A[i]
            Record[0]=[A[i]]
        elif (A[i]>tailTable[len-1]):
            tailTable[len]=A[i]
            Record[len]=Record[len-1][:]
            Record[len].append(A[i])
            len+=1
        else:
            j=CeilIndex(tailTable,-1,len-1,A[i])
            tailTable[j]=A[i]
            Record[j]=Record[j][:]
            Record[j][-1]=A[i]

    return Record[len-1]

if __name__ == '__main__':
    A=[2,5,3,7,11,8,10,13,6]
    n=len(A)

    print("Length of Longest Increasing Subsequence is: ",LongestIncreasingSubsequenceLength(A,n))