/* 这一题十分经典，是二维二分查找的完美结合 */

int kthSmallest(vector<vector<int>>& matrix, int k)
{
	int n = matrix.size();
	int left = matrix[0][0], right = matrix[n - 1][n - 1];
	while (left < right)// 以left==right结束
	{
		mid = left + (right-left)/2; 
		int num = 0; // 用来表示当前不大于mid的元素个数
		for (int i = 0; i < n; i++)
		{
			int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
			num += pos;
		}
		if (num < k)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}
