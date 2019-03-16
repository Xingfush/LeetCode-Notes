
/* 前序遍历虽然访问完了，但是仍然要入栈，目的就是问了访问它的右孩子时候方便 */
/* 前序遍历：形式一 */
void preOrderTraverse(TreeNode* root)
{
	stack<TreeNode *> st;
	TreeNode* pNode=root;

	while(pNode!=nullptr || !st.empty())
	{
		while(pNode!=nullptr)
		{
			// 先操作 pNode
			cout<<pNode->val<<" ";
			
			// 将 pNode 入栈
			st.push(pNode);

			// 访问 pNode的左孩子
			pNode=pNode->left;
		}

		if(!st.empty())
		{
			pNode=st.top();
			st.pop();
			// 访问右孩子，栈就是记录顺序的作用
			pNode=pNode->right;
		}

	}
}

/* 前序遍历：形式二 */
/* 这种形式更容易理解 */
void preOrderTraverse(TreeNode* root)
{
	stack<TreeNode *> st;
	TreeNode* pNode=root;

	while(pNode!=nullptr || !st.empty())
	{
		if(pNode!=nullptr)
		{
			// 先操作 pNode
			cout<<pNode->val<<" ";
			st.push(pNode);
			// 访问 pNode的左孩子
			pNode=pNode->left;
		}
		else
		{
			pNode=st.top();
			st.pop();
			// 访问右孩子，栈就是记录顺序的作用
			pNode=pNode->right;
		}

	}
}

/* 前序遍历：形式三 */
void preOrderTraverse(TreeNode* root)
{
	if (root==nullptr)
		return;

	stack<TreeNode *> st;
	TreeNode * pNode = root;
	st.push(root);

	while(!st.empty())
	{
		// 这句话说明 p 在循环中总是非空的
		cout << pNode->val << " ";

		/* 栈的特点：先被访问的根结点的右子树后被访问，先进后出 */
		if(pNode->right)
			st.push(pNode->right);
		if(pNode->left)
			pNode=pNode->left;
		else
		{
			pNode=st.top();
			st.pop();
		}
	}
	cout<<endl;
}

/* 中序遍历最简答，最容易理解 */
/* 形式 1. */
void inOrderTraverse(TreeNode* root)
{
	stack<TreeNode *> st;
	TreeNode * pNode = root;

	while(pNode!=nullptr || !st.empty())
	{
		while(pNode!=nullptr)
		{
			// 左子树入栈
			st.push(pNode);
			pNode=pNode->left;
		}

		if(!st.empty())
		{
			// 栈的记录作用
			pNode=st.top();
			st.pop();
			
			// 访问结点
			cout<<pNode->val<<" ";
			// 访问结点右孩子树
			pNode=pNode->right;
		}
	}
}

/* 形式 2. */
/* 更容易理解 */
void inOrderTraverse(TreeNode* root)
{
	stack<TreeNode *> st;
	TreeNode * pNode = root;

	while(pNode!=nullptr || !st.empty())
	{
		if(pNode!=nullptr)
		{
			// 左子树入栈
			st.push(pNode);
			pNode=pNode->left;
		}
		else
		{
			// 栈的记录作用
			pNode=st.top();
			st.pop();
			
			// 访问结点
			cout<<pNode->val<<" ";
			// 访问结点右孩子树
			pNode=pNode->right;
		}
	}
}

void postOrderTraverse(TreeNode* root)
{
	if(root==nullptr)
		return;

	stack<TreeNode *> st;
	// pCur当前访问结点，pLastVisit上一次访问结点
	TreeNode *pCur, *pLastVisit;
	pCur = root;
	pLastVisit = nullptr;

	// 先把pCur移动到左子树的最下边
	while(pCur!=nullptr)
	{
		st.push(pCur);
		pCur = pCur->left;
	}
	while(!st.empty())
	{
		// 走到这里，pCur都是空，并且已经到了左子树的底端
		// 出栈一个结点
		pCur = st.top();
		st.pop();
		// 一个结点被访问的前提是：无右子树 或 右子树已被访问
		if(pCur->right==nullptr || pCur->right==pLastVisit)
		{
			cout << setw(4) <<pCur->val;
			// 修改最近的访问结点
			pLastVisit = pCur;
		}
		else
		{
			// 根结点再次入栈
			s.push(pCur);
			// 进入右子树，可以肯定右子树一定不为空
			pCur = pCur->right;
			while(pCur!=nullptr)
			{
				s.push(pCur);
				pCur = pCur->left;
			}
		}
	}
	cout << endl;
}

/* 使用队列访问 */
/* 使用队列完成层序遍历 */
void layerOrderTraverse(TreeNode* root)
{
	if(root=nullptr)
		return;

	queue<TreeNode *> qt;
	qt.push(root);

	TreeNode *pNode = root;
	while(!qt.empty())
	{
		pNode = qt.front();
		qt.pop();

		cout<<pNode->val<<" ";

		if(pNode->left!=nullptr)
			qt.push(pNode->left);

		if(pNode->right!=nullptr)
			qt.push(pNode->right);

	}
}
