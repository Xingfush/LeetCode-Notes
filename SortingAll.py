def partition(array,left,right): # two ends are all close
	
	start = left
	end = right # end 一定是从 right开始，当left=right时，right-1没有意义
	pivot = array[right]

	while(start<end):

		while(start<end and array[start]<pivot):
			start += 1
		while(start<end and array[end]>=pivot):
			end -= 1
		if(start<end):
			array[start],array[end] = array[end],array[start]

	array[start],array[right] = array[right],array[end]

	return start

def partition(array,left,right):

	pivot = array[right]
	j = left

	for i in range(left,right):
		if array[i]<pivot:
			array[i],array[j] = array[j],array[i]
			j += 1
	array[j],array[right] = array[right],array[j]

	return j 

def QuickSort(array,start,end):

	if start<end:
		q = partition(array,start,end)
		QuickSort(array,start,q-1)
		QuickSort(array,q+1,end)


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


def merge(array,l,m,r):

	n1 = m-l
	n2 = r-m

	i = 0
	j = 0
	k = l

	arrL = [array[i] for i in range(l,m)]
	arrR = [array[i] for i in range(m,r)]

	while i<n1 and j<n2:
		if arrL[i]<arrR[j]:
			array[k] = arrL[i]
			i += 1
		else:
			array[k] = arrR[j]
			j += 1
		k += 1

	while i<n1:
		array[k] = arrL[i]
		k += 1
		i += 1
	while j<n2:
		array[k] = arrR[j]
		k += 1
		j += 1

	return array

def MergeSort(array,l,r): # r is the open index, not close index
	if r-l>=2:
		m = l+(r-l)//2
		MergeSort(array,l,m)
		MergeSort(array,m,r)
		merge(array,l,m,r)
	return array

def ShellSort(array):
	n = len(array)
	gap = n//2

	while gap>0:
		for i in range(gap,n):
			key = array[i]
			while i>gap and array[i-gap]>key:
				array[i] = array[i-gap]
				i -= gap
			array[i] = key
		gap //=2
	return array

def InsertSort(array):

	for i in range(1,len(array)):
		key = array[i]
		while i>0 and key<array[i-1]:
			array[i] = array[i-1]
		array[i] = key

	return array

def BubbleSort(array):
    n = len(array)
    for i in range(n-1):
        for j in range(1, n-i):
            if array[j] < array[j-1]:
                array[j], array[j-1] = array[j-1],array[j]
    return array