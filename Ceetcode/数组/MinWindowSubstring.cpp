/* 给定两个数组，A，B，找出A的最短子数组，这个子数组必须包含B中所有的元素，这里是字符串 */
string minWindow(string s, string t) {
    vector<int> map(128,0);
    for(auto c:t)
        map[c]++;
    int start=0,end=0;
    int len=INT_MAX,head=0;
    int counter=t.size(); // 假设 t内无重复元素
    while(end<s.size())
    {
        // 如果找到了一个元素，是之前没有找到过的
        if(map[s[end++]]-->0)
            counter--;
        // 开始左指针紧缩,注意此时右指针是开的，最短子串右端的下一位
        while(counter==0)
        {
            if(end-start<len)
            {
                len=end-start;
                head =start;
            }
            if(map[s[start++]]++==0)
                counter++;
        }
    }
    return len==INT_MAX?"":s.substr(head,len);  
}

