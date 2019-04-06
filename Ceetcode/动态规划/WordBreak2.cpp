/* 这一题使用dfs，本质上和暴力求解没有区别，时间复杂度超了，必须用动态规划 */

vector<string> wordBreak(string s,vector<string>& wordDict){
	unordered_set<string,vector<string>> m;
	return helper(s, wordDict, m);
}

vector<string> helper(string s, vector<string>& wordDict, unordered_map<string,vector<string>> &m)
{
	if(m.count(s)) return m[s]; // 如果存在，代表已经查找过，直接返回
	if(s.empty()) return {""};
	vector<string> res; // 用来记录当前词语可以拆分成的字符串
	for(string word:wordDict){
		if(s.substr(0,word.size())!=word) continue; // 从 wordDict中找到可以当s开头的词语
		vector<string> rem = helper(s.substr(word.size()),wordDict,m); // substr缺省长度，默认为到末尾
		for(string str:rem){ // 将子串所有的拆分情况和当前的词结合，最后集中到当前串的所有拆分情况中
			res.push_back(word+(str.empty()?"":" ")+str); // str=""空集时，res = word，m[s]=word
		}
	}
	return m[s] = res;
}


/* DFS 的解法 */
vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> map(wordDict.begin(),wordDict.end());
    string path;
    vector<string> res;
    dfs(s,map,0,path,res);
    return res;
    
}
void dfs(string& s, unordered_set<string> &map, int index, string path, vector<string>& res){
    if(index==s.size()){
        path.pop_back();
        res.push_back(path);
        return;
    }
    for(int i=index;i<s.size();i++){
        string temp = s.substr(index,i-index+1);
        if(map.count(temp)){
            path.append(temp+" ");
            dfs(s,map,i+1,path,res);
            path.erase(path.end()-temp.size()-1,path.end());
        }
    }
}
