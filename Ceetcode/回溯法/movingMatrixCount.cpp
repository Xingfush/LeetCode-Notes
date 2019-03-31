#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<vector>
#include<algorithm>

using namespace std;

/* 回溯法中选择下一个步骤涉及到一个判断，是否进入，这个判断可以单独抽象出来，编程check函数
   只要给定一个点，那么前后左右任意移动，总能找到所有的符合条件的点，这里的假设就是解集是联通的 */


int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows <= 0 || cols <= 0)
		return 0;

	bool *visited = new bool[rows*cols];
	memset(visited, 0, sizeof(bool)*rows*cols);

	int count=movingCountCore(threshold,rows,cols,0,0,visited);
	delete[]visited;
	return count;
}

int movingCountCore(int threshold, int m, int n, int i, int j, bool* visited)
{
	int count = 0;
	if (check(threshold, m, n, i, j, visited)) // 使用check检查是否可以进入，函数模块化
	{
		visited[i*n + j] = true;
		count = 1 + movingCountCore(threshold, m, n, i+1, j, visited)
			+ movingCountCore(threshold, m, n, i-1, j, visited)
			+ movingCountCore(threshold, m, n, i, j+1, visited)
			+ movingCountCore(threshold, m, n, i, j-1, visited);
	}
	return count;
}

bool check(int threshold, int m, int n, int i, int j, bool* visited)
{
	if (i > 0 && i < m && j>0 && j < n
		&& getDigitSum(i) + getDigitSum(j) <= threshold
		&& !visited[i*n + j])
		return true;
	return false;
}

int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10; // 获得位数值的方法
		number /= 10;
	}
	return sum;
}


