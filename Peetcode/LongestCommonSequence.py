def LongestCommonSequence(str1,str2):
    m,n = len(str1),len(str2)
    record = [[0 for i in range(n+1)] for j in range(m+1)]
    for i in range(1,m+1):
        for j in range(1,n+1):
            if str1[i-1]==str2[j-1]:
                record[i][j] = record[i-1][j-1] + 1
            elif record[i-1][j]>=record[i][j-1]:
                record[i][j] = record[i-1][j]
            else:
                record[i][j] = record[i][j-1]
            # 这里不要使用以下语句，因为打印序列的时候无法处理相等情况下的方向
            # record[i][j] = max(record[i-1][j],record[i][j-1])
    return record

def printLCS(x,y,c):
    # 这里的 c 就是上面的 record 矩阵
    s=[]
    i=len(x)
    j=len(y)
    while i>0 and j>0:
        if x[i-1]==y[j-1]:
            s.append(x[i-1])
            i=i-1
            j=j-1
        elif c[i][j-1]>=c[i-1][j]:
            j=j-1
        else:
            i=i-1
    print("Longest Common Subsequence is:" ,list(reversed(s)))

if __name__=='__main__':
    # print(LongestCommonSequence("abcughigh","bdcuihghvh"))
    print(printLCS("abcughigh","bdcuihghvh",LongestCommonSequence("abcughigh", "bdcuihghvh")))