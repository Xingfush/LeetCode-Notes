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


