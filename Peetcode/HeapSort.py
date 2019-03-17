def heapify(array,n,i):

	largest = i
	lchild = 2*i +1
	rchild = 2*i +2

	if lchild<n and array[lchild]>array[largest]:
		largest = lchild
	if rchild<n and array[rchild]>array[largest]:
		largest = rchild

	if largest!=i:
		array[largest],array[i] = array[i],array[largest]
		heapify(array,n,largest)

def HeapSort(array):

	n = len(array)
	for i in reversed(range(n//2)):
		heapify(array,n,i)

	while n>1:
		array[n-1],array[0] = array[0],array[n-1]
		n -= 1
		heapify(array,n,0)
	return array

if __name__ == '__main__':
    print(HeapSort([8,7,6,5,4,3,2,1]))
    print(HeapSort([1,2,3,4,5,6,7,8]))
    print(HeapSort([1,1,1,1,1,1,1,1]))
    print(HeapSort([-1, 2, 7, 1, 10, 1, -5,3]))
    print(HeapSort([1,0]))
    print(HeapSort([1]))
    print(HeapSort([]))