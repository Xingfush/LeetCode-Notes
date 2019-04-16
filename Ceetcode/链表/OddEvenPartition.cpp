/* 按照结点的序号，将奇数序号结点放到左边，偶数序号结点放到右边
	方法依然是建立两个链表，然后将其拼合，不同之处为
	1.直接用第一个、第二个结点初始化两个链表；
	2.终止条件的选定：只有偶数结点后面还有奇数结点，这是唯一的终止条件 even && even->next */

ListNode* oddEvenList(ListNode* head) {
    if(head==nullptr) return nullptr; 
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* even_head = even;
    while(even && even->next){ // 只要 even 后面还有 odd 那就得调整,终止条件
        odd->next= even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next=even_head;
    return head;
}