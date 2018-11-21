# This file is recorded for Python Class from Python Cookbook
# 万物皆对象，对象由属性和方法构成

# 一.重新定义对象的方法
# 例：改变对象实例的打印和显示输出，重新定义__str__()和__repr__()方法
class Pair:
    def __init__(self,x,y):
        self.x=x
        self.y=y
    def __repr__(self):
        return 'Pair({0.x!r},{0.y!r})'.format(self)
    def __str__(self):
        return '({0.x!s},{0.y!s})'.format(self)

# 附：如何理解format 0.x!r
# 0代表括号内变量的位置，0.x代表self.x,!r代表讲对象通过repr()转换为字符串形式

# p=Pair(3,4)
# print(p)

# 二.让对象支持上下文管理协议（with语句），需要在类内实现__enter__()和__exit()__方法
# 当出现with语句块是，对象的__enter__()方法被触发，返回值会被赋给as声明的变量，然后语句块开始执行，__exit__()执行清理
# 即使语句块发生异常，上面的控制流依然会执行完，exit()包含了异常类型，异常值和追溯信息，会自己处理异常

# 例：建立一个实现网络连接的类
from socket import socket,AF_INET,SOCK_STREAM
class LazyConnection:
    def __init__(self,address,family=AF_INET,type=SOCK_STREAM):
        self.address=address
        self.family=family
        self.type=type
        self.sock=None

    def __enter__(self):
        if self.sock is not None:
            raise RuntimeError('Already connected.')
        self.sock=socket(self.family,self.type)
        self.sock.connect(self.address)
        return self.sock

    def __exit__(self,exc_ty,exc_val,tb): # 自动处理异常
        self.sock.close()
        self.sock=None

# 这个类表示一个网络连接，初始化时候不会做任何事，连接的建立和关闭时使用with语句自动完成的
from functools import partial

conn=LazyConnection(('www.python.org',80))
with conn as s:
    # conn.__enter__() executes: connection open
    s.send(b'GET /index.html HTTP/1.0\r\n')
    s.send(b'Host: www.python.org\r\n')
    s.send(b'\r\n')
    resp=b''.join(iter(partial(s.recv,8192),b''))
    # conn.__exit()__ executes: connection closed.

# 二.在类中封装属性名
# Python中没有访问控制，不能封装“私有”数据，而是通过遵循一定的属性和方法命名规约来达到这个效果
# 1.任何以单下划线开头的名字都应该是内部实现

# 三.创建可管理的属性，用于给某个实例的attribute增加除访问和修改之外的其他处理逻辑
# 将该属性定义为property即可，通过装饰器实现，
class Person:
    def __init__(self,name):
        self.name=name # 为什么设置为self.first_name而不是self._first_name
    # Getter function
    @property
    def name(self):
        return self._name
    @name.setter
    def name(self,value):
        if not isinstance(value,str):
            raise TypeError('Expected a string')
        self._name=value
    @name.deleter
    def name(self):
        raise AttributeError("Can't delete attribute")
# 答：因为self也是一个对象，self.name相当于调用setter赋值，可以在初始化时进行类型检查
# _name才是底层属性，数据保存的地方，Python类的属性不需要再__init__中声明，直接在方法内创建就行。
# 所以说name和_name是两个不同的属性，平行关系

# 四.在子类中扩展父类中的property
# 情况1：重新定义所有的property方法,通过super(Child,Child).name.__setter__访问父类property方法
class SubPerson(Person):
    @property
    def name(self):
        print('Getting name')
        return super().name
    @name.setter
    def name(self,value):
        print('Setting name to',value)
        super(SubPerson,SubPerson).name.__setter__(self,value)
    @name.deleter
    def name(self):
        print('Deleting name')
        super(SubPerson,SubPerson).name.__delete__(self)

# 情况2：只定义其中一个方法，使用@property是远远不够的，应该使用具体的父类装饰器函数
class SubPerson2(Person):
    @Person.name.getter
    def name(self):
        print('Getting name')
        return super().name


a=Person(42)
# a.first_name='Yanshan'
# print(a.first_name)
# del a.first_name