/* 将一个字符串的大写字母全部放到后面，且相对顺序不变。
	例如： HelloWorld-> elloorlHW
	--- 2019.4.24号微软面试第一面第一题 */

void LowerUpperPartition(string& s){
	int length = s.size();
	for(int i=0;i<length;i++){
		if(islower(s[i])){
			int j=i-1;
			char temp = s[i];
			while(j>=0 && isupper(s[j])){
				s[j+1] = s[j];
				j--;
			}
			s[j+1] = temp; // 这里注意是 s[j+1]而不是 s[j]，因为 j--存在
		}
	}
}

