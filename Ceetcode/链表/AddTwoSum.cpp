/* 本题的思路很简单，但是想保证代码的简介、正确还是挺难得，基本功必须扎实；
    1.使用 sential，伪头结点，这样保证计算的一致性，非常好的技巧；
    2.ListNode* d = sential ，移动节点和头结点分别设置，好的习惯；
    3.直接使用 d->next = new ListNode(sum%10) 简介优雅；
    4.终止条件的处理，不要忘了最后一个 sum 的处理。 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* sential = new ListNode(0);
    ListNode* d = sential;
    int sum = 0;
    while(l1 || l2){
        sum /= 10;
        if(l1){
            sum += l1->val;
            l1=l1->next；
        }
        if(l2){
            sum += l2->val;
            l2=l2->next;
        }
        d->next = new ListNode(sum%10);
        d = d->next;
    }
    if(sum/10){
        d->next = new ListNode(sum/10);
        d = d->next;
    }
    return sential->next;
}