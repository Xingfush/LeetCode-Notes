def helper(m,n,op):
    if op == '+':
        return m+n
    elif op == '-':
        return m-n
    else:
        return m*n

def AddParentheses(input):
    if input.isdigit():
        return [int(input)] # 一个元素依然要使用列表形式
    res = [] # 多种情况都要返回，但每次只能计算一个，因此最终要汇总成一个List
    for i in range(len(input)):
        if input[i] in '+-*':
            res1 = AddParentheses(input[:i])
            res2 = AddParentheses(input[i+1:])
            for m in res1:
                for n in res2:
                    res.append(helper(m,n,input[i]))
    return res

def AddParentheses2(input):
    return [a+b if c=='+' else a-b if c=='-' else a*b
            for i,c in enumerate(input) if c in '+-*'
            for a in AddParentheses(input[:i])
            for b in AddParentheses(input[i+1:])] or [int(input)]
# if c not in '+-*'，那么a,b都是空，[a+b]也是空，相反[int(input)]此时必是一个值。
# 多级的for循环在列表推导式里是相乘的

if __name__ == '__main__':
    opstr='2*3-4*5+6'
    print('All values of different ways to compute are:',AddParentheses2(opstr))