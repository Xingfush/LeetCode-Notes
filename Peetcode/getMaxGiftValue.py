def getMaxGiftValue(array):
    m = len(array)
    n = len(array[0])
    maxValues = [ [ 0 for i in range(n)] for j in range(m) ]
    maxValues[0][0] = array[0][0]
    for i in range(1,n):
        maxValues[0][i] = maxValues[0][i-1]+array[0][i]
    for j in range(1,m):
        maxValues[j][0] = maxValues[j-1][0]+array[j][0]

    for i in range(1,m):
        for j in range(1,n):
            maxValues[i][j] = max(maxValues[i-1][j],maxValues[i][j-1])+array[i][j]

    return maxValues[-1][-1]

# 节省空间的另一种方法
def getMaxGiftValue(array):
    m = len(array)
    n = len(array[0])
    maxValues = [ 0 for i in range(n)]

    for i in range(m):
        for j in range(n):
            left = 0 # 处理边界条件
            up = 0
            if i>0:
                up = maxValues[j]
            if j>0:
                left = maxValues[j-1]
            maxValues[j] = max(left,up)+array[i][j]

    return maxValues[-1]

if __name__ == "__main__":
    values = [[1,10,3,8],[12,2,9,6],[5,7,4,11],[3,7,16,5]]
    print(getMaxGiftValue(values))