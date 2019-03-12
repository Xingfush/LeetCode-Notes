def lower_bound(array,first,last,value):
    while first < last:
        mid = first + (last-first)//2
        if array[mid] <value:
            first = mid+1
        else:
            last = mid
    return first

def upper_bound(array,first,last,value):
    while first < last:
        mid = first + (last-first)//2
        if array[mid] <value:
            first = mid+1
        else:
            last = mid
    return first-1

if __name__=='__main__':
    print(lower_bound([1, 2, 5, 6, 8, 10, 14, 20], 0, 8, 11))
    print(upper_bound([1, 2, 5, 6, 8, 10, 14, 20], 0, 8, 11))
    print(lower_bound([],0,0,2))
    print(upper_bound([],0,0,-1))
