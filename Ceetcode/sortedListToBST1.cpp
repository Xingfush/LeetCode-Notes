/* 统计链表中结点个数 */
int count(ListNode* head)
{
	return (head)?1+count(head->next):0;
}

/* ListNode** 是为了建立一个存储ListNode* 的数组，
   传入数组指针，n是数组元素个数，这是最常见的输出传入方式 */
TreeNode* build(ListNode** head,int n)
{
	if(n<=0)
		return nullptr;
	TreeNode* left=build(head,n/2);
	TreeNode* root=new TreeNode((*head)->val);
	root->left = left;
	*head=(*head)->next;
	root->right=build(head,n-n/2-1);
	return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
	int n=count(head);
	return build(&head,n);
}

