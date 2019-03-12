# This file fullfill the implementation of Stack in Python and Some typical problems.

# Implementation of Stack
class Empty(Exception):
    """Error attempting to acess an element from an empty container."""
    pass

class ArrayStack:
    """LIFO Stack implementation using a Python list as underlying storage."""
    def __init__(self):
        self._data=[] # nonpublic list instance

    def __len__(self):
        return len(self._data)

    def is_empty(self):
        return len(self._data)==0

    def push(self,e):
        self._data.append(e)

    def top(self):
        if self.is_empty():
            raise Empty('Stack is empty')
        return self._data[-1]

    def pop(self):
        if self.is_empty():
            raise Empty('Stack is empty')
        return self._data.pop()

# Application 1: Matching delimiters
def is_matched(expr):
    """Return True if all delimiters are properly match; False otherwise."""
    lefty='([{'
    righty=')]}'
    S=ArrayStack()
    for c in expr:
        if c in lefty:
            S.push(c)
        elif c in righty:
            if S.is_empty(): # 错误的两种情况有右无左
                return False
            if righty.index(c)!=lefty.index(S.pop()): # 此处使用str.index()和str.find()等效
                return False

    return S.is_empty() # 最后的检查，不应该有delimitor剩余，有左无右

# Application 2: Matching Tags in a markup language
def is_matched_html(raw):
    """Return True if all HTML tags are properly match; False otherwise."""
    S=ArrayStack()
    j=raw.find('<') # find first '<' character if any
    while j!=-1: #
        k=raw.find('>',j+1)
        if k==-1:
            return False # 有'<'时，找不到右'>'直接返回False
        tag=raw[j+1:k] # 左闭右开
        if not tag.startswith('/'): # 有一个左标签
            S.push(tag)
        else:   # 有一个有标签
            if S.is_empty():
                return False
            if tag[1:]!=S.pop(): # tag[1:]从1开始，避开'/'
                return False
        j=raw.find('<',k+1) # 不断地寻找下一个'<'的位置，使用k来不断更新

    return S.is_empty()

if __name__=='__main__':
    expr='[(2+5)*3-5]/2-2-[1-9*(3+1)]}'
    print('Is the expr matched:',is_matched(expr))
