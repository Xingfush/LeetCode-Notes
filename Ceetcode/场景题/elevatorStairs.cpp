/* 电梯调度问题：给出到每层的人数，电梯只能停一次，停在哪层最有效，即其他人步行最少
	使用以下方法时间复杂度为 O(n)，之所以能够使用是因为 这个问题是凸的，最优解一定存在且只有一个，
	因此我们按照单调的方向变化就行了 */

int minimalStairs(vector<int>& persons, int h){
	int n = persons.size();
	int T = 0, floor = 1;
	int N1 = 0, N2 = persons[0], N3 = 0;
	for(int i=1;i<n;i++){ // 0 索引，从0 开始，即是第一层
		N3 += persons[i];
		T += persons[i]*i;
	}
	for(int i=1;i<n;i++){
		if(N1+N2<=N3) // 在 i+1 层停更有利
		{
			T += N1+N2-N3;
			N1 += N2; // 更新N1
			N2 = persons[i];
			N3 -= persons[i];
			floor = i+1;
		}
		else
			break;
	}
	return floor;
}

