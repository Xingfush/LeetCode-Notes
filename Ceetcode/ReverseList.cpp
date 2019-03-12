ListNode* ReverseList(ListNode* head)
{
	ListNode* cur=head,pre=nullptr,post=nullptr;
	while(cur!=nullptr)
	{
		// 首先判断是否是最后一个结点
		post=cur->next;
		cur->next=pre;
		pre=cur;
		cur=post;
	}
	return pre;
}