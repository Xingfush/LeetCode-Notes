/* 本题是2019.4.10华为笔试三道编程题之二，记录一下
	题目要求：
	1. 每个左括号之前必有一个数字，代表这个括号内字符需要重复的次数；
	2. 括号类型有([{}])，可以嵌套使用，而且保证正确，无需检查；
例子： 输入：abc2(d2(ef)) 输出：abcdefefdefef */

// 左右括号的处理利用递归函数中的栈机制来完成
string FlattenString(string &s, int& index) {
	string temp;
	while (index < s.size()) {
		if (isalpha(s[index])) 
			temp += s[index++];
		else if (isdigit(s[index])) {
			int repeated = (int)(s[index] - '0');
			index += 2;
			string re = FlattenString(s, index); // 遇见左括号立刻进入
			for (int i = 0; i < repeated; i++)
				temp += re;
		}
		else{ // 遇见右括号立刻返回
			index++;
			return temp;
		}
	}
	return temp;
}

int main(int argc, char **argv)
{
	clock_t Start_time = clock();

	string s = "abc2(d3(AA)g)";
	int index = 0;
	string result = FlattenString(s, index);
	cout <<result <<endl;

	clock_t End_time = clock();
	cout << "Running time is :" << static_cast<double>(End_time - Start_time) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	return 0;
}