/* 子序列虽然不需要是连着的子串，但是字符之间的顺序是需要的，那么我们可以建立字符串t 中的每个字符
和其位置的映射，由于 t 中可能会出现重复字符，所以把相同的字符出现的所有位置按顺序加到一个数组中，
所以就是用 hashmap 来建立每个字符和其位置数组的映射。
	it = upper_bound(char2pos[c].begin(),char2pos[c].end(),pre)
	表示 能够找到符合要求下一个字符，使用 pre 来不断更新上一个的位置，后一个位置必须大于上一个位置。 */

bool isSubsequence(string s, string t){
	int pre =-1, n = t.size();
	unordered_map<char,vector<int>> char2pos;
	for(int i=0;i<n;i++)
		char2pos[t[i]].push_back(i); // 字符位置映射
	for(char c:s){
		auto it = upper_bound(char2pos[c].begin(),char2pos[c].end(),pre); 
		if(it==char2pos[c].end())
			return false;
		pre = *it;
	}
	return true;
}

/* isSubsequence的升级版，上述方法最大的优势就是检验多个 s 是否是 t 的子串，
题目：计算words中有多少个string是 S 的子序列。 */
int numMatchingSubseq(string S, vector<string>& words) {
    int n = S.size();
    int res = 0;
    unordered_map<char,vector<int>> char2pos;
    for(int i=0;i<n;i++) char2pos[S[i]].push_back(i);
    for(string& word:words){
        int pre = -1;
        res++; // 先加，如果不符合条件下面再减，一个小 trick
        for(char c:word){
            auto it = upper_bound(char2pos[c].begin(),char2pos[c].end(),pre);
            if(it==char2pos[c].end()){
                res--;
                break;
            }
            pre = *it;
        }
    }
    return res;
}