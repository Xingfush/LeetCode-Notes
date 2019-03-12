def merge(arr,l,m,r):
    n1 = m-l
    n2 = r-m
    L = [0]*n1
    R = [0]*n2
    for i in range(n1):
        L[i] = arr[l+i]
    for j in range(n2):
        R[j] = arr[m+j]

    i = 0
    j = 0
    k = l
    while (i<n1 and j<n2):
        if L[i] < R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1
    return arr

def MergeSort(array,l,r):
    if r-l<2:
        return array
    else:
        m = l + (r-l)//2
        MergeSort(array,l,m)
        MergeSort(array,m,r)
        merge(array,l,m,r)
    return array

if __name__ == '__main__':
    print(merge([1,2,5,9,12,20],0,6,6))
    print(MergeSort([1,2,3,4,5,6,7,8,9,10],0,10))