对于大部分的substring问题，即给定一个字符串，需要找出符合条件的子串，通常的做法就是

使用哈希表和左右指针，末班如下：

```c++
int findSubstring(string s)
{
    vector<int> map(128,0);
    int counter; // 检查子串是否满足条件
    int start =0, end =0; // 设置左右指针
    int len; // 字串的长度，最值
    
    for() { /* initialize the hash map here*/ }
    while(end<s.size())
    {
        if(map[s[end++]]-- ?) { /* modify counter here */ }
        while(/* counter condition */)
        {
            /* update len if finding minimum */
            // increase start to make it invalid/valid again
            if(map[s[start++]]++ ?)
            { /*modify counter here*/ }
        }
        /*update len here if finding maximum*/
    }
    return d;
}
```

这里的要点是，当问题是找出字串的最大长度时，我们应该在内部的while loop结束之后再更新maximum最大值，因为while此时保证了条件的有效性。另一方面，如果我们要寻找minimum最小值，我们应该在内部while loop进行更新。

