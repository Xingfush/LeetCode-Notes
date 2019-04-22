/* 解法1：使用循环链表，n个人(0-n-1)，报道 m-1 退场，重新开始报数*/
int JosephusCircle(int n, int m){
	if(n<1 || m<1) return -1;
	ListNode* head = new ListNode(0); // 第一个人的编号，结点
	ListNode* cur = head;
	ListNode* pLast = nullptr;
	int i;
	for(int i=1;i<n;i++){
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	cur->next = head;
	pLast = cur;
	cur = head;
	while(cur->next!=cur){
		for(int i=0;i<m-1;i++){ // 开始报数，报道第 m 个人停止
			pLast = cur; // pLast 保存 cur上一个结点
			cur = cur->next; // 此时 cur就是即将出场的结点
		}
		pLast->next = cur->next; // 删除结点的步骤三连
		delete cur;
		cur = pLast->next;
	}
	int result = cur->val;
	delete cur;
	return result;
}