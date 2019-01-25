def LongestUniqueSubsequence(s):
    dic = {} # 只需要判断是否已存在（重复），不计数（不用Counter）
    res = 0
    j = 0
    for i in range(len(s)):
        if s[i] not in dic:
            dic[s[i]] = 1 # 可以进一步简化为集合set
        else:
            while (s[i] in dic): # 更新游标的位置
                dic.pop(s[j])
                j += 1
        res = max(res, i-j+1)
    return res

def LongestUniqueSubsequence2(s):
    st = set()
    res = 0
    j = 0
    for i in range(len(s)):
        if s[i] not in st:
            st.add(s[i])
        else:
            while (s[i] in st):
                st.remove(s[j])
                j += 1
        res = max(res, i-j+1)
    return res

if __name__=='__main__':
    print(LongestUniqueSubsequence2("abcdefdhiajq"))