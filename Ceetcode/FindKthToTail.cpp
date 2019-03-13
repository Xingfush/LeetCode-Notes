LinkNode* FindKthToTail(LinkNode* head, unsigned int k)
{
	if(head==nullptr||k==0)
		return nullptr;

	LinkNode *pAhead=head,*pBehind=nullptr;

	for(unsigned int i=0;i<k-1;i++) // 是k-1而不是k
	{
		if(pAhead->next!=nullptr) // 没有终止判别条件的向前移动是很危险的
			pAhead=pAhead->next;
		else
			return nullptr;
	}
	
	pBehind=head;
	while(pAhead->next!=nullptr)
	{
		pAhead=pAhead->next;
		pBehind=pBehind->next;
	}
	return pBehind;
	}
}
/* 一定要注意pAhead指针的移动，不要越界 */