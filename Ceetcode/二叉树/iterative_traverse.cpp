/* 前序遍历虽然访问完了，但是仍然要入栈，目的就是问了访问它的右孩子时候方便 */

void PreOrderTraverse(TreeNode* root){
	stack<TreeNode*> st;
	TreeNode* pNode = root;
	while(!st.empty() || pNode){
		if(pNode){
			st.push(pNode);
			cout<<pNode->val;
			pNode = pNode->left;
		} else {
			pNode = st.top();
			st.pop();
			pNode = pNode->right;
		}
	}
}

/* 中序遍历最简答，最容易理解 */

void InOrderTraverse(TreeNode* root){
	stack<TreeNode*> st;
	TreeNode* pNode = root;
	while(!st.empty() || pNode){
		if(pNode){
			st.push(pNode);
			pNode = pNode->left;
		} else {
			pNode = st.top();
			st.pop();
			cout<<pNode->val;
			pNode = pNode->right;
		}
	}
}

/* 后序遍历最难，仔细理解 */

void PostOrderTraverse(TreeNode* root){
	stack<TreeNode*> st;
	// pCur当前访问结点，pLastVisit上一次访问结点
	TreeNode *pNode = root, *pLast = nullptr;
	while(!st.empty() || pNode){
		if(pNode){
			st.push(pNode);
			pNode = pNode->left;
		} else {
			TreeNode* temp = st.top();
			// 走到这里，pCur都是空，并且已经到了左子树的底端
			if(!temp->right || temp->right=pLast){
				cout<<temp->val;
				pLast = temp;
				st.pop();
			} else {
				pNode = temp->right;
			}
		}
	}
}


/* 使用队列访问 */
/* 使用队列完成层序遍历 */
void LayerOrderTraverse(TreeNode* root){
	if(root==nullptr) return; // 很必要，以免空指针入队

	queue<TreeNode*> q;
	q.push(root);
	TreeNode* pNode = nullptr;
	while(!qt.empty()){
		pNode = q.front();
		q.pop();
		cout<<pNode->val;
		if(pNode->left) q.push(pNode->left);
		if(pNode->right) q.push(pNode->right);
	}
}


