/* 题目描述，假设有 一个字符串数组为， tiger rpg get，那么t-r-r-g-g-t->t
	首尾字母可以构成一个环，注意这里 数组中字符串可以调换位置，
	比如 tiger get rpg，也同样可以构成环，现在给出一个字符串数组，返回是否可以
	构成环。

   解题思路：使用深度遍历，本质就是一个排列问题，找出所有能够构成环的排列，
   是否能够找到，这里使用 path 一个类似栈的结构，保存不断更新的首字母，尾字母，
   关键是 visited 在排列问题中的使用*/

bool flag = false;

void dfs(vector<string>& strs, vector<bool>& visited, vector<char>& path, int len)
{
	if (len == strs.size() && path.size() == 2) {
		if (path[0] == path[1]) {
			flag = true;
			return;
		}
	}
	for (int i = 0; i < strs.size(); i++)
	{
		if (!visited[i] && strs[i].front()==path.back()) {
			visited[i] = true;
			path.pop_back();
			path.push_back(strs[i].back());
			dfs(strs, visited, path, len + 1);
			path.pop_back();
			path.push_back(strs[i].front());
			visited[i] = false;
		}
	}
}