def LongestIncreasingSubsequence(num):
    res = 1
    j = 0
    for i in range(1,len(num)):
        if num[i] < num[i-1]: # 设置游标，j为一个子序列的起点
            j = i
        res = max(res,i-j+1)
    return res

def LongestIncreasingSubsequence2(array): # 这个答案更好理解
	res = 1
	num=1
	for i in range(1,len(array)):
		if array[i]>array[i-1]:
			num+=1
		else:
			num=1
		res=max(num,res)
	return res

if __name__=='__main__':
    print(LongestIncreasingSubsequence2([1,2,8,7,10,3,4,5,6,-7,8,20,60,71,23]))