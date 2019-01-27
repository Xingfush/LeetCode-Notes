def QuickSort(array, l, r):
    if l < r:
        q = partition(array, l, r)
        QuickSort(array, l, q - 1)
        QuickSort(array, q + 1, r)
    return array

def partition(array, l, r):
    x = array[r]
    i = l - 1
    for j in range(l, r):
        if array[j] <= x:
            i += 1
            array[i], array[j] = array[j], array[i]
    array[i + 1], array[r] = array[r], array[i + 1]
    return i + 1


if __name__ == '__main__':
    # print(partition([8,7,6,5,4,3,2,1], 0, 8))
    print(QuickSort([-9, 10, 3, 42, -11, 11, -20, 13, 15, -9], 0, 9))