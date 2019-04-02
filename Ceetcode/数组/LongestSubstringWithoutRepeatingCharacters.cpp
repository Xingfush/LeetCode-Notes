/* // 这里的counter用来计数重重复出现的元素数，例如[a,b,a,b,c,d,a]，遍历完后counter=3 */

int lengthOfLongestSubstring(string s)
{
	vector<int> map(128,0);
	int counter=0,len=0; 
	int start=0,end=0;
	while(end<s.size())
	{
		if(map[s[end++]]++>0) // 如果出现了两次，即重复元素
			counter++; // counter>0，代表有重复元素
		while(counter>0)
		{
			if(map[s[start++]]-->1)
				counter--; // 这里只要是左移碰到重复的元素就counter
		}
		len = max(len, end-start); // 这里始终是左闭右开
	}
	return len;
}

