/* 链表的排序：堆排序，快速排序，归并排序，最适合链表的O(nlgn)排序算法中，非归并排序莫属
	这道题以小见大，考察基本功，对问题的理解能力；
	主要是 pre 的作用，归并排序把数组划分为子数组，将链表划分为子链表，通过 pre = nullptr 实现，
	1.快慢指针寻找中点；
	2.使用pre进行记录 slow 也就是分割点前一个结点，进行链表切分；
	3.两个有序链表的合并，必背。 */

ListNode* sortList(ListNode* head){
	if(!head || !head->next) return head;
	ListNode* slow = head, *fast = head, *pre = head;
	while(fast && fast->next){
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = nullptr;
	return merge(sortList(head), sortList(slow));
}

ListNode* merge(ListNode* l1, ListNode* l2){
	if(l1==nullptr)
		return l2;
	if(l2==nullptr)
		return l1;
	ListNode* result==nullptr;
	if(l1->val<l2->val){
		result = l1;
		result->next = merge(l1->next,l2);
	}
	else{
		result = l2;
		result->next = merge(l1,l2->next);
	}
	return result;
}