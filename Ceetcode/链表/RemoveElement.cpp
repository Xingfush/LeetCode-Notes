/* 删除一个结点很容易，主要是考虑如果头结点被删除怎么处理
   这里使用伪头结点法，在头节点前面设一个头结点 */

ListNode* removeListNode(ListNode* head, int key){
	if(!head) return nullptr;
	ListNode* temp = nullptr;

	while(head && head->val==key){
		temp = head;
		head = head->next;
		delete temp;
	}

	ListNode *cur = head, *pre = nullptr;
	while(cur){
		if(cur->val==key){
			temp = cur;
			pre->next = cur->next;
			cur = cur->next;
			delete temp;
		} else {
			pre = cur;
			cur = cur->next;
		}
	}

	return head;
}


/* 代码要点：思路清晰（pre,cur的移动）；规范（内存泄漏和野指针） */