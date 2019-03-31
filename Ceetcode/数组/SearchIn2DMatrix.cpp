bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size()==0||matrix[0].size()==0)
        return false;
    
    int m=matrix.size(),n=matrix[0].size();
    int i=0,j=n-1;
    while(i<m && j>=0)
    {
        if(matrix[i][j]==target)
            return true;
        else if(matrix[i][j]>target)
        {
            int start=0,end=j; // 这里的 matrix[i][j]>target，所以查找区间缩小为[i,j-1]=[i,j)
            while(start<end)
            {
                int mid=start+(end-start)/2;
                if(matrix[i][mid]<=target)
                    start=mid+1;
                else
                    end=mid;
            }
            j=end-1;
        }
        else
            i++;
        }
    return false;
}

/* 2019年3月25号，面试依图被拒，此题是一面的考题 */
// 这个矩阵为什么要从右上角开始：把右上角看做树根节点，这分明就是一个二叉搜索树啊！
// 二分查找只能用在行的搜索上面：找到第一个小于等于target的值，列的二分无法做到，因为切片复制有线性时间复杂度
// 面试之所以失败，是因为没有搞清楚 行查找的目的，列查找的目的，
// 一个是为了找到<=target的，另一个是为了>=target的，各有目的，临时抱佛脚，大脑一片空白，难怪失败。