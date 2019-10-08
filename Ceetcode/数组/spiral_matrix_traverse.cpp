/* 本题是必备的基础题，属于数组操作基本功系列，螺旋形访问一个数组，要点在于设置四个index，
	未访问的最上一行： upper most---u
	未访问的最下一行： down most---d
	未访问的最左一列： left most---l
	未访问的最右一列： right most---r
	注意访问的对称性，访问行时，从 l到r，左闭右闭；
				   	访问列时，从 u到d，上闭下闭。*/

vector<int> SpiralOrderTraverse(const vector<vector<int>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return {};
    int m=matrix.size(),n=matrix[0].size();
    int l=0,r=n-1,u=0,d=m-1;
    vector<int> res(m*n,0);
    int p=0;
    while(l<=r && u<=d){ // 注意终止条件 l<=r, u<=d
        for(int col =l;col<=r;col++){
            res[p++]=matrix[u][col];
        }
        if(++u>d) break;
        for(int row=u;row<=d;row++){
            res[p++]=matrix[row][r];
        }
        if(--r<l) break;
        for(int col=r;col>=l;col--){
            res[p++]=matrix[d][col];
        }
        if(--d<u) break;
        for(int row=d;row>=u;row--){
            res[p++]=matrix[row][l];
        }
        if(++l>r) break;
    }
    return res;
}