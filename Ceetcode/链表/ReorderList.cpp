/* 经典的题目，栈的使用
题目：给定一个链表 l0->l1->l2->...->ln，将其重新调整为 l0->ln->l2->l(n-1)->...
本题看起来复杂，其实将问题很简单
	1.使用快慢指针来找到链表的中点，并将链表从中间断开；
	2.将第二个链表翻转；
	3.将第二个链表的元素间隔地插入第一个链表中。
这里的第二个步骤，可以使用栈完成，先进后出，完成翻转，然后可以直接使用 栈的大小标定中点。
第三个步骤不变，就是普通的插入节点。 */

void reorderList(ListNode* head) {
    if(!head || !head->next) return;
    stack<ListNode*> s;
    ListNode* cur = head;
    while(cur){
        s.push(cur);
        cur = cur->next;
    }
    cur=head;
    int len = ((int)s.size()-1)/2;
    for(;len>0;len--){
        s.top()->next = cur->next;
        cur->next = s.top();
        cur=s.top()->next;
        s.pop();
    }
    s.top()->next=nullptr;
}
