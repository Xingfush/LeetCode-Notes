# This file is for testing of Senior Programming in Python.

# Decorator: It is a function, and used for adding extra function for certain function easily.
# 装饰器本质就是一个函数，输入和输出均为函数对象，对函数进行功能添加，可以有额外的参数输入
import logging

# def use_logging(func): # 第一层输入参数为函数
#
#     def wrapper(*args,**kwargs): # 第二层输入参数为“输入函数”的参数
#         logging.warn("%s is runing." % func.__name__)
#         return func(*args,**kwargs) # 返回输入函数的输出
#
#     return wrapper # 返回改造后的函数

# 接受输入参数的装饰器函数
def use_logging(level):
    def decorator(func):
        def wrapper(*args,**kwargs):
            if level=='warning':
                logging.warn("%s is running." % func.__name__)
            return func(*args,**kwargs)
        return wrapper
    return decorator

@use_logging('warning')
def bar():
    print("I am a bar.")

@use_logging('logging')
def foo():
    print("I am a foo.")



#bar=use_logging(bar)
bar()
foo()