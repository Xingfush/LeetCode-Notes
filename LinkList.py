# This file fullfill the implementation of Stack in Python and Some typical problems.

# Single implementation of LinkedStack

class Empty(Exception):
    """Error attempting to acess an element from an empty container."""
    pass

class LinkedStack:
    """LIFO Stack implementation using a singly linked list for storage."""

    # Single LinkList implementation.
    class _Node:
        """Lightweight, nonpublic class for storing a singly linked node."""
        __slots__ = '_element','_next'

        def __init__(self,element,next):
            self._element=element
            self._next=next

    def __init__(self):
        self._head=None
        self._size=0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size==0

    def push(self,e):
        self._head=self._Node(e,self._head) # 最能体现Python特性的一句话，内在的引用机制
        self._size+=1

    def top(self):
        if self.is_empty():
            raise Empty('Stack is empty')
        return self._head._element

    def pop(self):
        if self.is_empty():
            raise Empty('Stack is empty')
        anwser=self._head._element
        self._head=self._head._next
        self._size-=1
        return anwser


# Single implementation of LinkedQueue
class LinkedQueue:

    class _Node:
        __slots__ = '_element','_next'

        def __init__(self,element,next):
            self._element=element
            self._next=next

    def __init__(self):
        self._head=None # 初始时 head和tail指向同一个元素
        self._tail=None
        self._size=0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size==0

    def first(self):
        if self.is_empty():
            raise Empty('Queue is empty')
        return self._head._element

    def dequeue(self):
        if self.is_empty():
            raise Empty('Queue is empty')
        answer=self._head._element
        self._head=self._head._next
        self._size-=1
        if self.is_empty(): # 如果只有一个元素，那么head和tail同时指向一个元素
            self._tail=None
        return answer

    def enqueue(self,e):
        newest=self._Node(e,None) # newest指向None，这个不用再修改
        if self.is_empty(): # 如果是空的，那么此时head和tail均指向None，新添加的元素就是head
            self._head=newest
        else:
            self._tail._next=newest # 只有当原本不为空时，tail不是None，tail.next才有所指
        self._tail=newest # 这个是肯定的
        self._size+=1

# 需要注意的地方：
# 1.只有一个元素或者为空时，head和tail指向同一个元素，或者None。
# 2.无论是enqueue还是dequeue，都要对队列为空的特殊情况进行特殊讨论，
# 一般情况下，enqueue只影响tail，dequeue只影响head，但是当Queue为空时，两者都会影响。


# 循环队列，实现有效的rotate方法，引用于队首变队尾的特殊场景

class CircularQueue:
    """Queue implementation using circularly linked list for storage."""

    class _Node:
        __slots__ = '_element', '_next'
        def __init__(self, element, next):
            self._element = element
            self._next = next

    def __init__(self):
        self._tail=None
        self._size=0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size==0

    def first(self):
        if self.is_empty():
            raise Empty('Queue is empty')
        head=self._tail._next
        return head._element

    def dequeue(self):
        if self.is_empty():
            raise Empty('Queue is empty')
        oldhead=self._tail._next # 一定要先保存下来带删除的节点，不然解队列应用后无法访问
        if self._size==1: # 只有一个元素是特殊情况，不然会陷入死循环
            self._tail=None
        else:
            self._tail._next=oldhead._next
        self._size-=1
        return oldhead._element

    def enqueue(self):
        newest=self._Node(e,None)
        if self.is_empty():
            newest._next=newest
        else:
            newest._next=self._tail._next
            self._tail._next=newest
        self._tail=newest #  上面先使用tail进行enqueue，后面再更新tail
        self._size+=1

    def rotate(self):
        if self._size>0: # 即使只有一个元素，也可以自己转到自己
            self._tail=self._tail._next


# Implementation of Double-Linked List Queue, as base class of Dequeue.

class _DoublyLinkedBase:
    class _Node:  # A leading underscore mean it is a base class not intended for public interface
        __slots__ = '_element', '_prev', '_next'

        def __init__(self, element, prev, next):
            self._element = element
            self._prev = prev
            self._next = next

    def __init__(self):
        self._header=self._Node(None,None,None)
        self._trailer=self._Node(None,None,None)
        self._header._next=self._trailer
        self._trailer._prev=self._header
        self._size=0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size==0

    def _insert_between(self,e,predecessor,successor):
        """Add element e between two existing nodes and return new node."""
        newest=self._Node(e,predecessor,successor)
        predecessor._next=newest
        successor._prev=newest
        self._size+=1
        return newest

    def _delete_node(self,node):
        predecessor=node._prev
        successor=node._next
        predecessor._next=node._next
        successor._prev=node._prev
        self._size-=1
        element=node._element
        node._prev=node._next=node._element=None
        return element


