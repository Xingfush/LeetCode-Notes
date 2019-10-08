/* 稀疏矩阵的乘法 */

vector<vector<int>> MatrixMultiplication(const vector<vector<int>>& m1,
                                         const vector<vector<int>>& m2){
    if(m1.empty() || m1[0].empty() || m2.empty() || m2[0].empty() || m1[0].size()!=m2.size())
        return {};
    int m = m1.size(), p = m1[0].size(), n = m2[0].size();
    vector<vector<int>> m3(m, vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int k=0;k<p;k++){
            if(m1[i][k]!=0){
                for(int j=0;j<n;j++){
                    if(m2[k][j]!=0){
                        m3[i][j] += m1[i][k]*m2[k][j];
                    }
                }
            }
        }
    }
    return m3;
}

/* 其实这里先对 A 的行遍历，然后遍历 A 的列，然后遍历 B 的列，也是可以的，只是和我们平时
   理解的矩阵乘法顺序不太一样，重点是需要在 A的列，也就是B的行累计，res[i][j]++ */
