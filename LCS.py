# Problem 1: Longest Increasing Subsequence Size (NlogN)
# Solution 1: Dynamic Programming
# How to add or replace an element in the existing sequence. Each new smallest element in the array can be
# a potential candidate to start new sequence,so we must maintain lists of increasing sequences and update.
# 使用二分法查找新的A[i]在数组tailTable中的位置，有序数组查找使用二分查找
def CeilIndex(A,l,r,key): #返回的索引 A[r]>=key>A[l]

    while (r-l>1):
        m=l+(r-l)//2
        if (A[m]>=key):
            r=m
        else:
            l=m
    return r

def LongestIncreaseSequence(A):
    tailTable=[0 for i in range(len(A))] # 记录每个LIS长度的最小尾元素
    Record=[] # 记录每个LIS长度的所有元素，用于结果重建

    tailTable[0]=A[0] # 用第一个元素初始化，所以下面从1开始，而不是0
    Record.append([A[0]])
    l=1 # 用于记录末尾位置，可以使用append和-1代替，此处没有必要
    for i in range(1,len(A)):
        if A[i]<tailTable[0]: # 第一行替换
            tailTable[0]=A[i]
            Record[0]=[A[i]]
        elif A[i]>tailTable[l-1]: # 在最后一行后重建一行
            tailTable[l]=A[i]
            Record.append(Record[-1][:])
            Record[-1].append(A[i])
            l+=1
        else:
            j=CeilIndex(tailTable,-1,l-1,A[i]) # tailTable[j]>=A[i]>tailTable[j-1]
            tailTable[j]=A[i]
            Record[j]=Record[j][:]
            Record[j][-1]=A[i]

    return Record[-1]

# Solution 2: Dynamic Programming
def LongestIncreaseSequence2(A):
    tails=[0]*len(A)
    size=0
    for x in A:
        i,j=0,size #
        while i!=j:
            m=(i+j)//2 # 由于i始终小于j，经过整除2后绝对不会出现tails[m] out of range error
            if tails[m]<x: # 寻找x在tail中的位置，tail[i-1]<x<=tail[i]
                i=m+1
            else:
                j=m
        tails[i]=x
        size=max(i+1,size)
    return size


# Problem 2: Longest Common Sequence
# Solution 1: Bottom-up Method
import numpy as np
def LongestCommonSequence(x,y):
    m=len(x)
    n=len(y)
    c=np.zeros((m+1,n+1))
    # 这里最需要注意的就是i和j的空间是m+1,n+1，向右平移了一位
    # 索引字符串的时候要相应的减去一位。
    for i in range(1,m+1):
        for j in range(1,n+1):
            if x[i-1]==y[j-1]:
                c[i,j]=c[i-1,j-1]+1
            elif c[i-1,j]>=c[i,j-1]:
                c[i,j]=c[i-1,j]
            else:
                c[i,j]=c[i,j-1]
    return c

def PrintLCS(x,y,c):
    s=[]
    i=len(x)
    j=len(y)
    while i>0 and j>0:
        if x[i-1]==y[j-1]:
            s.append(x[i-1])
            i=i-1
            j=j-1
        elif c[i,j-1]>=c[i-1,j]:
            j=j-1
        else:
            i=i-1

    print("Longest Common Subsequence is:" ,list(reversed(s)))


# Problem 3: edit distance of converting str1 to str2
def editDistance(str1,str2):
    m=len(str1)
    n=len(str2)
    d=np.zeros((m+1,n+1))
    for i in range(m+1):
        d[i,0]=i
    for j in range(n+1):
        d[0,j]=j
    for i in range(1,m+1):
        for j in range(1,n+1):
            if str1[i-1]==str2[j-1]:
                d[i,j]=d[i-1,j-1]
            else:
                d[i,j]=1+min(d[i-1,j-1],d[i-1,j],d[i,j-1])

    return int(d[m,n])



def BianrySearch(key,A):
    l,r=0,len(A)
    while r-l>=2: # 等价于r!=l，区别于r>=l
        m=(l+r)//2
        if key<=A[m]: # A[r-1]<key<=A[r]
            r=m
        else: # A[m]<key==A[l-1]<key, r=l
            l=m
    return r

def lower_bound(array,value):
    first,last=0,len(array)
    while first<last:
        mid=first+(last-first)//2
        if array[mid]==value:
            return mid
        elif array[mid]<value:
            first=mid+1
        else:
            last=mid

    return -1


if __name__ == '__main__':
    X='saturdaywendy'
    Y='sundayandy'
    A=[1, 3, 5, 7 ,9 ,11 ,13, 15, 17, 19, 20]
    B=[2,5]
    #print("Length of Longest Common Subsequence is: ",LongestIncreaseSequence(A))
    #PrintLCS(X,Y,LongestCommonSequence(X,Y))
    #print("The key is in a region:",lower_bound(B,5))
    print("the edit distance between str1 and str2 is:",editDistance(X,Y))