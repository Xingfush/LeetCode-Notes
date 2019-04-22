/* 本题是2019.4.10华为笔试三道编程题之二，记录一下
	题目要求：
	1. 每个左括号之前必有一个数字，代表这个括号内字符需要重复的次数；
	2. 括号类型有([{}])，可以嵌套使用，而且保证正确，无需检查；
例子： 输入：abc2(d2(ef)) 输出：abcdefefdefef */

/* 使用递归来实现（递归内含栈） */
int index = 0;
string decodeString(string s) {
    string temp;
    while(index<s.size()){
        if(isalpha(s[index]))
            temp += s[index++];
        else if(isdigit(s[index])){
            int cnt = 0;
            while(isdigit(s[index]))
                cnt = cnt*10 + s[index++]-'0';
            index++;
            string re = decodeString(s);
            for(int i=0;i<cnt;i++)
                temp += re;
        }
        else{
            index++;
            return temp;
        }
    }
    return temp;
}

/* 使用迭代来实现，显式用栈，具体过程如下：
	使用 两个栈，分别保存 str, count
	遇见左括号：count 入栈，当前的 t 入栈，同时 令 t ="", cnt =0
	遇见右括号：取栈顶数字 将当前 t 赋值k次，合并到栈顶字符串，然后出栈，
	遇见数字，用 cnt 处理，遇见字母 添加到 t。
	左括号和右括号左右对称：两进两出，t和cnt初始化和取用，只要过程明白，那么代码就很简单。
	最后如果是 首字符是数字，如：5[db4[d]e] ，这种最后的栈为空，要返回 t。*/
string decodeString(string s) {
    stack<string> s_str;
    stack<int> s_num;
    int cnt = 0;
    string t;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i]))
            cnt = cnt*10 +s[i]-'0';
        else if(s[i]=='['){
            s_str.push(t);
            s_num.push(cnt);
            cnt = 0;
            t.clear();
        }
        else if(s[i]==']'){
            int k = s_num.top();
            s_num.pop();
            for(int j=0;j<k;j++)
                s_str.top() += t;
            t = s_str.top();
            s_str.pop();
        }
        else
            t += s[i];
    }
    return s_str.empty()?t:s_str.top();
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