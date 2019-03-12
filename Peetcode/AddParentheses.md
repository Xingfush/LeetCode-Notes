### Add Parentheses

本题的递归形式和前面不太相同，虽然都是分治法的思想，但是合并的时候，`Max Subarray`是子问题返回一个值到上层问题，而`Add Parentheses`是返回一个list，该list中包含所有的`possible value`，这样的list逐级合并（乘式）。以operator为中点左右分割，终止条件是剩余项是否是数字。

递归的思想体现：只要解决该阶段的问题就行，找出该子数组所有的组合，并返回上级即可。

这里附上使用列表推导式的实现（乘式递归）：

```python
def AddParentheses2(input):
    return [a+b if c=='+' else a-b if c=='-' else a*b
            for i,c in enumerate(input) if c in '+-*'
            for a in AddParentheses(input[:i])
            for b in AddParentheses(input[i+1:])] or [int(input)] 
# 一个元素仍要以列表形式返回
```

另外，需要注意，在`input`是正确的情况下（单个数字，或者两端是数字），`input[i+1:]`的使用不需要提前检验元素的存在性。