# Problem 3: Different ways to add Parentheses，多种情况返回，而非最优解，本质都是遍历
# 括号的本质是一个点的分割
# Solution 1: 分治法，以operator为中点左右分割，终止条件是剩余项是否是数字
def diffWaysToCompute1(input):
    if input.isdigit():
        return [int(input)] # 一个元素依然要使用列表形式
    res=[] # 多种情况都要返回，但每次只能计算一个，因此最终要汇总成一个List
    for i in range(len(input)):
        if input[i] in '-+*':
            res1=diffWaysToCompute1(input[:i]) # 索引左开右闭
            res2=diffWaysToCompute1(input[i+1:])
            for j in res1:
                for k in res2:
                    res.append(helper(j,k,input[i]))
    return res

def helper(m,n,op):
    if op=='+':
        return m+n
    elif op=='-':
        return m-n
    else:
        return m*n

# Solution 2: 分治法，使用列表推导是进行多种情况叠加返回，内容和上面完全一样
def diffWaysToCompute2(input):
    return [a+b if c=='+' else a-b if c=='-' else a*b
            for i,c in enumerate(input) if c in '+-*'
            for a in diffWaysToCompute2(input[:i])
            for b in diffWaysToCompute2(input[i+1:])] or [int(input)]
# if c not in '+-*'，那么a,b都是空，[a+b]也是空，相反[int(input)]此时必是一个值。
# 多级的for循环在列表推导式里是相乘的

if __name__ == '__main__':
    opstr='2*3-4*5'
    print('All values of different ways to compute are:',diffWaysToCompute2(opstr))