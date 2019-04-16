/* 分隔链表：左边全都小于 x,右边大于等于 x */

ListNode* partition(ListNode* head, int x) {
    ListNode* left = new ListNode(0);
    ListNode* right = new ListNode(0);
    ListNode* l = left, *r = right;
    while(head){
        if(head->val<x){
            l->next = head;
            l=l->next;
        }
        else{
            r->next=head;
            r = r->next;
        }
        head=head->next;
    }
    l->next = right->next;
    r->next = nullptr;
    head = left->next;
    delete left; // 有 new 就有 delete
    delete right;
    return head;
}