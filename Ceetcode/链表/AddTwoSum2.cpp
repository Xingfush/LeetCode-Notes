/* 本题的数字要求倒过来加，最好的方法是使用栈，这点一定要明确，具体的操作和1类似，有个小技巧：
    tail->val = sum%10; // 
    ListNode* head = new ListNode(sum/10); 
    head->next = tail; // 逆序建立链表，这个思路清奇 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1,s2;
    while(l1){
        s1.push(l1->val);
        l1=l1->next;
    }
    while(l2){
        s2.push(l2->val);
        l2=l2->next;
    }
    int sum=0;
    ListNode* tail = new ListNode(0);
    while(!s1.empty()||!s2.empty()){
        sum /= 10;
        if(!s1.empty()){
            sum += s1.top();
            s1.pop();
        }
        if(!s2.empty()){
            sum += s2.top();
            s2.pop();
        }
        tail->val = sum%10;
        ListNode* head = new ListNode(sum/10);
        head->next = tail;
        tail = head;
    }
    return tail->val?tail:tail->next; // 这个一定要加上，因为新建 head 结点时没有检验 sum/10 是否为0.
    
}