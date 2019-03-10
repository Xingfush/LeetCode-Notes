# Lomuto Scheme
def partition(array,l,r):
    pivot = array[r]
    i = l
    for j in range(l,r):
        if array[j]<=pivot:
            array[j],array[i]=array[i],array[j]
            i+=1
    array[i],array[r]=array[r],array[i]
    return i

def QuickSort(array, l, r):
    if l < r:
        q = partition(array, l, r)
        QuickSort(array, l, q - 1)
        QuickSort(array, q + 1, r)
    return array

# Hoare Scheme
def partition2(array,l,r):
    pivot = array[l]
    left = l +1
    right = r
    while left <= right:
        while left <= right and array[left] <= pivot:
            left += 1
        while left <= right and array[right] >= pivot:
            right -= 1
        if left <= right:
            array[left],array[right] = array[right],array[left]
    array[l],array[right] = array[right],array[l]
    return right

def QuickSort2(array, l, r):
    if l<r:
        k = partition2(array, l, r)
        QuickSort2(array,l,k-1)
        QuickSort2(array,k+1,r)
    return array

# 最优实现，应试优先
def QuickSort3(array,l,r):
    if l>=r:
        return
    left = l
    right = r
    pivot = array[left]
    while left < right:
        while left < right and array[right] > pivot:
            right -= 1
        array[left] = array[right]
        while left < right and array[left] <= pivot:
            left += 1
        array[right] = array[left]
    array[right] = pivot
    QuickSort3(array, l, left-1)
    QuickSort3(array, left+1, r)
    return array

if __name__ == '__main__':
    print(QuickSort3([8,7,6,5,4,3,2,1], 0, 7))
    print(QuickSort3([1,2,3,4,5,6,7,8], 0, 7))
    print(QuickSort3([1,1,1,1,1,1,1,1], 0, 7))
    print(QuickSort3([-1, 2, 7, 1, 10, 1, -5,3], 0, 7))
    print(QuickSort3([1,0],0,1))
    print(QuickSort3([1],0,0))