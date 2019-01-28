def ShellSort(arr):
    # Start with a big gap, then reduce the gap
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            while i >= gap and arr[i - gap] > temp:
                arr[i] = arr[i - gap]
                i -= gap
            arr[i] = temp
        gap //= 2
    return arr

if __name__ == '__main__':
    print(ShellSort([8,7,6,5,4,3,2,1]))
    print(ShellSort([1,2,3,4,5,6,7,8]))
    print(ShellSort([1,1,1,1,1,1,1,1]))
    print(ShellSort([-1, 2, 7, 1, 10, 1, -5,3]))
    print(ShellSort([1,0]))
    print(ShellSort([1]))