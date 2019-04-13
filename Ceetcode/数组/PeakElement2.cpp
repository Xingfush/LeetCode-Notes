/* 来自lintCode上的一道题，微软真题
There is an integer matrix which has the following features:

The numbers in adjacent positions are different.
The matrix has n rows and m columns.
For all i < m, A[0][i] < A[1][i] && A[n - 2][i] > A[n - 1][i].
For all j < n, A[j][0] < A[j][1] && A[j][m - 2] > A[j][m - 1].

峰值元素的定义为：
	A[j][i]>A[j+1][i] && A[j][i]>A[j-1][i] && A[j][i]>A[j][i+1] && A[j][i]>A[j][i-1]
找到任意的均值返回即可。
 --------------------- 
作者：jmspan 
来源：CSDN 
原文：https://blog.csdn.net/jmspan/article/details/51724388 */

/* 思路：二维二分法：这题和矩形元素查找那一题非常像 */

vector<int> findPeak2D(vector<vector<int>> & matrix)
{
	int top = 1, bottom = matrix.size()-2; // 注意这里的初始化，和上面的条件相关
	vector<int> result;
	while (top <= bottom) { // top=bottom 停止，然后慢慢搜索这一行
		int m = (bottom+top) / 2;
		int col = findPeak1D(matrix, m);
		if (matrix[m][col] < matrix[m - 1][col]) bottom = m - 1;
		else if(matrix[m][col] < matrix[m+1][col]) top = m + 1;
		else {
			result.push_back(m); // 一定从内部返回，不然陷入死循环
			result.push_back(col);
			return result;
		}
	}
	return result;
}

int findPeak1D(vector<vector<int>>& matrix, int m) {
	int start = 0, end = matrix[m].size() - 1;
	while (start < end) {
		int mid = start + (end-start) / 2;
		if (matrix[m][mid] < matrix[m][mid + 1]) start = mid + 1;
		else end = mid;
	}
	return start;
}
