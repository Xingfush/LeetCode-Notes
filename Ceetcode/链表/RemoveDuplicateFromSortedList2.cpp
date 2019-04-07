/* 代码虽然看起来复杂了点，但是思路清晰，不存在内存泄漏和其它问题。 */

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* front = new ListNode(0);
    front->next = head;
    ListNode* cur = head, * pre = front;
    while(cur!=nullptr){
        int key = cur->val;
        bool isDuplicate = false; // 标记重复结点，事后删除
        while(cur->next!=nullptr && cur->next->val==key){
            ListNode* temp = cur->next;
            cur->next=cur->next->next;
            delete temp;
            isDuplicate = true;
        }
        if(isDuplicate){
            ListNode* temp = cur;
            pre->next = cur->next;
            delete temp;
        }
        else pre = cur;
        cur=cur->next;
    }
    cur = front->next; // front 是伪头结点，用完一定在函数内进行内存释放和删除，一定！
    delete front;
    return cur;
}

