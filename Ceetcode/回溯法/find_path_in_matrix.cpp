/* 回溯法典型例子 */

bool hasPath(char* matrix, int rows, int cols, char*str){
	if(matrix==nullptr || rows<1 ||cols<1 || str==nullptr)
		return false;

	bool *visited = new bool[rows*cols];
	memset(visited,0,sizeof(bool)*rows*cols);
	int length = 0;

	for(int row=0;row<rows;row++){
		for(int col=0;col<cols;col++){
			if(hasPathCore(matrix, rows, cols, row, col, str, length, visited))
				return true;
		}
	}
	return false;
}

bool hasPathCore(char* matrix, int m, int n, int i, int j, 
		         char* str, int length, bool* visited){
	// 终止条件1
	if(str[length]=='\0')
		return true;
	bool hasPath = false; // hasPath 是成功状态的标志
	// 准入判别条件，不准入则直接返回上面的 false
	if(i>=0 && i<m && j>=0 && j<n && visited[i*n+j]==false
		&& matrix[i*n+j]==str[length]){
		// 进入，有进有出
		length++;
		visited[i*n+j]=true;

		hasPath = hasPathCore(matrix, m, n, i+1, j, str, length, visited)
		|| hasPathCore(matrix, m, n, i-1, j, str, length, visited)
		|| hasPathCore(matrix, m, n, i, j+1, str, length, visited)
		|| hasPathCore(matrix, m, n, i, j-1, str, length, visited);

		if(!hasPath){ // 只有档不成功的时候才会回溯，这是只找第一份答案{
			length--; // 留下答案记录
			visited[i*n+j]=false;
		}
	}
	
	return hasPath;
}


