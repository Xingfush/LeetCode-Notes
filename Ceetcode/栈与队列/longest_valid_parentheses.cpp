/* 本题的理解有些困难，首先最长有效的括号范围，即在这个范围内，括号都是左右相对，完全正确。
	start：记录了正确左括号的索引，例如 ")((()"，那么 start = 1
	m.push, m.pop，所有的左右括号都是有进有出，如果右括号之前 m.empty 无左括号，那么不处理，将 start 设为 i+1
	如果 m.empty() 在出现右括号，将栈中的左括号 pop之后为空，那么直接对应 i-start+1，最左有效起始位置更新
	例如 ")()()()"，start 一直是 start = 1，一直到最后一个 )，有效长度应该为 i-start+1。
	如果 m.empty() 不为空，例如 ")((())，即 遇见第二个 ) ，那么它应该对应 m.top()，即最后一个 (，计算有效长度
	*/

int LongestValidParentheses(string s){
	int res = 0, start = 0;
	stack<int> m;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			m.push(i);
		} else if (s[i]==')'){
			if(m.empty()){
				start = i+1;
			} else{
				m.pop();
				res = m.empty()?max(res,i-start+1):max(res,i-m.top());
			}
		}
	}

	return res;	
}