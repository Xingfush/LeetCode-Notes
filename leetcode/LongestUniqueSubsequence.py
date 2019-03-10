def LongestUniqueSubsequence2(s):
    st = set()
    res = 0
    j = 0
    for i in range(len(s)):
        while (s[i] in st):
            st.remove(s[j])
            j+=1
        st.add(s[i]) # 移除掉上一个之后，现在的这个元素也要加上
        res = max(res,i-j+1)
    return res

if __name__=='__main__':
    print(LongestUniqueSubsequence2("abababcdefghijki"))