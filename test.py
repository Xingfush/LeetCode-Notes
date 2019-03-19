def getMaxGiftValue(array):
    m = len(array)
    n = len(array[0])
    maxValues = [ 0 for i in range(n)]

    for i in range(m):
        for j in range(n):
            left = 0
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
