unsigned int count(ListNode *head){
    return (head)?count(head->next)+1:0;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==nullptr || headB==nullptr)
        return nullptr;
    
    unsigned int lenA=count(headA);
    unsigned int lenB=count(headB);
    unsigned int lenDiff;
    
    if(lenA>lenB)
    {
        lenDiff=lenA-lenB;
        for(unsigned i=0;i<lenDiff;i++)
            headA=headA->next;
    }
    else
    {
        lenDiff=lenB-lenA;
        for(unsigned i=0;i<lenDiff;i++)
            headB=headB->next;
    }
    
    while((headA!=nullptr)&&(headB!=nullptr))
    {
        if(headA==headB)
            return headA;
        headA=headA->next;
        headB=headB->next;
    }
    return nullptr;
}