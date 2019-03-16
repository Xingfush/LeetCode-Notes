import sys
def buyLeastGifts(scores):
    size = len(scores)
    min_index = scores.index(min(scores))

    scores_extened = []
    scores_extened.extend(scores[min_index:])
    scores_extened.extend(scores[:min_index])
    scores_extened.append(scores[min_index])

    gifts_nums = [0 for i in range(len(scores_extened))]
    gifts_nums[0] = 1
    gifts_nums[-1] = 1

    min_indexes = [0,len(scores_extened)-1]
    max_indexes = []

    for i in range(1,len(scores_extened)-1):
        if scores_extened[i]<=scores_extened[i-1] and scores_extened[i]<=scores_extened[i+1]:
            gifts_nums[i]=1
            min_indexes.append(i)
        if scores_extened[i]>=scores_extened[i-1] and scores_extened[i]>=scores_extened[i+1]:
            max_indexes.append(i)

    min_indexes.sort()
    max_indexes.sort()

    for i in range(len(min_indexes)-1):
        min_index = min_indexes[i]
        max_index = max_indexes[i]
        for j in range(min_index+1,max_index):
            gifts_nums[j]=j-min_index+1

    for i in range(1,len(min_indexes)):
        min_index = min_indexes[i]
        max_index = max_indexes[i-1]
        for j in reversed(range(max_index+1,min_index)):
            gifts_nums[j]=min_index-j+1

    for max_index in max_indexes:
        gifts_nums[max_index] = max(gifts_nums[max_index-1],gifts_nums[max_index+1])+1

    return sum(gifts_nums[1:])

if __name__ == "__main__":
    # # 读取第一行的n
    # n = int(sys.stdin.readline().strip())
    # ans = 0
    # for i in range(n):
    #     # 读取每一行
    #     line = sys.stdin.readline().strip()
    #     # 把每一行的数字分隔后转化成int列表
    #     scores = list(map(int, line.split()))
    print(buyLeastGifts([1,2,3,4,3,2,0,6,8,0]))
