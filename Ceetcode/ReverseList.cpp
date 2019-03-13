ListNode* ReverseList(ListNode* head)
{
	ListNode* cur=head,pre=nullptr,post=nullptr;
	while(cur!=nullptr)
	{
		// 首先判断是否是最后一个结点
		post=cur->next; // 记录
		cur->next=pre; // 调整连接
		pre=cur; // 更新
		cur=post;
	}
	return pre;
}