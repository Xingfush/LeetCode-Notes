def threeSum(nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    if len(nums) < 3:
        return []
    nums.sort()
    res = set()
    for i, num in enumerate(nums[:-2]):
        if i >= 1 and num == nums[i - 1]:
            continue
        temp = set()
        for v in nums[i+1:]:
            if v in temp:
                res.add((num, v, -num - v))
            else:
                temp.add(-num - v)
    return list(res)