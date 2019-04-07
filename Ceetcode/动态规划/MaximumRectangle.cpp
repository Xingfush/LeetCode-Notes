/* 题目1：求直方图的最大矩形面积 */

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int res =0;
    for(int i=0;i<n;i++){
        if(i+1<n && heights[i]<=heights[i+1])
            continue;
        int minH = heights[i];
        for(int j=i;j>=0;j--){
            minH = min(minH,heights[j]);
            res = max(minH*(i-j+1),res);
        }
    }
    return res;
}

// 解法2：主要是“最小栈”的使用
int largestRectangleArea(vector<int> &height){
	int res = 0;
	stack<int> st;
	height.push_back(0);
	for(int i=0;i<height.size();i++){
		if(st.empty() || height[st.top()]<height[i])
			st.push(i);
		else{
			int cur = st.top();
			st.pop;
			res = max(res,height[cur]*(st.empty()?i:(i-st.top()-1)));
			--i;
		}
	}
	return res;
}

/* 题目2：经典的 maximum rectangle */
// 解法1：结合上面的最大直方图矩形面积
int maximalRectangle(vector<std::vector<char>> &matrix){
	int res = 0;
	int m = matrix.size(), n=matrix[0].size();
	vector<int> height(n,0);
	for(int i=0;i<m;i++){
		for(int j=0;j<matrix[i].size();j++)
			height[j] = matrix[i][j]=='0'?0:(1+height[j]);
		res = max(res,largestRectangleArea(height));
	}
	return res;
}

// 解法2：尚未理解，面试优先使用上一种，时间复杂度是一样的，O(nm)
int maximalRectangle(vector<vector<char> > & matrix){
	if(matrix.empty() || maxtrix[0].empty())
		return 0;

	int res =0, m=matrix.size(), n=matrix[0].size();
	vector<int> height(n,0),left(n,0),right(n,n);
	for(int i=0;i<m;i++)
	{
		int cur_left =0, cur_right =n; // 
		for(int j=0;j<n;j++){
			if(matrix[i][j]=='1') ++height[j];
			else height[j]=0; // 注意这里的 height 的连贯性
		}
		for(int j=0;j<n;j++){
			if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
			else{
				left[j]=0;
				cur_left=j+1;
			}
		}
		for(int j=n-1;j>=0;j--){
			if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
			else{
				right[j]=n;
				cur_right=j;
			}
		}
		for(int j=0;j<n;j++)
			res = max(res,(right[j]-left[j])*height[j]);
	}
	return res;
}
