TreeNode* constructFromPrePost(vector<int> pre, vector<int> post) {
    vector<TreeNode*> s;
    s.push_back(new TreeNode(pre[0]));
    for (int i = 1, j = 0; i < pre.size(); ++i) {
        TreeNode* node = new TreeNode(pre[i]);
        while (s.back()->val == post[j])
            s.pop_back(), j++;
        if (s.back()->left == NULL) s.back()->left = node;
        else s.back()->right = node;
        s.push_back(node);
    }
    return s[0];
}

// 简直是神作！！！
/* Here I share my iterative solution.
We will preorder generate TreeNodes, push them to stack and postorder pop them out.

Loop on pre array and construct node one by one.
stack save the current path of tree.
node = new TreeNode(pre[i]), if not left child, add node to the left. otherwise add it to the right.
If we meet a same value in the pre and post, it means we complete the construction for current subtree. We pop it from stack.*/

/*1.按照前序数组进行遍历；2. */