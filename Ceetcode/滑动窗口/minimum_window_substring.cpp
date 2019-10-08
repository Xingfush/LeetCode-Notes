/* 给定两个数组，A，B，找出A的最短子数组，这个子数组必须包含B中所有的元素，这里是字符串
   本题不需要假设 t 无重复元素，这里求解的是 "包含t的所有元素"
   如果只需要包含t中出现过的元素，那么事先对 t 进行去重操作即可，用 set */

string MininumWindowSubstring(const string& s, const string& t){
    vector<int> map(128,0);
    for(char c:t)
        map[c]++;
    int counter = t.size(), len = INT_MAX, j = 0;
    int start = 0, end = 0;
    while(end<s.size()){
        if(map[s[end++]]-->0)
            counter--;
        // 开始左指针紧缩,注意此时右指针是开的，最短子串右端的下一位
        while(counter==0){
            if(end-start<len){
                len = end-start;
                j = start;
            }
            if(map[s[start++]]++==0)
                counter++;
        }
    }

    return len==INT_MAX?"":s.substr(j,len);
}

