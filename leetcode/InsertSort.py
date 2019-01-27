def InsertSort(array):
    for i in range(1,len(array)):
        key = array[i]
        while key<array[i-1] and i>0:
            array[i] = array[i-1]
            i -= 1
        array[i] = key
    return array

if __name__ == '__main__':
    print(InsertSort([-9,10,3,42,7,7,5,2,2,7,-20,23]))