class Solution {
private:
    int maxVal = 0;
    unordered_map<long,long> levelLeft;
public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return maxVal;
    }

    void dfs(TreeNode* root, long depth, long pos) 
    {
        if (root == NULL) 
            return;
        
        if (levelLeft.find(depth)==levelLeft.end())
           levelLeft[depth]=pos;
        
        maxVal = max(maxVal, pos - levelLeft[depth] + 1);
        
        dfs(root->left, depth + 1, 2 * pos); //make sure all left explored first using dfs
        dfs(root->right, depth + 1, 2 * pos + 1);
    }
};