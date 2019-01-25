import numpy as np

def LongestCommonSequence(str1,str2):
    m,n = len(str1),len(str2)
    record = np.zeros((m+1,n+1))
    for i in range(1,m+1):
        for j in range(1,n+1):
            if str1[i-1]==str2[j-1]:
                record[i,j] = record[i-1,j-1] + 1
            elif record[i,j-1]>= record[i-1,j]:
                record[i,j] = record[i,j-1]
            else:
                record[i,j] = record[i-1,j]
    return record[m,n]

if __name__=='__main__':
    print(LongestCommonSequence("abcughigh","bdcuihghvh"))