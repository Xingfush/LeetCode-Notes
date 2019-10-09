vector<vector<int>> ZigZagOrderTraverse(TreeNode* root){
	vector<vector<int>> res;
	if(root==nullptr) return res;

	stack<TreeNode*> s1, s2;
	s1.push(root);
	vector<int> out;
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			TreeNode* pNode = s1.top();
			out.push_back(pNode->val);
			s1.pop();
			if(pNode->left) s2.push(pNode->left);
			if(pNode->right) s2.push(pNode->right);
		}
		if(!out.empty()) res.push_back(out);
		out.clear();
		while(!s2.empty()){
			TreeNode* pNode = s2.top();
			out.push_back(pNode->val);
			s2.pop();
			if(pNode->right) s1.push(pNode->right);
			if(pNode->left) s1.push(pNode->left);
		}
		if(!out.empty()) res.push_back(out);
		out.clear();
	}

	return res;
}