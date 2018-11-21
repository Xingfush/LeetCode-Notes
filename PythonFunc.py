# This file is recorded for Python Function.

# 一.接受任意参数的函数，*args传入函数后args是元组，**kwargs传入后是字典
# 后面仍然定义其他参数，即强制关键字参数

# 二.减少可调用对象的参数个数，使用functools.partial()，允许给一个或多个参数设置固定的值
# partial()固定某些参数并返回一个新的callable对象
def spam(a,b,c,d):
    print(a,b,c,d)

from functools import partial
s1=partial(spam,1) # a=1
s2=partial(spam,d=42) # d=42

# 三.生成器函数--generator
# generator和函数执行的流程不一样，函数是顺序执行，遇到return或者最后一行就停止，但是generator每次调用
# next()的时候就执行，遇到yield就返回，再次执行时从yield语句处开始执行

# 使用生成器实现斐波那契数列
def fib(max):
    n,a,b=0,0,1
    while n<max:
        yield b
        a,b=b,a+b
        n+=1
    return 'Done'

f=fib(6) # 首先要创建一个generator对象
for n in fib(6): # 生成器是可迭代的，使用next(f)比较低效
    print(n)