/* 这里依然是用sliding window，即哈希表+左右指针法，这里的counter表示unique元素的个数 */
int LongestSubstringTwoDistinct(string s)
{
	vector<int> map(128,0)
	int counter=0, len =0;
	int start=0,end=0;
	while(end<s.size())
	{
		if(map[s[end++]]++==0)
			counter ++;
		while(counter>2)
		{
			if(map[s[start++]]--==1)
				counter --;
		}
		len = max(len, end-start);
	}
	return len;
}