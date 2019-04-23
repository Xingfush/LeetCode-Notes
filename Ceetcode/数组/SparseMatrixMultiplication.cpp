vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B){
	vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
	for(int i=0;i<A.size();++i){
		for(int k=0;k<A[0].size();++k){
			if(A[i][k]!=0){
				for(int j=0;j<B[0].size();++j){
					if(B[k][j]!=0)
						res[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	}
	return res;
}

/* 普通矩阵的乘法 */
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B){
	vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
	for(int i=0;i<A.size();++i){
		for(int j=0;j<B[0].size();++j){
			for(int k=0;k<A[0].size();++k){
				res[i][j] = A[i][k]*B[k][j];
			}
		}
	}
	return res;
}