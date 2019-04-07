/* 代码正确性（不存在内存泄漏和野指针），规范性（命名合理），简介性 */

ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* cur = head->next, * pre=head;
    while(cur!=nullptr){
        if(cur->val==pre->val){
            ListNode* temp = cur;
            pre->next = cur->next;
            cur = cur->next;
            delete temp;
        }
        else{
            pre=cur;
            cur=cur->next;
        }
    }
    return head;
}
