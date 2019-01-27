def partition(array,l,r):
    key = array[l]
    left = l
    right = r-1
    while left < right: # left=right时只有一个元素
        while array[left]<key:
            left += 1
        while array[right]>key:
            right -= 1
        if left < right:
            array[left],array[right] = array[right],array[left]
    return right

def QuickSort(array,l,r):
    if l < r:
        k = partition(array,l,r)
        QuickSort(array,l,k)
        QuickSort(array,k+1,r)
    return array

if __name__ == '__main__':
    # print(partition([-9, 10, 3, 42, -11, 11, -20, 13, 15, -10], 0, 10))
    print(QuickSort([9,2,-3,-4,-5,-6,-7,-8,-10,-12], 0, 10))