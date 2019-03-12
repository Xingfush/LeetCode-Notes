# accessibility代表该元素是否可以由nums的子集组成，第一遍首先遍历num元素，显然每个元素都应该为True
# 其次，i从half递减至num，每个i=num_now+num_before符合的都是True。这里最关键的是before的记录，
# 正是dynamic programming的关键所在。

def canPartition(nums):
    Sum=sum(nums)
    if Sum % 2!=0:
        return False
    half=Sum//2
    accessibility=[False]*(half+1)
    accessibility[0]=True
    for num in nums:
        if half>=num:
            for i in range(half,num-1,-1):
                if accessibility[i-num]==True:
                    accessibility[i]=True

    return accessibility[half]