/* 删除一个结点很容易，主要是考虑如果头结点被删除怎么处理
   这里使用伪头结点法，在头节点前面设一个头结点 */

ListNode* removeElements(ListNode* head, int val)
{
	if(!head)
		return nullptr;
	
	ListNode* front = new ListNode(0);
	front->next = head;
	ListNode* pre=front, *cur=head;

	while(cur)
	{
		if(cur->val==val)
		{
			ListNode* temp = cur;
			pre->next = cur->next;
			cur=cur->next;
			delete temp;
			temp = nullptr
		}
		else
		{
			pre=cur;
			cur=cur->next;
		}
	}
	return front->next;
}

/* 代码要点：思路清晰（pre,cur的移动）；规范（内存泄漏和野指针） */