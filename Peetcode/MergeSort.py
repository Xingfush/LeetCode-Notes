def merge(arr,l,m,r):
    n1 = m-l
    n2 = r-m

    L = [arr[i] for i in range(l,m)]
    R = [arr[i] for i in range(m,r)]

    i = 0
    j = 0
    k = l
    while i<n1 and j<n2:
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
    if r-l>=2:
        m = l + (r-l)//2
        MergeSort(array,l,m)
        MergeSort(array,m,r)
        merge(array,l,m,r)
    return array

if __name__ == '__main__':
    print(merge([1,2,5,9,12,20],0,6,6))
    print(MergeSort([1,2,3,4,5,6,7,8,9,10],0,10))
    print(MergeSort([-9,10,3,42,7,7,5,2,2,7,-20,23],0,12))
    print(MergeSort([8,7,6,5,4,3,2,1],0,8))
    print(MergeSort([1,2,3,4,5,6,7,8],0,8))
    print(MergeSort([1,1,1,1,1,1,1,1],0,8))
    print(MergeSort([-1, 2, 7, 1, 10, 1, -5,3],0,8))
    print(MergeSort([1,0],0,2))
    print(MergeSort([0],0,1))
    print(MergeSort([],0,0))