# This file is for testing of Senior Programming in Python.

# -------------------------------------------------------------------------------------------------------------------
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
from functools import wraps
def use_logging(level):
    def decorator(func):
        @wraps(func) # 可以注释掉运行 bar.__name__和bar.__annotations__看下区别
        def wrapper(*args,**kwargs):
            # 装饰器并不会改变原始函数的参数签名和返回值，使用*args,**kwargs只是确保任何参数都可以被接受
            if level=='warning':
                logging.warn("%s is running." % func.__name__)
            return func(*args,**kwargs)
        return wrapper
    return decorator

# 装饰器作用在函数上，这个函数的重要元信息（名字，注解，文档字符）都丢失了，使用@wraps来注解底层包装函数

@use_logging('warning')
def bar():
    print("I am a bar.")

@use_logging('logging')
def foo():
    print("I am a foo.")


# -------------------------------------------------------------------------------------------------------------------
# Class: 有关类的知识

# 类的三种方法：实例方法(最常用)，类方法classmethod，静态方法staticmethod
class M():
    def m1(self,n):
        print('self:',self)
    @classmethod
    def m2(cls,n):
        print('cls:',cls)
    @staticmethod
    def m3(n):
        pass

# a=M()
# a.m1(1)
# A.m2(1)
# A.m3(1)
# 1.首先执行M()，创建一个类A对象（类也是对象）同时初始化类里面的属性和方法，此时实例还未创建出来
# 2.执行a=A()，调用默认的构造器，创建实例对象
# 3.调用a.m1，m1是实例方法，内部自动把实例对象a传递给self参数进行绑定，即self和a指向同一个实例对象
# 4.调用A.m2，python内部隐式地把类对象传递给cls参数，cls和A都指向类对象

# 实例方法必须显示的传入一个实例对象进去，a.m1(1)等价于A.m1(a,1)
# 类方法中A.m2(1)等价于a.m2(1)，因为python会捕获a的类传递给cls，因此可以直接在类内部通过self.m2()调用
# 静态方法和普通函数没有区别，只是碰巧存在于类中的一个函数而已

# 一.将装饰器定义为类的一部分
class C():
    # Decorator as an instance method
    def decorator1(self,func):
        @wraps(func)
        def wrapper(*args,**kwargs):
            print('Decorator 1')
            return func(*args,**kwargs)
        return wrapper
    # Decorator as an class method
    @classmethod
    def decorator2(self,func):
        @wraps(func)
        def wrapper(*args,**kwargs):
            print('Decorator 2')
            return func(*args,**kwargs)
        return wrapper

a=A()
# As an instance method
@a.decorator1
def spam():
    pass
# As a class method
@A.decorator2
def grok():
    pass

# 在类中定义装饰器在标准库中很常见，例如@property装饰器就是一个类，里面定义了三个方法，每个方法都是装饰器
# getter(),setter(),deleter()
class Person:
    # 创建一个property实例
    name=property()
    # 应用类装饰器定义方法
    @name.getter
    def name(self):
        return self._name
    @name.setter
    def name(self,value):
        if not isinstance(value,str):
            raise TypeError('Expected a string')
        self._name=value


# 二.类装饰器，可以依靠类内部的__call__方法，使用@星际将装饰器附加到函数上
# 将装饰器定义为类的形式，将函数也变为了类，而__call__方法刚好使得类可以像函数那样使用
# Example 1:
class FooCall():
    def __init__(self,func):
        self._func=func

    def __call__(self):
        print('class decorator running')
        self._func()
        print('class decorator ending')

@FooCall
def barCall():
    print('bar __call__')

# Example 2:
import types
class Profiled:
    def __init__(self,func):
        wraps(func)(self)
        self.ncalls=0
    def __call__(self, *args, **kwargs):
        self.ncalls+=1
        return self.__wrapped__(*args,**kwargs)
    def __get__(self, instance, cls):
        if instance is None:
            return self
        else:
            return types.MethodType(self,instance)

# 之后可以在类和函数中自由使用
@Profiled
def add(x,y): # 此时add变成了一个类，add(2,3),add.ncalls
    return x+y

class Spam:
    @Profiled
    def bar(self,x):
        print(self,x)

# 三.为类和静态方法提供装饰器，很简单，但要保证装饰器在@classmethod和@staticmethod之后


# super()：用来调用父类的方法
class FooParent():
    def __init__(self): # 所有的类内方法都要使用self参数
        self.parent='I\'m the parent.' # 在__init__初始化函数里直接定义变量
        print('Parent')

    def bar(self,message): # 接受其他参数，和self
        print("%s from Parent" % message)

class FooChild(FooParent):
    def __init__(self):
        # super(FooChild,self)首先找到FooChild的父类，然后对其初始化
        super(FooChild,self).__init__() # 在类外直接使用对象调用方法，同样有self参数
        print('Child')

    def bar(self,message):
        super(FooChild,self).bar(message) # 类外调用方法
        print('Child bar function')
        print(self.parent) # 类内变量的引用方法

# __init__() 和 __call__ 的区别
# 1.__init__()的作用是初始化某个类的一个实例
# 2.__call__()的作用是使实例能够像函数一样被调用，同时不影响实例本身的生命周期
# 但是可以用来改变实例内部的值
class X():
    def __init__(self,a,b,range):
        self.a=a
        self.b=b
        self.range=range

    def __call__(self, a,b):
        self.a=a
        self.b=b
        print('__call__ with ({},{})'.format(self.a,self.b))



if __name__=='__main__':
    # fooChild=FooChild()
    # fooChild.bar('HelloWorld')
    # xInstance=X(1,2,3)
    # xInstance(1,2)
    bar()
    print(bar.__name__)
    print(bar.__annotations__)

#bar=use_logging(bar)
# bar()
# foo()