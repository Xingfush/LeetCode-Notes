/*----------------------------------------------------------*/
/* 使用快慢指针寻找中点，采用层次遍历 */
TreeNode* build(ListNode* head, ListNode* tail)
{
	if(head==tail)
		return nullptr;

	ListNode* slow=head,*fast=head;

	while((fast!=tail)&&(fast->next!=tail)) // 这里一定先判空fast，再判空fast->next
	{
		slow = slow->next; //每次走一步
		fast = fast->next->next; // 每次走两步
	}

	TreeNode* root= new ListNode(slow->val); // 所以是左闭右开
	root->left= build(head,slow);
	root->right= build(slow->next,tail);

	return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
	return build(head,nullptr);
}