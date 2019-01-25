def lower_bound(A,l,r,key):
    while l<r:
        mid=l+(r-l)//2
        if A[mid]<key:
            l=mid+1
        else:
            r=mid
    return r

def LongestIncreaseSequence(A):
    if len(A)<2: return A
    # 如果需要一个记录中间值的表，和表的最大程度
    # 先用 None 进行填充，并设置游标 maxLen or cur
    tailTable=[0]*len(A)
    Record=[[] for i in range(len(A))]
    tailTable[0]=A[0]
    Record[0].append(A[0])
    l=1
    for i in range(1,len(A)):
        if A[i]<tailTable[0]:
            tailTable[0]=A[i]
            Record[0]=[A[i]]
        elif A[i]>tailTable[l-1]:
            tailTable[l]=A[i]
            Record[l]=Record[l-1][:]
            Record[l].append(A[i])
            l+=1
        else:
            j=lower_bound(tailTable,0,l,A[i])
            tailTable[j]=A[i]
            Record[j]=Record[j-1][:]
            Record[j].append(A[i])
    return Record[l-1]

# 仅计算最长上升子序列的长度
def LongestIncreaseSequence2(A):
    tailTable=[0 for i in range(len(A))]
    tailTable[0]=A[0]
    l=1
    for i in range(1,len(A)):
        if A[i]<tailTable[0]:
            tailTable[0]=A[i]
        elif A[i]>tailTable[l-1]:
            tailTable[l]=A[i]
            l+=1
        else:
            j=lower_bound(tailTable,0,l,A[i])
            tailTable[j]=A[i]
    return l

if __name__=='__main__':
    print(LongestIncreaseSequence3([1,2,8,7,10,3,4,5,6,4,8,20,0,-1,23]))