# Implementation of subclass LinkedDeque based on _DoublyLinkedBase.
class LinkedDeque(_DoublyLinkedBase):
    # __init__, __len__, is_empty is omitted, as those in Parent class suffice the requirements.
    # __init__，方法继承，属性也继承

    def first(self):
        if self.is_empty():
            raise Empty('Deque is empty')
        return self._header._next._element

    def last(self):
        if self.is_empty():
            raise Empty('Deque is empty')
        return self._trailer._prev._element

    def insert_first(self,e):
        self._insert_between(e,self._header,self._header._next) # 父类的方法直接作为自己的方法调用

    def insert_last(self,e):
        self._insert_between(e,self._trailer._prev,self._trailer)

    def delete_first(self):
        if self.is_empty():
            raise Empty('Deque is empty')
        return self._delete_node(self._header._next)

    def delete_last(self):
        if self.is_empty():
            raise Empty('Deque is empty')
        return self._delete_node(self._trailer._prev)


# Positional List ADT based on Double LinkedList
class PositionalList(_DoublyLinkedBase):
    """A sequential container of elements allowing positional access."""
    # ----------------nested Postion class-----------------------
    class Position:
        """An abstraction representing the location of a single element."""
        def __init__(self,container,node):
            self._container=container # 以PositionalList对象（而非类）为参数传入，用于检验是否是对一个对象操作
            self._node=node # 对 node 进行一个封装，多了一个指向node的引用

        def element(self):
            return self._node._element

        def __eq__(self, other):
            """Return True if other is a Position representing the same location."""
            return type(other) is type(self) and other._node is self._node

        def __ne__(self, other):
            return not (self==other)


    # ---------------utility method-------------------------------
    def _validate(self,p):
        """Return position'node, or raise appropriate error if invalid."""
        # validate 返回node引用，相当于是一个解p的作用，使用底层方法前，先解位置p至节点node
        if not isinstance(p,self.Position):
            raise TypeError('p must be proper Position type')
        if p._container is not self: # self 指的就是一个对象，正在操作的对象
            raise ValueError('p does not belong to this container')
        if p._node._next is None: # convention for deprecated nodes.
            raise ValueError('p is no longer valid')
        return p._node

    def _make_position(self,node):
        """Return Position instance for given node (or None if sentinel)."""
        # make_position 将node包装为Position，与validate一升一降，升可用子类的index操作，降可用父类的Node操作
        if node is self._header or node is self._trailer:
            return None # boundary violation
        else:
            return self.Position(self,node) # legitimate position

    # -----------------accessor------------------------------------
    def first(self):
        return self._make_position(self._header._next)

    def last(self):
        return self._make_position(self._trailer._prev)

    def before(self,p):
        node=self._validate(p)
        return self._make_position(node._prev)

    def after(self,p):
        node=self._validate(p)
        return self._make_position(node._next)

    def __iter__(self):
        """Generate a forward iteration of the elements of the list."""
        cursor=self.first()
        while cursor is not None:
            yield cursor.element()
            cursor=self.after(cursor) # after() 是iter的关键

    # -----------------mutators-------------------------------------

    def _insert_between(self,e,predecessor,successor):
        """Add element between existing nodes and return new Position."""
        node=super()._insert_between(e,predecessor,successor)
        return self._make_position(node) # 只是对 insert_between的返回加了一层包装，输入没有包装

    def add_first(self,e):
        """Insert element e at the front of the list and return new Position."""
        return self._insert_between(e,self._header,self._header._next)

    def add_last(self,e):
        return self._insert_between(e,self._trailer._prev,self._trailer)

    def add_before(self,p,e):
        """"Insert element e into list before Position p and return new Position."""
        original=self._validate(p)
        return self._insert_between(e,original._prev,original)

    def add_after(self,p,e):
        original=self._validate(p)
        return self._insert_between(e,original,original._next)

    def delete(self,p):
        original=self._validate(p)
        return self._delete_node(original)

    def replace(self,p,e):
        """Replace the element at Position p with e, return the element formerly at Position p"""
        original=self._validate(p)
        old_value=original._element
        original._element=e
        return old_value











