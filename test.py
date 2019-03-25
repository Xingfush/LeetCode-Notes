def threeSum(nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    if len(nums) < 3:
        return []
    nums.sort()
    res = []
    n = len(nums)
    for i in range(0,n-2):
        if i>0 and nums[i]==nums[i-1]:
            continue
        temp = set()
        for j in range(i+1,n):
            if j>i+1 and nums[j]==nums[j-1]:
                continue
            if nums[j] in temp:
                res.append([nums[i],nums[j],-nums[i]-nums[j]])
            else:
                temp.add(-nums[i]-nums[j])
    return res


if __name__ == "__main__":
    print(threeSum([0,0,0,0]))
