from heapq import heapify,heappop,heappush,heapreplace

def Merge(*iterables):
    output = []
    h = []
    for order,it in enumerate(map(iter,iterables)):
        try:
            next = it.__next__
            h.append([next(),order,next])
        except StopIteration:
            pass
    heapify(h)
    while len(h) > 1:  # 终止条件是堆中有元素
        try:
            while True:
                value, order, next = s = h[0]  # 取出堆的根节点
                output.append(value)
                s[0] = next()  # raises StopIteration when exhausted
                heapreplace(h, s)  # restore heap condition
        except StopIteration:
            heappop(h)  # remove empty iterator
    if h:
        # fast case when only a single iterator remains
        value, order, next = h[0]
        try:
            while True:
                output.append(value)
                value = next()
        except StopIteration:
            pass
    return output

if __name__=='__main__':
    print(Merge([1, 3, 5, 7, 18, 39], [0, 2, 4, 8, 12, 16, 42, 51, 67], [1,10]))


