def LongestIncreaseSubsequence(num):
    res = 1
    j = 0
    for i in range(1,len(num)):
        if num[i] < num[i-1]: # 设置游标，j为一个子序列的起点
            j = i
        res = max(res,i-j+1)
    return res

if __name__=='__main__':
    print(LongestIncreaseSubsequence([1,2,8,7,10,3,4,5,6,4,8,20,0,-1,23]))