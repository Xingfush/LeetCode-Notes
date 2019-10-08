/* 这一题十分经典，是二维二分查找的完美结合 */

int TopKOfSortedMatrix(const vector<vector<int>>& m, int k){
    if(m.empty() || m[0].empty()) return 0;
    int rows = m.size(), cols = m[0].size();
    int left = m[0][0], right = m[rows-1][cols-1];
    while(left<right){ // 以left==right结束
        int mid = left + (right-left)/2;
        int num = 0; // 用来表示当前不大于mid的元素个数
        for(int i=0;i<rows;i++){
            num += upper_bound(m[i].begin(),m[i].end(),mid) - m[i].begin();
        }
        if(num<k)
            left = mid+1;
        else
            right = mid;
    }

    return left;
}