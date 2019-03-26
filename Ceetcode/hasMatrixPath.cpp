#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<vector>
#include<algorithm>

using namespace std;

/* 字符串的路径（即找到的情况）使用pathlength表示，当找到最后一个‘0’，是唯一的终止条件 */
/* 终止条件一定要尽量的简单，不要多重嵌套，找到结束符，就是终止
回溯法另一个要点就是能够“回溯”，
前进包括:visited=true,pahtlength++,那么回溯:visited=false,pathlenght--*/

bool hasPathCore(const char* matrix, int m, int n, int i, int j,
	const char* str, int& pathLength, bool*visited)
{
	if (str[pathLength] == '\0')
		return true;
	
	bool hasPath = false;
	if (i >= 0 && i < m && j >= 0 && j < n &&
		matrix[i*n + j] == str[pathLength] && !visited[i*n + j])
	{
		visited[i*n + j] = true;
		pathLength++;
		hasPath = hasPathCore(matrix, m, n, i, j - 1, str, pathLength, visited)
			|| hasPathCore(matrix, m, n, i, j + 1, str, pathLength, visited)
			|| hasPathCore(matrix, m, n, i - 1, j, str, pathLength, visited)
			|| hasPathCore(matrix, m, n, i + 1, j, str, pathLength, visited);
		if (!hasPath)
		{
			pathLength--;
			visited[i*n + j] = false;
		}
	}
	return hasPath;
}

bool hasPath(char* matrix, int rows, int cols, char*str)
{
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;

	bool *visited = new bool[rows*cols]; 
	memset(visited, 0, rows*cols);// memeset常用来初始化新建数组，memset(*ptr,0,size(type)*len)

	int pathLength = 0;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
				return true;
		}
	}
	delete[]visited;
	return false;
}

int main(int argc, char **argv)
{
	clock_t Start_time = clock();
	char* matrix = "abtgcfcsjdeh";
	char* str1 = "bfce";
	char* str2 = "abfb";
	cout << hasPath(matrix, 3, 4, str1) << endl;
	cout << hasPath(matrix, 3, 4, str2) << endl;
	clock_t End_time = clock();
	cout << "Running time is :" << static_cast<double>(End_time - Start_time) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	return 0;
}
