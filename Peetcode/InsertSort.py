def InsertSort(array):
    for i in range(1,len(array)):
        key = array[i]
        while i>0 and array[i-1]>key:
            array[i] = array[i-1]
            i -= 1
        array[i] = key
    return array

def BubbleSort(array):
    n = len(array)
    for i in range(n-1):
        for j in range(1, n-i):
            if array[j] < array[j-1]:
                array[j], array[j-1] = array[j-1],array[j]
    return array

if __name__ == '__main__':
    print(BubbleSort([-9,10,3,42,7,7,5,2,2,7,-20,23]))
    print(BubbleSort([8,7,6,5,4,3,2,1]))
    print(BubbleSort([1,2,3,4,5,6,7,8]))
    print(BubbleSort([1,1,1,1,1,1,1,1]))
    print(BubbleSort([-1, 2, 7, 1, 10, 1, -5,3]))
    print(BubbleSort([1,0]))
    print(BubbleSort([1]))