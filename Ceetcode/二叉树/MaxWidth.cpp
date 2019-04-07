int widthOfBinaryTree(TreeNode* root){
    int res = 0;
    vector<int> start;
    dfs(root,0,1,start,res); // 注意这里根节点是 1 索引的，只是标记作用，并没有实际的数组存储
    return res;
}

void dfs(TreeNode* node, int h, int idx, vector<int>& start, int & res){
    if(!node) return;
    if(h>=start.size()) start.push_back(idx); // 
    res = max(res, idx - start[h]+1);
    dfs(node->left, h+1, 2*idx+1, start, res);
    dfs(node->right, h+1, 2*idx+2, start, res);
}

/* 这道题充分利用了前序遍历的特点，前序遍历先访问左节点，所以每到新的一层，前序遍历访问的第一个结点
    就是这一层的 leftest node，这样我们访问每一层的时候，直接使用 idx - start[h] +1 就可以得到
    最大宽度。
    1. 使用 h 来标记结点所属的层，用来访问 start[h];
    2. idx 的计算使用 全局左边 2*i, 2*i+1 来转移到下一层的左右子结点。 */