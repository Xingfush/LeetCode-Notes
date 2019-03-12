def TwoSum(num,value):
    dic = {}
    for i in range(len(num)):
        if num[i] in dic:
            return i,dic[num[i]]
        else:
            dic[value-num[i]] = i
    return None

def TwoSum2(num,value):
    dic = {}
    res = []
    for i in range(len(num)):
        if num[i] in dic:
            res.append([i,dic[num[i]]])
            dic.pop(num[i])
        else:
            dic[value-num[i]] = i
    return res

# Brute-Force 暴力破解法
def TwoSum3(num,value):
    l = len(num)
    for i in range(l):
        for j in range(i,l):
            if num[i] + num[j] == value:
                return i,j
    return None

if __name__=='__main__':
    print(TwoSum3([1,2,3,2,3,1,3,4,-2,102],100))