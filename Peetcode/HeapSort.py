def MaxHeapify(array,n,i):
    l= 2*i+1
    r= 2*i+2
    largest = i
    if l<=n and array[largest]<array[l]:
        largest=l
    if r<=n and array[largest]<array[r]:
        largest=r
    if largest != i:
        array[largest],array[i]=array[i],array[largest]
        MaxHeapify(array,n,largest)

def HeapSort(array):
    n = len(array)
    for i in reversed(range(n//2)):
        MaxHeapify(array,n-1,i)
    while n>1:
        array[n-1],array[0]=array[0],array[n-1]
        n-=1
        MaxHeapify(array,n-1,0)
    return array


if __name__ == '__main__':
    print(HeapSort([8,7,6,5,4,3,2,1]))
    print(HeapSort([1,2,3,4,5,6,7,8]))
    print(HeapSort([1,1,1,1,1,1,1,1]))
    print(HeapSort([-1, 2, 7, 1, 10, 1, -5,3]))
    print(HeapSort([1,0]))
    print(HeapSort([1]))
    print(HeapSort([]))