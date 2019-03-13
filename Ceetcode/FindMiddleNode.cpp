ListNode* middleNode(ListNode* head) {
    ListNode *pAhead =head, *pBehind=head;
    while(pAhead!=nullptr && pAhead->next!=nullptr)
    {
        pAhead=pAhead->next->next;
        pBehind=pBehind->next;
    }
    return pBehind;
}