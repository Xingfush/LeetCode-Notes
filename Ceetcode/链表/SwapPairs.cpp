/* 普通的链表操作题，结点交换，考察队指针的操作能力
题目：将链表 1->2->3->4，两两交换相邻结点，得到 2->1->4->3 */

ListNode* swapPairs(ListNode* head) {
    ListNode* sential = new ListNode(-1); // 使用 伪头结点处理头结点会发生改变的问题
    sential->next = head;
    ListNode* pre = sential;
    while(head && head->next){ // 只有出现偶数个结点才进行操作， head && head->next;
        pre->next = head->next;
        head->next = head->next->next; // 指针操作在草稿纸上模拟，不易出错
        pre->next->next = head;
        pre = head;
        head = head->next;
    }
    head = sential->next;
    delete sential;
    return head;
}

