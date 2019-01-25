# Problem 1: length of longest substring that don't contain same character.
from collections import Counter
import numpy as np
def lenghtOfLongestSubstring(s):
    """
    :param s: string
    :return: string
    """
    length = len(s)
    counter = Counter()
    res = 0
    j = 0
    for i in range(length):
        counter[s[i]] += 1
        if counter[s[i]] >1: #  遇见重复的元素
            while counter[s[i]]>1: # j指向前一个重复元素的后一位
                counter[s[j]] -= 1
                j +=1
        res = max(res,i-j+1)
    return res

def twoSum(num, target):
    """
    find two number in list that sum to target.
    :param num: list or 1-D array
    :param target: float scalar
    :return: two number or None.
    """
    for i in range(len(num)//2 +1):
        for b in num[i+1:]:
            if num[i] + b ==target:
                return num[i],b
    return None

def TwoSum(num, target):
    """
    find two number in list that sum to target.
    using hash table.
    :param num: list or 1-D array
    :param target: float scalar
    :return: index of two number
    """
    dic = {}
    for i in range(len(num)):
        if num[i] in dic:
            return dic[num[i]], i
        else:
            dic[target-num[i]] = i
    return None

def LongestUniqueSubstring(s):
    """
    find the longest substring that contains no same char.
    :param s: string
    :return: length
    """
    from collections import Counter
    res = 0
    j = 0
    counter = Counter()
    inds = [0,0]
    for i in range(len(s)):
        counter[s[i]] += 1
        if counter[s[i]] > 1:
            while counter[s[i]] > 1:
                counter[s[j]] -=1
                j += 1
        # res = max(res, i-j+1)
        if res < i-j+1:
            inds = [j,i]
            res = i-j+1
    # 这里的Inds最终一定返回，但是赋值是条件的，因此必须初始化
    # 即使可能不会产生语法错误，也要保持好习惯
    return s[inds[0]:inds[1]+1]

def LongestIncreasingSequence(num):
    """
    find the longest increasing sequence.
    :param num: list or 1-D array
    :return: length
    """
    if len(num)<2: return len(num)
    # 如果需要一个记录中间值的表，和表最大长度
    # 先用None进行填充，并设置游标 maxLen or cur
    tailTable = [None]*len(num)
    record = [[] for i in range(len(num))]
    maxLen = 1
    tailTable[0] = num[0]
    record[0].append(num[0])
    for i in range(1,len(num)):
        j = upper_bound(tailTable[:maxLen],num[i])
        tailTable[j] = num[i]
        if j==maxLen:
            maxLen += 1
            # list [] 是可变类型，赋值要用[:]
            record[maxLen-1] = record[maxLen-2][:]
            record[maxLen-1].append(num[i])
        else:
            if j ==0:
                record[j] = num[i]
            else:
                # 所有涉及到 j-1下索引的情况都要做out of range检查
                record[j] = record[j-1][:]
                record[j][-1] = num[i]
    return record[maxLen-1]

def upper_bound(num, value):
    """
    find the first element that no less than value.
    Notice: when all elemens less than value, return len(num)
            This is a very good result.
    :param num: increasingly sorted list, float
    :param value: scalar, float
    :return: index, or None
    """
    if len(num)==0: return None
    left = 0
    right = len(num)
    while left<right:
        mid = left + (right-left)//2
        if num[mid] < value:
            left = mid + 1
        else:
            right = mid
    return left

def LongestIncreasingSubsequence(num):
    """find the longest increasing subsequence."""
    res = 0
    j = 0
    for i in range(len(num)):
        if num[i] < num[i-1]:
           j = i
        res = max(res,i-j+1)
    return res

def LongestCommonSequence(str1,str2):
    """
    find the longest common subsequence of two strings.
    :param str1: string object
    :param str2: string object
    :return: lenght
    """
    m,n = len(str1),len(str2)
    record = np.zeros((m+1,n+1))
    for i in range(1,m+1):
        for j in range(1,n+1):
            if str1[i-1]==str2[j-1]:
                record[i,j] = record[i-1,j-1] + 1
            elif record[i,j-1]>= record[i-1,j]:
                record[i,j] = record[i,j-1]
            else:
                record[i,j] = record[i-1,j]
    return record[m,n]


if __name__=='__main__':
    # print(LongestCommonSequence('abmdcdefdgegadgeghi','dabmdcdefgegagghijefg'))
    print(LongestIncreasingSequence([1,2,8,7,10,1,3,4,5,6,4,8,20,0,-1,23]))
    # lenghtOfLongestSubstring('abcdefgdefghie')
    # findMiddle([1,2,3,4,5,6,7,8],value=6.5)
    # print(TwoSum([1,2,3,4,5,6,4,2,3,4,10],16))
    # print(LongestUniqueSubstring('abcdefgdenmkjdklopfgohie'))