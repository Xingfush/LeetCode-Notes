def siftdown(array,n,i): # n denote the number of heap, not the index end.

	child = 2*i +1

	while child<n:
		# find the larger child
		if (child+1<n) and (array[child]<array[child+1]):
			child += 1
		# update
		if array[i]>array[child]: # stop here
			break
		else:
			array[i],array[child] = array[child],array[i]
			i = child
			child = 2*i +1


def siftup(array,i):

	parent = (i-1)/2

	while(i>0):
		# stop here
		if(array[i]<array[parent]):
			break
		else:
			array[i],array[parent] = array[parent],array[i]
			index = parent