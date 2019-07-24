/* 稀疏矩阵的乘法 */
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B)
{
	// 判别矩阵维度
	if(A.empty() || A[0].empty() || B.empty() || B[0].empty() || 
										A[0].size()!=B.size())
	throw "matrix can not be empty.";

	vector<vector<int>> C(A.size(), vector<int>(B[0].size(), 0));
	for(int i=0;i<A.size();i++){
		for(int k=0;k<A[0].size();k++){
			if(A[i][k]!=0){
				for(int j=0;j<B[0].size();j++){
					if(B[k][j]!=0){
						C[i][j] += A[i][k]*B[k][j];
					}
				}
			}
		}
	}
	return C;
}

/* 其实这里先对 A 的行遍历，然后遍历 A 的列，然后遍历 B 的列，也是可以的，只是和我们平时
   理解的矩阵乘法顺序不太一样，重点是需要在 A的列，也就是B的行累计，res[i][j]++ */


/* 普通矩阵的乘法 */
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B){
	vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
	for(int i=0;i<A.size();++i){
		for(int j=0;j<B[0].size();++j){
			for(int k=0;k<A[0].size();++k){
				res[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	return res;
}