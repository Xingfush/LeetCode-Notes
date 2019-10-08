/* 依图之耻，永记于心 */

bool SearchInSortedMatrix(const vector<vector<int>>& m, int target){
    if(m.empty() || m[0].empty()) return false;
    int rows = m.size(), cols = m[0].size();
    int i=0, j=cols-1;
    while(i<rows && j>=0){
        if(m[i][j]==target){
            return true;
        } else if(m[i][j]>target) { // 找到第一个小于等于 target
            int left = 0, right = j;
            while(left<right){
                int mid = left +(right-left)/2;
                if(m[i][mid]<=target)
                    left = mid+1;
                else
                    right = mid;
            }
            j = right -1;
        } else { // 找到第一个大于等于 target
            int top = i, bottom = rows;
            while(top<bottom){
                int mid = top + (bottom-top)/2;
                if(m[mid][j]<target)
                    top = mid+1;
                else
                    bottom = mid;
            }
            i = bottom;
        }
    }

    return false;
}


