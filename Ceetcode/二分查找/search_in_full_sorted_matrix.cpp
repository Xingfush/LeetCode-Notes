/* matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
这个矩阵按行展开之后完全是有序的，关键点是对索引的操作，这个是基本功，一定要熟练。
如何理解使用 end = m*n 作为“右开”的索引，例如 2x3 的矩阵，如果 end = 5，那么
matrix[end/3][end%3] 刚好索引到最后一个元素，而 end = 5+ 1，刚好是右开。
 */
 
bool SearchInFullSortedMatrix(const vector<vector<int>>& m, int target){
    if(m.empty() || m[0].empty()) return false;
    int rows = m.size(), cols = m[0].size();
    int left = 0, right = rows*cols;
    while(left<right){
        int mid = left +(right-left)/2;
        int temp = m[mid/rows][mid%rows];
        if(temp==target)
            return true;
        else if(temp<target)
            left = mid +1;
        else
            right = mid;
    }
    
    return false;
}
