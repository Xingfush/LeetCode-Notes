/* 题目：将矩阵旋转90度
	方法1：每次用四个元素进行交换，这四个元素的坐标要记清楚，可以画图记忆 */
void RotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-1-i;j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = temp;
        }
    }
}

/* 方法2：旋转90度 = 按对角线翻转（左下到右上的对角线）+ 中线行进行上下翻转
	运行简单，容易记忆 */

void RotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            swap(matrix[i][j],matrix[n-1-j][n-1-i]);
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            swap(matrix[i][j],matrix[n-1-i][j]);
        }
    }
}