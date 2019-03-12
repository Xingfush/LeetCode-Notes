import numpy as np

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